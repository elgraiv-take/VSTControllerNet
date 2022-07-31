#pragma once

#include <base/source/fobject.h>
#include <pluginterfaces/vst/ivstmessage.h>
namespace Elgraiv::VstControllerNet::Native {
	class VstVirtualConnectionPoint
		: public Steinberg::FObject
		, public Steinberg::Vst::IConnectionPoint
	{
	public:

		OBJ_METHODS(VstVirtualConnectionPoint, FObject)
		REFCOUNT_METHODS(FObject)

		DEFINE_INTERFACES
			DEF_INTERFACE(Steinberg::Vst::IConnectionPoint)
		END_DEFINE_INTERFACES(FObject)


		Steinberg::tresult PLUGIN_API connect(Steinberg::Vst::IConnectionPoint* other)override;
		Steinberg::tresult PLUGIN_API disconnect(Steinberg::Vst::IConnectionPoint* other)override;
		Steinberg::tresult PLUGIN_API notify(Steinberg::Vst::IMessage* message)override;

	private:
	};

}