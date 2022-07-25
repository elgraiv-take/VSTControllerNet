using Elgraiv.VstControllerNet.Util;
using System;

namespace Elgraiv.VstControllerNet
{
    public class VstLoader : DisposableBase
    {
        public VstAssembly LoadVst(string path)
        {
            var assembly = new VstAssembly(path);
            assembly.Load();
            return assembly;
        }
    }
}
