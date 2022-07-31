#include "DevRelayConnector.hpp"


namespace Elgraiv::VstControllerNet::Interop::Dev {
	RelayConnector::RelayConnector()
	{
		_callbackForA = gcnew ConnectorMessageCallback(this, &RelayConnector::RelayFromA);
		auto funcPtrA = System::Runtime::InteropServices::Marshal::GetFunctionPointerForDelegate(_callbackForA);
		auto callbackA = Native::VirtualConnectionCallback(reinterpret_cast<void(*)(Steinberg::Vst::IMessage*)>(funcPtrA.ToPointer()));
		_connectorA = gcnew ManagedModuleHandle<Native::VstVirtualConnectionPoint>(new Native::VstVirtualConnectionPoint(callbackA));

		_callbackForB = gcnew ConnectorMessageCallback(this, &RelayConnector::RelayFromB);
		auto funcPtrB = System::Runtime::InteropServices::Marshal::GetFunctionPointerForDelegate(_callbackForB);
		auto callbackB = Native::VirtualConnectionCallback(reinterpret_cast<void(*)(Steinberg::Vst::IMessage*)>(funcPtrB.ToPointer()));
		_connectorB = gcnew ManagedModuleHandle<Native::VstVirtualConnectionPoint>(new Native::VstVirtualConnectionPoint(callbackB));
	}
	void Dev::RelayConnector::RelayFromA(Steinberg::Vst::IMessage* message)
	{
		_connectorB->Broadcast(message);
	}
	void Dev::RelayConnector::RelayFromB(Steinberg::Vst::IMessage* message)
	{
		_connectorA->Broadcast(message);
	}
}