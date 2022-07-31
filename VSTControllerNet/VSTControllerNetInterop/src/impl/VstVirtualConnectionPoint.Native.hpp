#pragma once

#include <base/source/fobject.h>
#include <pluginterfaces/vst/ivstmessage.h>
#include <unordered_set>
#include <functional>
namespace Elgraiv::VstControllerNet::Native {
	using VirtualConnectionCallback = std::function<void(Steinberg::Vst::IMessage*)>;
	class VstVirtualConnectionPoint
		: public Steinberg::FObject
		, public Steinberg::Vst::IConnectionPoint
	{
	public:
		VstVirtualConnectionPoint(VirtualConnectionCallback callback);

		OBJ_METHODS(VstVirtualConnectionPoint, FObject)
		REFCOUNT_METHODS(FObject)

		DEFINE_INTERFACES
			DEF_INTERFACE(Steinberg::Vst::IConnectionPoint)
		END_DEFINE_INTERFACES(FObject)


		Steinberg::tresult PLUGIN_API connect(Steinberg::Vst::IConnectionPoint* other)override;
		Steinberg::tresult PLUGIN_API disconnect(Steinberg::Vst::IConnectionPoint* other)override;
		Steinberg::tresult PLUGIN_API notify(Steinberg::Vst::IMessage* message)override;

		void Broadcast(Steinberg::Vst::IMessage* message);

	private:
		std::unordered_set<Steinberg::Vst::IConnectionPoint*> _connections;
		VirtualConnectionCallback _callback;
	};

}