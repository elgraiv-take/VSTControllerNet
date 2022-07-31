using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Elgraiv.VstControllerNet
{
    public class VstAudioProcessor : IVstModule
    {
        private Interop.VstAudioProcessor _interop;
        internal VstAudioProcessor(Interop.VstAudioProcessor interop)
        {
            _interop = interop;
        }

        internal Interop.VstConnectionPoint ConnectionPoint => _interop.ConnectionPoint;

        public void Activate()
        {
            _interop.Activete();
        }
    }
}
