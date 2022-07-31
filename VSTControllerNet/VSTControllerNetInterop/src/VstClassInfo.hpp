#pragma once


namespace Elgraiv::VstControllerNet::Interop {

	public enum class ClassType
	{
		Unknown,
		AudioProcessor,
		Controller,
	};

	public ref class VstClassInfo {
	internal:
		ref class Bridge;
		VstClassInfo(Bridge^ info);
	public:
		property System::String^ Name {
			System::String^ get();
		}
		property ClassType Type {
			ClassType get();
		}
		interface class IVstModule^ CreateInstance(ref class VstHostContext^ context);
	private:
		Bridge^ _bridge;
	};
}