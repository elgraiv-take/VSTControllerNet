#pragma once

namespace Elgraiv::VstControllerNet::Interop{

	public ref class VstPluginFactory {
	public:
		property int NumberOfClasses {
			int get();
		}

		property System::Collections::Generic::IEnumerable<ref class VstClassInfo^>^ ClassInfos
		{
			System::Collections::Generic::IEnumerable<ref class VstClassInfo^>^ get();
		}

		VstPluginFactory(System::IntPtr getPluginFactory);

	internal:
		ref class Bridge;
	private:
		Bridge^ _bridge;
	};

}