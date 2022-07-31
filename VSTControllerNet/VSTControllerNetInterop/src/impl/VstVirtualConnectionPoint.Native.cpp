
#include "VstVirtualConnectionPoint.Native.hpp"
namespace Elgraiv::VstControllerNet::Native {
	Steinberg::tresult PLUGIN_API VstVirtualConnectionPoint::connect(Steinberg::Vst::IConnectionPoint* other) {
		return Steinberg::kResultTrue;
	}
	Steinberg::tresult PLUGIN_API VstVirtualConnectionPoint::disconnect(Steinberg::Vst::IConnectionPoint* other) {
		return Steinberg::kResultTrue;
	}
	Steinberg::tresult PLUGIN_API VstVirtualConnectionPoint::notify(Steinberg::Vst::IMessage* message) {
		
		return Steinberg::kResultTrue;

	}

}