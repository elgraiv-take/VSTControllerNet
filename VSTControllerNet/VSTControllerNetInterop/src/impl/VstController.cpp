
#include "VstController.Bridge.hpp"
#include <pluginterfaces/vst/ivsteditcontroller.h>

namespace Elgraiv::VstControllerNet::Interop {

	VstController::Bridge::Bridge(Steinberg::Vst::IEditController* native)
		:_native(gcnew ManagedModuleHandle<Steinberg::Vst::IEditController>(native))
	{
	}

	////////////////////////////


	VstController::VstController(Bridge^ bridge):_bridge(bridge)
	{
	}

	VstClassInfo^ VstController::ClassInfo::get() {
		return nullptr;
	}

}