#pragma once

#include <base/source/fobject.h>
#include <pluginterfaces/vst/ivsthostapplication.h>
#include <pluginterfaces/vst/ivsteditcontroller.h>
#include <pluginterfaces/gui/iplugview.h>
#include <string>

namespace Elgraiv::VstControllerNet::Native{
	class HostContext
		: public Steinberg::FObject
		, public Steinberg::Vst::IHostApplication
		, public Steinberg::Vst::IComponentHandler
		, public Steinberg::Vst::IComponentHandler2
		, public Steinberg::IPlugFrame
	{
	public:
		struct Desc {

		};
		HostContext(const std::string name, const Desc& desc);

		OBJ_METHODS(HostContext, FObject)
	    REFCOUNT_METHODS(FObject)

		DEFINE_INTERFACES
			DEF_INTERFACE(Steinberg::Vst::IHostApplication)
			DEF_INTERFACE(Steinberg::Vst::IComponentHandler)
			DEF_INTERFACE(Steinberg::Vst::IComponentHandler2)
			DEF_INTERFACE(Steinberg::IPlugFrame)
		END_DEFINE_INTERFACES(FObject)

		Steinberg::tresult PLUGIN_API getName(Steinberg::Vst::String128 name) override;
		Steinberg::tresult PLUGIN_API createInstance(Steinberg::TUID cid, Steinberg::TUID iid, void** obj) override;

		///

		Steinberg::tresult PLUGIN_API beginEdit(Steinberg::Vst::ParamID id) override;

		Steinberg::tresult PLUGIN_API performEdit(Steinberg::Vst::ParamID id, Steinberg::Vst::ParamValue valueNormalized) override;

		Steinberg::tresult PLUGIN_API endEdit(Steinberg::Vst::ParamID id) override;
		Steinberg::tresult PLUGIN_API restartComponent(Steinberg::int32 flags) override;
		///

		Steinberg::tresult PLUGIN_API setDirty(Steinberg::TBool state) override;
		Steinberg::tresult PLUGIN_API requestOpenEditor(Steinberg::FIDString name = Steinberg::Vst::ViewType::kEditor) override;
		Steinberg::tresult PLUGIN_API startGroupEdit() override;
		Steinberg::tresult PLUGIN_API finishGroupEdit() override;

		///
		Steinberg::tresult PLUGIN_API resizeView(Steinberg::IPlugView* view, Steinberg::ViewRect* newSize) override;


		Steinberg::FUnknown* Self() { return static_cast<Steinberg::FObject*>(this); }
	private:
		std::string _name;
	};

	class VirtualConnectionPoint :public Steinberg::Vst::IConnectionPoint {

	};
}