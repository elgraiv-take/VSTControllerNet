#include "VstHostContext.Bridge.hpp"
#include "VstHostContext.Native.hpp"
#include <pluginterfaces/vst/ivsteditcontroller.h>
#include <string>

namespace Elgraiv::VstControllerNet::Interop {
	VstHostContext::Bridge::Bridge(System::String^ name)
	{
		using namespace System::Runtime::InteropServices;
		const char* chars =	(const char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer();
		auto nameString = std::string(chars);
		Marshal::FreeHGlobal(System::IntPtr((void*)chars));

		Native::HostContext::Desc nativeDesc;

		_native = gcnew ManagedModuleHandle<Native::HostContext>(new Native::HostContext(nameString, nativeDesc));
		_host = (*_native).QueryInterface<Steinberg::Vst::IHostApplication>();
		_componentHandler = (*_native).QueryInterface<Steinberg::Vst::IComponentHandler>();
	}


	/////////////////////////////////////////

	VstHostContext::VstHostContext(Description^ desc)
		:_bridge(gcnew Bridge(desc->Name))
	{
	}
}