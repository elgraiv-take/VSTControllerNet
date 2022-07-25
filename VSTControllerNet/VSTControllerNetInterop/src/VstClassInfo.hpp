#pragma once


namespace Elgraiv::VstControllerNet::Interop {

	public enum class ClassType
	{
		Unknown,
		AudioModule,
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
		void CreateInstance();
	private:
		Bridge^ _bridge;
	};
}