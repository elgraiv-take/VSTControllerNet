#include "VstAudioProcessor.Bridge.hpp"
#include "VstConnectionPoint.Bridge.hpp"
#include <pluginterfaces/vst/ivstcomponent.h>
#include <pluginterfaces/vst/ivstaudioprocessor.h>
#include <pluginterfaces/vst/ivstmessage.h>

namespace Elgraiv::VstControllerNet::Interop {

	VstAudioProcessor::Bridge::Bridge(Steinberg::Vst::IComponent* native, VstClassInfo^ classInfo)
		: _classInfo(classInfo), _native(gcnew ManagedModuleHandle<Steinberg::Vst::IComponent>(native))
	{

		_connectionPoint = gcnew VstConnectionPoint(gcnew VstConnectionPoint::Bridge((*_native).QueryInterface<Steinberg::Vst::IConnectionPoint>()));
		_processor = (*_native).QueryInterface<Steinberg::Vst::IAudioProcessor>();

	}
	void VstAudioProcessor::Bridge::Activete()
	{
		_native->setActive(true);
	}
	void VstAudioProcessor::Bridge::Deactivate()
	{
		_native->setActive(false);
	}
	////////////////////////////


	void VstAudioProcessor::Activete()
	{
		_bridge->Activete();
	}

	void VstAudioProcessor::Deactivate()
	{
		_bridge->Deactivate();
	}

	VstAudioProcessor::VstAudioProcessor(Bridge^ bridge) :_bridge(bridge)
	{
	}

	VstClassInfo^ VstAudioProcessor::ClassInfo::get() {
		return _bridge->ClassInfo;
	}
	VstConnectionPoint^ VstAudioProcessor::ConnectionPoint::get() {
		return _bridge->ConnectionPoint;
	}
}