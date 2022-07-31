using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Elgraiv.VstControllerNet
{
    public class VstModuleInfo
    {
        private Interop.VstClassInfo _interop;

        public string Name => _interop.Name;
        public string Category => _interop.Type.ToString();
        private VstHost _host;

        internal VstModuleInfo(Interop.VstClassInfo interop,VstHost host)
        {
            _interop = interop;
            _host = host;
        }

        public IVstModule CreateInstance()
        {
            var interop = _interop.CreateInstance(_host.Context);
            switch (interop)
            {
                case Interop.VstAudioProcessor processor:
                    return new VstAudioProcessor(processor);
                case Interop.VstController controller:
                    return new VstController(controller);
            }
            return new UnknownModule();
        }
    }
}
