using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Elgraiv.VstControllerNet
{
    public class VstHost
    {
        internal Interop.VstHostContext Context { get; }

        public VstHost(string name)
        {
            var contextDesc = new Interop.VstHostContext.Description()
            {
                Name = name
            };
            Context = new Interop.VstHostContext(contextDesc);
        }
        public VstAssembly LoadVst(string path)
        {
            var assembly = new VstAssembly(path, this);
            assembly.Load();
            return assembly;
        }
    }
}
