#pragma once

#include "../VstHostContext.hpp"
#include "Utils.hpp"

namespace Elgraiv::VstControllerNet::Native {
	class HostContext;
}
namespace Steinberg {
	class FUnknown;
	namespace Vst {
		class IHostApplication;
		class IComponentHandler;
	}
}
namespace Elgraiv::VstControllerNet::Interop {

	ref class VstHostContext::Bridge {
	internal:
		Bridge(System::String^ name);

		property ManagedModuleHandle<Steinberg::Vst::IHostApplication>^ Host {
			ManagedModuleHandle<Steinberg::Vst::IHostApplication>^ get() {
				return _host;
			}
		}
		property ManagedModuleHandle<Steinberg::Vst::IComponentHandler>^ ComponentHandler{
			ManagedModuleHandle<Steinberg::Vst::IComponentHandler>^ get() {
				return _componentHandler;
			}
		}

	private:
		ManagedModuleHandle<Native::HostContext>^ _native;
		ManagedModuleHandle<Steinberg::Vst::IHostApplication>^ _host;
		ManagedModuleHandle<Steinberg::Vst::IComponentHandler>^ _componentHandler;
	};
}