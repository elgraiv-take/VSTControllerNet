using CommunityToolkit.Mvvm.ComponentModel;
using Elgraiv.VstControllerNet;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace Sample
{
    internal class MainModel : ObservableObject
    {
        private string _vstPath = string.Empty;
        public string VstPath
        {
            get => _vstPath;
            set => SetProperty(ref _vstPath, value);
        }

        private VstHost _vstHost;

        private VstAssembly? _loadedVst;
        public VstAssembly? LoadedVst
        {
            get => _loadedVst;
            private set
            {
                if(SetProperty(ref _loadedVst, value))
                {
                    OnPropertyChanged(nameof(IsValid));
                }
            }
        }

        private List<ModuleInfoModel> _modules = new List<ModuleInfoModel>();
        public IEnumerable<ModuleInfoModel> Modules => _modules;

        public bool IsValid
        {
            get => _loadedVst?.IsValid ?? false;
        }

        public MainModel()
        {
            _vstHost = new VstHost("SampleHost");
        }

        public void LoadVst()
        {
            if (_loadedVst != null)
            {
                return;
            }
            var vst = _vstHost.LoadVst(VstPath);
            _modules.AddRange(vst.Modules.Select(info => new ModuleInfoModel(info, this)));
            LoadedVst = vst;
        }

        public void UnloadVst()
        {
            _modules.Clear();
            _loadedVst?.Dispose();
            LoadedVst = null;
        }

        public void Construct(Window window)
        {
            if (LoadedVst != null)
            {
                var modules = LoadedVst.Modules.Select(info => info.CreateInstance()).ToArray();
                var audioPorocessor = modules.OfType<VstAudioProcessor>().First();
                var controller = modules.OfType<VstController>().First();
                controller.Connect(audioPorocessor);
                audioPorocessor.Activate();
                controller.Show(window);
            }
        }

    }
}
