#pragma once
#include "../VstModule.hpp"
#include "Utils.hpp"

namespace Steinberg {
	namespace Vst {
		class IComponent;
		class IAudioProcessor;
		class IConnectionPoint;
	}
}

namespace Elgraiv::VstControllerNet::Interop {

	ref class VstAudioProcessor::Bridge {
	public:
		Bridge(Steinberg::Vst::IComponent* native, VstClassInfo^ classInfo);

		property VstClassInfo^ ClassInfo {
			VstClassInfo^ get() {
				return _classInfo;
			}
		}
		property VstConnectionPoint^ ConnectionPoint {
			VstConnectionPoint^ get() {
				return _connectionPoint;
			}
		}
		void Activete();
		void Deactivate();

	private:
		ManagedModuleHandle<Steinberg::Vst::IComponent>^ _native;
		ManagedModuleHandle<Steinberg::Vst::IAudioProcessor>^ _processor;
		VstConnectionPoint^ _connectionPoint;
		VstClassInfo^ _classInfo;
	};
}