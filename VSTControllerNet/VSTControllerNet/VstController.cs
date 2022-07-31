using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Interop;

namespace Elgraiv.VstControllerNet
{
    public class VstController : IVstModule
    {
        private Interop.VstController _interop;
        internal VstController(Interop.VstController interop)
        {
            _interop = interop;
        }

        public void Connect(VstAudioProcessor processor)
        {
            Interop.VstConnectionPoint.Connect(_interop.ConnectionPoint, processor.ConnectionPoint);
        }


        public void Show(Window parent)
        {
            var helper = new WindowInteropHelper(parent);
            var view = _interop.CreateView();
            view.Show(helper.Handle);
        }
    }
}
