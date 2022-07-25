#pragma once

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

		T& GetData() {
			return *_data;
		}

	private:
		T* _data{ nullptr };
	};

	template<typename T>
	ref class ManagedModuleHandle {
	public:
		ManagedModuleHandle(T* module):_module(module) {

		}

		T* operator ->() {
			return _module;
		}

		operator bool() {
			return _module != nullptr;
		}

		!ManagedModuleHandle() {
			_module->release();
			_module = nullptr;
		}
		~ManagedModuleHandle() {
			_module->release();
			_module = nullptr;
		}
	private:
		T* _module{ nullptr };
	};

}