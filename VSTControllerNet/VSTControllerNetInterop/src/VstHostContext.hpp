#pragma once


namespace Elgraiv::VstControllerNet::Interop {

	public ref class VstHostContext {
	public:
		ref class Description {
		public:
			property System::String^ Name;
		};
		VstHostContext(Description^ desc);
	internal:
		ref class Bridge;
		property Bridge^ NativeBridge {
			Bridge^ get() {
				return _bridge;
			}
		}
		
	private:
		Bridge^ _bridge;
	};
}