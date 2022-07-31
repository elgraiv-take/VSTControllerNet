#pragma once
#include "../VstClassInfo.hpp"
#include "../VstPluginFactory.hpp"
#include "Utils.hpp"

namespace Steinberg {
	struct PClassInfo;
}

namespace Elgraiv::VstControllerNet::Interop {


	ref class VstClassInfo::Bridge {
	public:
		Bridge(const Steinberg::PClassInfo& info, VstPluginFactory::Bridge^ factory);

		property System::String^ Name {
			System::String^ get() {
				return _name;
			}
		}
		property ClassType Type {
			ClassType get() {
				return _classType;
			}
		}

		const Steinberg::PClassInfo& GetNativeInfo() {
			return *(*_data);
		}

		interface class IVstModule^ CreateInstance(VstClassInfo^ wrapper, ref class VstHostContext^ context);

	private:
		NativeStructHolder<Steinberg::PClassInfo>^ _data;
		System::String^ _name;
		ClassType _classType;
		VstPluginFactory::Bridge^ _factory;
	};
}