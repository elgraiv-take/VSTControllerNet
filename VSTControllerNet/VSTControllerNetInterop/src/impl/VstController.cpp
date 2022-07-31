
#include "VstController.Bridge.hpp"
#include "VstControllerView.Bridge.hpp"
#include "VstVirtualConnectionPoint.Native.hpp"
#include "VstConnectionPoint.Bridge.hpp"
#include <pluginterfaces/vst/ivsteditcontroller.h>
#include <pluginterfaces/vst/ivstmessage.h>
#include <pluginterfaces/gui/iplugview.h>

namespace Elgraiv::VstControllerNet::Interop {

	VstController::Bridge::Bridge(Steinberg::Vst::IEditController* native, VstClassInfo^ classInfo)
		: _classInfo(classInfo), _native(gcnew ManagedModuleHandle<Steinberg::Vst::IEditController>(native))
	{

		_connectionPoint = gcnew VstConnectionPoint(gcnew VstConnectionPoint::Bridge((*_native).QueryInterface<Steinberg::Vst::IConnectionPoint>()));
		
		
	}

	VstControllerView^ VstController::Bridge::CreateView()
	{
		auto view=_native->createView(Steinberg::Vst::ViewType::kEditor);
		if (view == nullptr) {
			view = _native->createView(nullptr);
		}
		if (view == nullptr) {
			_native->queryInterface(Steinberg::IPlugView_iid, (reinterpret_cast<void**>(&view)));
		}
		auto bridge=gcnew VstControllerView::Bridge(view);
		return gcnew VstControllerView(bridge);
	}


	////////////////////////////


	VstController::VstController(Bridge^ bridge) :_bridge(bridge)
	{
	}

	VstClassInfo^ VstController::ClassInfo::get() {
		return _bridge->ClassInfo;
	}
	VstConnectionPoint^ VstController::ConnectionPoint::get() {
		return _bridge->ConnectionPoint;
	}

	VstControllerView^ VstController::CreateView()
	{
		return _bridge->CreateView();
	}

}