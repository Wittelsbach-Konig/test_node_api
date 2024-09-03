#include <napi.h>

#include "simple_class.h"

class WrappedClass : public Napi::ObjectWrap<WrappedClass> {
 private:
  static Napi::FunctionReference constructor;
  Napi::Value GetValue(const Napi::CallbackInfo& info);
  Napi::Value SetValue(const Napi::CallbackInfo& info);
  Napi::Value Add(const Napi::CallbackInfo& info);
  SimpleClass* _simpleClass;

 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  WrappedClass(const Napi::CallbackInfo& info);
  SimpleClass* GetInternalInstance();
};