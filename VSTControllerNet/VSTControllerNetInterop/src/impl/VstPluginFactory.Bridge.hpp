#pragma once

#include "../VstClassInfo.hpp"
#include "../VstPluginFactory.hpp"
#include "../VstModule.hpp"
#include <pluginterfaces/base/ftypes.h>

namespace Steinberg {
	class IPluginFactory;
}

namespace Elgraiv::VstControllerNet::Interop {

	ref class VstPluginFactory::Bridge {
	public:
		Bridge(System::IntPtr getPluginFactory);

		int GetNumberOfClasses() {
			return _numberOfClasses;
		}

		property System::Collections::Generic::IEnumerable<ref class VstClassInfo^>^ ClassInfos {
			System::Collections::Generic::IEnumerable<ref class VstClassInfo^>^ get() {
				return _classInfos;
			}
		}
		
		VstController::Bridge^ CreateControllerInstance(const Steinberg::FIDString& cid);

	private:
		Steinberg::IPluginFactory* _nativeFactory{ nullptr };
		int _numberOfClasses{ 0 };
		System::Collections::Generic::List<VstClassInfo^>^ _classInfos{ gcnew System::Collections::Generic::List<VstClassInfo^>() };
	};
}