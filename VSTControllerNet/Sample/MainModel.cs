using CommunityToolkit.Mvvm.ComponentModel;
using Elgraiv.VstControllerNet;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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

        private VstLoader _vstLoader;

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

        public bool IsValid
        {
            get => _loadedVst?.IsValid ?? false;
        }

        public MainModel()
        {
            _vstLoader = new VstLoader();
        }

        public void LoadVst()
        {
            if (_loadedVst != null)
            {
                return;
            }
            var vst = _vstLoader.LoadVst(VstPath);
            LoadedVst = vst;
        }

        public void UnloadVst()
        {
            _loadedVst?.Dispose();
            LoadedVst = null;
        }


    }
}
