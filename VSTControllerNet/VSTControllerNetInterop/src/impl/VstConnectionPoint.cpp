#include "VstConnectionPoint.Bridge.hpp"
#include <pluginterfaces/vst/ivstmessage.h>
#include "DevRelayConnector.hpp"

namespace Elgraiv::VstControllerNet::Interop {
	namespace Dev {
		ref class InstanceHolder {
		public:
			static RelayConnector^ g_connector;
		};
	}

	void VstConnectionPoint::Bridge::Connect(VstConnectionPoint::Bridge^ a, VstConnectionPoint::Bridge^ b)
	{

		auto relay = gcnew Dev::RelayConnector();

		relay->ConnectionA->connect(&**a->_native);
		relay->ConnectionB->connect(&**b->_native);
		a->_native->connect(&**relay->ConnectionA);
		b->_native->connect(&**relay->ConnectionB);



		Dev::InstanceHolder::g_connector = relay;
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