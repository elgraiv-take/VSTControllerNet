#pragma once

#include <pluginterfaces/base/funknown.h>
namespace Elgraiv::VstControllerNet::Interop {
	template<typename T>
	ref class NativeStructHolder {
	public:
		static NativeStructHolder<T>^ CreateInstance() {
			return gcnew NativeStructHolder<T>(new T());
		}

		~NativeStructHolder() {
			delete _data;
			_data = nullptr;
		}
		!NativeStructHolder() {
			delete _data;
			_data = nullptr;
		}
		NativeStructHolder(T* instance): _data(instance) {
			
		}

		T* operator ->() {
			return _data;
		}

		static T& operator*(NativeStructHolder<T>% self) {
			return *self._data;
		}
	private:
		T* _data{ nullptr };
	};

	template<typename T>
	ref class ManagedModuleHandle {
	public:
		template<typename TInterface>
		ManagedModuleHandle<TInterface>^ QueryInterface() {
			TInterface* targetIf;
			_module->queryInterface(TInterface::iid, reinterpret_cast<void**>(&targetIf));
			return gcnew ManagedModuleHandle<TInterface>(targetIf);
		}

		ManagedModuleHandle(T* module):_module(module) {

		}

		T* operator ->() {
			return _module;
		}

		operator bool() {
			return _module != nullptr;
		}

		static T& operator*(ManagedModuleHandle<T>% self) {
			return *self._module;
		}

		!ManagedModuleHandle() {
			if (_module) {
				_module->release();
			}
			_module = nullptr;
		}
		~ManagedModuleHandle() {
			if (_module) {
				_module->release();
			}
			_module = nullptr;
		}
	private:
		T* _module{ nullptr };
	};


}