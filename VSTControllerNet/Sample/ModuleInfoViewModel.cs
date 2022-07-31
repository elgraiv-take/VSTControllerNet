using CommunityToolkit.Mvvm.Input;
using Elgraiv.VstControllerNet;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;

namespace Sample
{
    internal class ModuleInfoViewModel
    {
        private ModuleInfoModel _model;

        public string Name => _model.Name;
        public string Category => _model.Category;

        public ICommand CreateInstanceCommand { get; }

        public ModuleInfoViewModel(ModuleInfoModel moduleInfo)
        {
            _model = moduleInfo;
            CreateInstanceCommand = new RelayCommand(CreateInstance);
        }

        private void CreateInstance()
        {
            _model.CreateInstance();
        }
    }
}
