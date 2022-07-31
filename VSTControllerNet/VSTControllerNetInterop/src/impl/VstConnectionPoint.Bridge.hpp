#pragma once
#include "../VstConnectionPoint.hpp"
#include "Utils.hpp"
namespace Steinberg {
	namespace Vst {
		class IConnectionPoint;
	}
}

namespace Elgraiv::VstControllerNet::Interop {

	ref class VstConnectionPoint::Bridge {
	public:
		static void Connect(VstConnectionPoint::Bridge^ a, VstConnectionPoint::Bridge^ b);

		Bridge(ManagedModuleHandle<Steinberg::Vst::IConnectionPoint>^ handle);
	private:
		ManagedModuleHandle<Steinberg::Vst::IConnectionPoint>^ _native;
	};
}