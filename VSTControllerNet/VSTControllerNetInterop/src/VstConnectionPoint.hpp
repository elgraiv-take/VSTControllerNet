#pragma once


namespace Elgraiv::VstControllerNet::Interop {

	public ref class VstConnectionPoint {
	public:
		static void Connect(VstConnectionPoint^ a, VstConnectionPoint^ b);
	internal:
		ref class Bridge;
		VstConnectionPoint(Bridge^ bridge);
	private:
		Bridge^ _bridge;
	};
}