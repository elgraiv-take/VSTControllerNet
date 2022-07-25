#pragma once
#include "../VstModule.hpp"
#include "Utils.hpp"

namespace Steinberg {
	namespace Vst {
		class IEditController;
	}
}

namespace Elgraiv::VstControllerNet::Interop {

	ref class VstController::Bridge {
	public:
		Bridge(Steinberg::Vst::IEditController* native);
	private:
		ManagedModuleHandle<Steinberg::Vst::IEditController>^ _native;
	};

}