#include "VstPluginFactory.Bridge.hpp"
#include "VstClassInfo.Bridge.hpp"
#include <pluginterfaces/base/ipluginbase.h>
#include <pluginterfaces/vst/ivstaudioprocessor.h>
#include <pluginterfaces/vst/ivsteditcontroller.h>
#include "VstController.Bridge.hpp"
namespace Elgraiv::VstControllerNet::Interop {

	VstPluginFactory::Bridge::Bridge(System::IntPtr getPluginFactory)
	{

		auto getter = reinterpret_cast<Steinberg::IPluginFactory * (*)(void)>(getPluginFactory.ToPointer());
		_nativeFactory = getter();
		_numberOfClasses = _nativeFactory->countClasses();

		for (auto i = 0; i < _numberOfClasses; i++) {
			Steinberg::PClassInfo classInfo;
			_nativeFactory->getClassInfo(i, &classInfo);

			auto newInfo = gcnew VstClassInfo(gcnew VstClassInfo::Bridge(classInfo, this));
			_classInfos->Add(newInfo);
		}
	}

	Steinberg::Vst::IEditController* VstPluginFactory::Bridge::CreateControllerInstance(const Steinberg::FIDString& cid)
	{
		Steinberg::Vst::IEditController* controller;
		auto result = _nativeFactory->createInstance(cid, Steinberg::Vst::IEditController_iid, (void**)&controller);
		return controller;

	}
	Steinberg::Vst::IComponent* VstPluginFactory::Bridge::CreateAudioProcessorInstance(const Steinberg::FIDString& cid)
	{
		Steinberg::Vst::IComponent* controller;
		auto result = _nativeFactory->createInstance(cid, Steinberg::Vst::IComponent_iid, (void**)&controller);
		return controller;

	}

	/////////////////////////////////////////////////

	VstPluginFactory::VstPluginFactory(System::IntPtr getPluginFactory)
		:_bridge(gcnew Bridge(getPluginFactory))
	{

	}

	int VstPluginFactory::NumberOfClasses::get() {
		return _bridge->GetNumberOfClasses();
	}
	System::Collections::Generic::IEnumerable<ref class VstClassInfo^>^ VstPluginFactory::ClassInfos::get() {
		return _bridge->ClassInfos;
	}
}
