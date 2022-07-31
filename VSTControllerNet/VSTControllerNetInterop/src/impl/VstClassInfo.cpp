#include "VstClassInfo.Bridge.hpp"
#include "VstPluginFactory.Bridge.hpp"
#include "VstController.Bridge.hpp"
#include "VstAudioProcessor.Bridge.hpp"
#include "VstHostContext.Bridge.hpp"
#include "VstHostContext.Native.hpp"
#include <pluginterfaces/vst/ivstaudioprocessor.h>
#include <pluginterfaces/vst/ivsteditcontroller.h>
#include <pluginterfaces/base/ipluginbase.h>
#include "Utils.hpp"


namespace Elgraiv::VstControllerNet::Interop {
	namespace {
		ref class CategoryConverter {
		private:
			static System::String^ const g_categoryAudioModule = gcnew System::String(kVstAudioEffectClass);
			static System::String^ const g_categoryController = gcnew System::String(kVstComponentControllerClass);

			static System::Collections::Generic::Dictionary<System::String^, ClassType>^ g_classTypeDict;

			static CategoryConverter() {
				auto dict = gcnew System::Collections::Generic::Dictionary<System::String^, ClassType>();
				dict->Add(g_categoryAudioModule, ClassType::AudioProcessor);
				dict->Add(g_categoryController, ClassType::Controller);
				g_classTypeDict = dict;

			}
		public:
			static ClassType CategoryToEnum(System::String^ categoryName) {
				auto type = ClassType::Unknown;
				if (g_classTypeDict->TryGetValue(categoryName, type)) {
					return type;
				}
				return ClassType::Unknown;
			}
		};

	}
	//////////////////////////////////////

	VstClassInfo::Bridge::Bridge(const Steinberg::PClassInfo& info, VstPluginFactory::Bridge^ factory) :_factory(factory) {
		_data = NativeStructHolder<Steinberg::PClassInfo>::CreateInstance();
		auto& data = **_data;

		std::memcpy(&data, &info, sizeof(info));

		_name = gcnew System::String(info.name);
		_classType = CategoryConverter::CategoryToEnum(gcnew System::String(data.category));


	}

	IVstModule^ VstClassInfo::Bridge::CreateInstance(VstClassInfo^ wrapper, VstHostContext^ context)
	{
		switch (_classType)
		{
		case Elgraiv::VstControllerNet::Interop::ClassType::Unknown:
			break;
		case Elgraiv::VstControllerNet::Interop::ClassType::AudioProcessor:
		{

			auto component = _factory->CreateAudioProcessorInstance(_data->cid);
			auto res1 = component->initialize(&**(context->NativeBridge->Host));
			return gcnew VstAudioProcessor(gcnew VstAudioProcessor::Bridge(component, wrapper));
		}
		case Elgraiv::VstControllerNet::Interop::ClassType::Controller:
		{

			auto controller =_factory->CreateControllerInstance(_data->cid);
			auto res1 = controller->initialize(&**(context->NativeBridge->Host));
			auto res2 = controller->setComponentHandler(&**context->NativeBridge->ComponentHandler);
			return gcnew VstController(gcnew VstController::Bridge(controller, wrapper));
		}
		default:
			break;
		}
		return nullptr;
	}


	//////////////////////////////////////


	VstClassInfo::VstClassInfo(Bridge^ info) :_bridge(info) {

	}
	IVstModule^ VstClassInfo::CreateInstance(VstHostContext^ context)
	{
		return _bridge->CreateInstance(this, context);
	}
	System::String^ VstClassInfo::Name::get() {
		return _bridge->Name;
	}
	ClassType VstClassInfo::Type::get() {
		return _bridge->Type;
	}

}