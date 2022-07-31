#pragma once


namespace Elgraiv::VstControllerNet::Interop {
	ref class VstClassInfo;
	ref class VstConnectionPoint;

	public interface class IVstModule {
	public:
		property VstClassInfo^ ClassInfo {
			VstClassInfo^ get();
		}
		property VstConnectionPoint^ ConnectionPoint {
			VstConnectionPoint^ get();
		}
	};

	public ref class VstAudioProcessor : public IVstModule {
	public:
		virtual property VstClassInfo^ ClassInfo {
			VstClassInfo^ get();
		}
		virtual property VstConnectionPoint^ ConnectionPoint {
			VstConnectionPoint^ get();
		}
		void Activete();
		void Deactivate();
	internal:
		ref class Bridge;
		VstAudioProcessor(Bridge^ bridge);
	private:
		Bridge^ _bridge;
	};
	public ref class VstController : public IVstModule {
	public:
		virtual property VstClassInfo^ ClassInfo {
			VstClassInfo^ get();
		}
		virtual property VstConnectionPoint^ ConnectionPoint {
			VstConnectionPoint^ get();
		}
		ref class VstControllerView^ CreateView();
	internal:
		ref class Bridge;
		VstController(Bridge^ bridge);
	private:
		Bridge^ _bridge;
	};
}