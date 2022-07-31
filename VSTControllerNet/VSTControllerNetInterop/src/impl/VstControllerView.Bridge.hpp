#pragma once

#include "../VstControllerView.h"
#include "Utils.hpp"

namespace Steinberg {
	class IPlugView;
}
namespace Elgraiv::VstControllerNet::Interop {
	ref class VstControllerView::Bridge {
	internal:
		Bridge(Steinberg::IPlugView* native);
		void Show(System::IntPtr hwnd);
		void Close();
	private:
		ManagedModuleHandle<Steinberg::IPlugView>^ _native;
	};
}