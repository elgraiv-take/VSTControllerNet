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
    internal class ModuleInfoModel
    {
        private VstModuleInfo _info;
        private MainModel _main;
        public string Name => _info.Name;
        public string Category => _info.Category;
        private ObservableCollection<IVstModule> _instances = new ObservableCollection<IVstModule>();

        public ModuleInfoModel(VstModuleInfo info, MainModel main)
        {
            _info = info;
            _main = main;
        }

        public void CreateInstance()
        {
            var instance = _info.CreateInstance();
            _instances.Add(instance);
        }
        public void ShowWindow(Window parent)
        {
            var controller = _instances.OfType<VstController>().FirstOrDefault();
            controller?.Show(parent);
        }
    }
}
