
#include "VstVirtualConnectionPoint.Native.hpp"
namespace Elgraiv::VstControllerNet::Native {

	VstVirtualConnectionPoint::VstVirtualConnectionPoint(VirtualConnectionCallback callback) :_callback(callback)
	{
	}
	
	Steinberg::tresult PLUGIN_API VstVirtualConnectionPoint::connect(Steinberg::Vst::IConnectionPoint* other) {
		other->addRef();
		_connections.insert(other);
		return Steinberg::kResultTrue;
	}
	Steinberg::tresult PLUGIN_API VstVirtualConnectionPoint::disconnect(Steinberg::Vst::IConnectionPoint* other) {
		_connections.erase(other);
		other->release();
		return Steinberg::kResultTrue;
	}
	Steinberg::tresult PLUGIN_API VstVirtualConnectionPoint::notify(Steinberg::Vst::IMessage* message) {
		if (_callback) {
			_callback(message);
		}
		return Steinberg::kResultTrue;
	}

	void VstVirtualConnectionPoint::Broadcast(Steinberg::Vst::IMessage* message)
	{
		for (auto& connection : _connections) {
			connection->notify(message);
		}
	}

}