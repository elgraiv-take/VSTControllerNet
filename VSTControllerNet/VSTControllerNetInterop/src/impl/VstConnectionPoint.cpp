#include "VstConnectionPoint.Bridge.hpp"
#include <pluginterfaces/vst/ivstmessage.h>

namespace Elgraiv::VstControllerNet::Interop {

	void VstConnectionPoint::Bridge::Connect(VstConnectionPoint::Bridge^ a, VstConnectionPoint::Bridge^ b)
	{
		a->_native->connect(&**b->_native);
		b->_native->connect(&**a->_native);
	}
	
	VstConnectionPoint::Bridge::Bridge(ManagedModuleHandle<Steinberg::Vst::IConnectionPoint>^ handle) :_native(handle)
	{
	}

	//////////////////////

	void VstConnectionPoint::Connect(VstConnectionPoint^ a, VstConnectionPoint^ b)
	{
		Bridge::Connect(a->_bridge, b->_bridge);
	}

	VstConnectionPoint::VstConnectionPoint(Bridge^ bridge) :_bridge(bridge) {

	}
}