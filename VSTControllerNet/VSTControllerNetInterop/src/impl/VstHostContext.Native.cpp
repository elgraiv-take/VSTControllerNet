
#include "VstHostContext.Native.hpp"

#include <public.sdk/source/vst/hosting/hostclasses.h>
#include <public.sdk/source/vst/hosting/parameterchanges.h>
#include "public.sdk/source/vst/utility/stringconvert.h"

namespace Elgraiv::VstControllerNet::Native {

    HostContext::HostContext(const std::string name, const Desc& desc)
        : _name(name)
    {
    }

    Steinberg::tresult PLUGIN_API HostContext::getName(Steinberg::Vst::String128 name) {
        return VST3::StringConvert::convert(_name, name) ? Steinberg::kResultTrue : Steinberg::kInternalError;
    }


    Steinberg::tresult PLUGIN_API HostContext::createInstance(Steinberg::TUID cid, Steinberg::TUID iid, void** obj)
	{
        auto const classID = Steinberg::FUID::fromTUID(cid);
        auto const interfaceID = Steinberg::FUID::fromTUID(iid);

        if (classID == Steinberg::Vst::IMessage::iid && interfaceID == Steinberg::Vst::IMessage::iid)
        {
            *obj = new Steinberg::Vst::HostMessage();
            return Steinberg::kResultTrue;
        }
        else if (classID == Steinberg::Vst::IAttributeList::iid && interfaceID == Steinberg::Vst::IAttributeList::iid)
        {
            if (auto list = Steinberg::Vst::HostAttributeList::make())
            {
                *obj = list.take();
                return Steinberg::kResultTrue;
            }
            return  Steinberg::kOutOfMemory;
        }
        *obj = 0;
        return Steinberg::kResultFalse;
	}


    Steinberg::tresult PLUGIN_API HostContext::beginEdit(Steinberg::Vst::ParamID id)
    {
        return Steinberg::kResultTrue;
    }
    Steinberg::tresult PLUGIN_API HostContext::performEdit(Steinberg::Vst::ParamID id, Steinberg::Vst::ParamValue valueNormalized)
    {
        return Steinberg::kResultTrue;
    }
    Steinberg::tresult PLUGIN_API HostContext::endEdit(Steinberg::Vst::ParamID id)
    {
        return Steinberg::kResultTrue;
    }
    Steinberg::tresult PLUGIN_API HostContext::restartComponent(Steinberg::int32 flags)
    {
        return Steinberg::kResultTrue;
    }
    Steinberg::tresult PLUGIN_API HostContext::setDirty(Steinberg::TBool state)
    {
        return Steinberg::kResultTrue;
    }
    Steinberg::tresult PLUGIN_API HostContext::requestOpenEditor(Steinberg::FIDString name)
    {
        return Steinberg::kResultTrue;
    }
    Steinberg::tresult PLUGIN_API HostContext::startGroupEdit()
    {
        return Steinberg::kResultTrue;
    }
    Steinberg::tresult PLUGIN_API HostContext::finishGroupEdit()
    {
        return Steinberg::kResultTrue;
    }
    Steinberg::tresult PLUGIN_API HostContext::resizeView(Steinberg::IPlugView* view, Steinberg::ViewRect* newSize)
    {
        return Steinberg::kResultTrue;
    }
}