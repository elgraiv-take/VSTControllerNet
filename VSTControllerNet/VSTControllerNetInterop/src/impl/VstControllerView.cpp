#include "VstControllerView.Bridge.hpp"
#include <pluginterfaces/gui/iplugview.h>

namespace Elgraiv::VstControllerNet::Interop {

	VstControllerView::Bridge::Bridge(Steinberg::IPlugView* native)
		:_native(gcnew ManagedModuleHandle<Steinberg::IPlugView>(native))
	{

	}

	void VstControllerView::Bridge::Show(System::IntPtr hwnd)
	{
		_native->attached(hwnd.ToPointer(), Steinberg::kPlatformTypeHWND);
	}

	void VstControllerView::Bridge::Close()
	{
		_native->removed();
	}


	////////////////////////////////////////////

	VstControllerView::VstControllerView(Bridge^ bridge)
		: _bridge(bridge)
	{
	}
	
	void VstControllerView::Show(System::IntPtr windowHandle)
	{
		_bridge->Show(windowHandle);
	}

}