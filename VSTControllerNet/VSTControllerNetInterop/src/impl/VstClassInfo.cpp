#include "VstClassInfo.Bridge.hpp"
#include "VstPluginFactory.Bridge.hpp"
#include "VstController.Bridge.hpp"
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
				dict->Add(g_categoryAudioModule, ClassType::AudioModule);
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
		auto& data = _data->GetData();

		std::memcpy(&data, &info, sizeof(info));

		_name = gcnew System::String(info.name);
		_classType = CategoryConverter::CategoryToEnum(gcnew System::String(data.category));


	}

	void VstClassInfo::Bridge::CreateInstance()
	{
		switch (_classType)
		{
		case Elgraiv::VstControllerNet::Interop::ClassType::Unknown:
			break;
		case Elgraiv::VstControllerNet::Interop::ClassType::AudioModule:
			break;
		case Elgraiv::VstControllerNet::Interop::ClassType::Controller:
		{
			auto controller = _factory->CreateControllerInstance(_data->GetData().cid);
			break;
		}
		default:
			break;
		}
	}


	//////////////////////////////////////


	VstClassInfo::VstClassInfo(Bridge^ info) :_bridge(info) {

	}
	void VstClassInfo::CreateInstance()
	{
		_bridge->CreateInstance();
	}
	System::String^ VstClassInfo::Name::get() {
		return _bridge->Name;
	}
	ClassType VstClassInfo::Type::get() {
		return _bridge->Type;
	}

}