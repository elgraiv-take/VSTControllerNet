using CommunityToolkit.Mvvm.ComponentModel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace Sample
{
    internal class MainWindowViewModel : ObservableObject
    {
        private MainModel _model;
        public bool IsLoaded
        {
            get => _model.LoadedVst != null;
        }
        public bool IsValid
        {
            get => _model.IsValid;
        }
        public string LoadButtonLabel
        {
            get => IsLoaded ? "Unload" : "Load";
        }

        public string StatusLabel
        {
            get => IsLoaded ? (IsValid ? "Valid" : "Invalid") : "NotLoaded";
        }

        public string Path
        {
            get => _model.VstPath;
            set => _model.VstPath = value;
        }
        public ICommand LoadCommand { get; }

        public MainWindowViewModel(MainModel model)
        {
            _model = model;
            _model.PropertyChanged += OnModelPropertyChanged;
            LoadCommand = new CommunityToolkit.Mvvm.Input.RelayCommand(Load);
        }

        private void Load()
        {
            if (IsLoaded)
            {
                _model.UnloadVst();
            }
            else
            {
                _model.LoadVst();
            }
        }

        private void OnModelPropertyChanged(object? sender, System.ComponentModel.PropertyChangedEventArgs e)
        {
            OnPropertyChanged("");//雑
        }

        public MainWindowViewModel() : this(new MainModel())
        {
        }

    }
}
