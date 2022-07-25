using Elgraiv.VstControllerNet.Util;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Elgraiv.VstControllerNet
{
    public class VstAssembly: DisposableBase
    {
        private delegate IntPtr GetPluginFactoryNative();
        private static class NativeMethods
        {
            [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
            public static extern IntPtr LoadLibrary([MarshalAs(UnmanagedType.LPWStr)] string lpLibFileName);

            [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Ansi)]
            public static extern IntPtr GetProcAddress(IntPtr hModule, [MarshalAs(UnmanagedType.LPStr)] string lpProcName);

            [DllImport("kernel32.dll", SetLastError = true)]
            public static extern bool FreeLibrary(IntPtr hLibModule);

        }

        private Interop.VstPluginFactory? _pluginFactory;
        private Interop.VstClassInfo[]? _classInfos;

        private IntPtr _handle;
        public string Path { get; }
        public bool IsValid { get; private set; } = false;

        internal VstAssembly(string path)
        {
            Path = path;
        }
        internal bool Load()
        {
            _handle = NativeMethods.LoadLibrary(Path);
            if(_handle == IntPtr.Zero)
            {
                return false;
            }
            var getterHandle = NativeMethods.GetProcAddress(_handle, "GetPluginFactory");
            var getPluginFactory = Marshal.GetDelegateForFunctionPointer<GetPluginFactoryNative>(getterHandle);
            if (getPluginFactory == null)
            {
                return false;
            }
            _pluginFactory = new Interop.VstPluginFactory(getterHandle);
            _classInfos = _pluginFactory.ClassInfos.ToArray();
            IsValid = true;
            return true;
        }

        protected override void DisposeUnmanaged()
        {
            base.DisposeUnmanaged();
            if( _handle != IntPtr.Zero)
            {
                NativeMethods.FreeLibrary(_handle);
                _handle= IntPtr.Zero;
            }
        }
    }
}
