#pragma once


namespace Elgraiv::VstControllerNet::Interop {
	ref class VstClassInfo;

	public interface class IVstModule {
	public:
		property VstClassInfo^ ClassInfo {
			VstClassInfo^ get();
		}
	};
	/*
	public ref class VstAudioModule : public IVstModule {
	public:
		virtual property VstClassInfo^ ClassInfo {
			VstClassInfo^ get();
		}
	internal:
		ref class Bridge;
	private:
		Bridge^ _bridge;
	};
	*/
	public ref class VstController : public IVstModule {
	public:
		virtual property VstClassInfo^ ClassInfo {
			VstClassInfo^ get();
		}
	internal:
		ref class Bridge;
		VstController(Bridge^ bridge);
	private:
		Bridge^ _bridge;
	};
}