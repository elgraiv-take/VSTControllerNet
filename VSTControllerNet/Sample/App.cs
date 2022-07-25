using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace Sample
{
    public class App : System.Windows.Application
    {
        [System.STAThreadAttribute()]
        public static void Main()
        {
            Sample.App app = new Sample.App();
            app.Run();
        }

        protected override void OnStartup(StartupEventArgs e)
        {
            base.OnStartup(e);
            ShutdownMode = ShutdownMode.OnMainWindowClose;
            var model = new MainModel();
            var viewModel = new MainWindowViewModel(model);
            var mainWindow = new MainWindow()
            {
                DataContext = viewModel,
            };
            MainWindow = mainWindow;
            mainWindow.Show();
        }
    }
}
