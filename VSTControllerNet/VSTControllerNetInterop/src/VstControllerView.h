#pragma once

namespace Elgraiv::VstControllerNet::Interop {
	
	public ref class VstControllerView {
	public:
		void Show(System::IntPtr windowHandle);
	internal:
		ref class Bridge;
		VstControllerView(Bridge^ bridge);
	private:
		Bridge^ _bridge;
	};
}