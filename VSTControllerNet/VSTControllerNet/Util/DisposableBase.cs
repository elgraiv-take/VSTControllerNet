using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Elgraiv.VstControllerNet.Util
{
    public abstract class DisposableBase: IDisposable
    {
        protected virtual void DisposeManaged() { }
        protected virtual void DisposeUnmanaged() { }

        #region IDisposable
        private bool _disposedValue;

        protected virtual void Dispose(bool disposing)
        {
            if (!_disposedValue)
            {
                if (disposing)
                {
                    DisposeManaged();
                }
                DisposeUnmanaged();
                _disposedValue = true;
            }
        }

        ~DisposableBase()
        {
            Dispose(disposing: false);
        }

        public void Dispose()
        {
            Dispose(disposing: true);
            GC.SuppressFinalize(this);
        }
        #endregion
    }
}
