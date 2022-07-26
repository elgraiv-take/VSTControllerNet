#pragma once
#include "../VstModule.hpp"
#include "Utils.hpp"

namespace Steinberg {
	namespace Vst {
		class IEditController;
		class IConnectionPoint;
	}
}

namespace Elgraiv::VstControllerNet::Interop {

	ref class VstController::Bridge {
	public:
		Bridge(Steinberg::Vst::IEditController* native, VstClassInfo^ classInfo);
		ref class VstControllerView^ CreateView();
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

	private:
		ManagedModuleHandle<Steinberg::Vst::IEditController>^ _native;
		VstConnectionPoint^ _connectionPoint;
		VstClassInfo^ _classInfo;
	};

}