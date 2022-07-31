#pragma once
#include "VstVirtualConnectionPoint.Native.hpp"
#include "Utils.hpp"

namespace Elgraiv::VstControllerNet::Interop::Dev {
	public delegate void ConnectorMessageCallback(Steinberg::Vst::IMessage* message);
	ref class RelayConnector {
	public:
		RelayConnector();


		property ManagedModuleHandle<Native::VstVirtualConnectionPoint>^ ConnectionA{
			ManagedModuleHandle<Native::VstVirtualConnectionPoint>^ get() {
				return _connectorA;
			}
		}
		property ManagedModuleHandle<Native::VstVirtualConnectionPoint>^ ConnectionB {
			ManagedModuleHandle<Native::VstVirtualConnectionPoint>^ get() {
				return _connectorB;
			}
		}

	private:
		void RelayFromA(Steinberg::Vst::IMessage* message);
		void RelayFromB(Steinberg::Vst::IMessage* message);
		ConnectorMessageCallback^ _callbackForA;
		ConnectorMessageCallback^ _callbackForB;

		ManagedModuleHandle<Native::VstVirtualConnectionPoint>^ _connectorA;
		ManagedModuleHandle<Native::VstVirtualConnectionPoint>^ _connectorB;
	};
}