#include "wrapped_class.h"

Napi::FunctionReference WrappedClass::constructor;

Napi::Object WrappedClass::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func =
      DefineClass(env, "WrappedClass",
                  {InstanceMethod("add", &WrappedClass::Add),
                   InstanceMethod("getValue", &WrappedClass::GetValue),
                   InstanceMethod("setValue", &WrappedClass::SetValue)});
  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();
  exports.Set("WrappedClass", func);
  return exports;
}

WrappedClass::WrappedClass(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<WrappedClass>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  int length = info.Length();
  if (length != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  if (!info[0].IsNumber()) {
    Napi::Object object_parent = info[0].As<Napi::Object>();
    WrappedClass* parent =
        Napi::ObjectWrap<WrappedClass>::Unwrap(object_parent);
    SimpleClass* parent_simple_class_instance = parent->GetInternalInstance();
    this->_simpleClass =
        new SimpleClass(parent_simple_class_instance->getValue());
    return;
  }
  Napi::Number value = info[0].As<Napi::Number>();
  this->_simpleClass = new SimpleClass(value.DoubleValue());
}

Napi::Value WrappedClass::GetValue(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  double num = this->_simpleClass->getValue();
  return Napi::Number::New(env, num);
}

Napi::Value WrappedClass::SetValue(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  int length = info.Length();
  if (length != 1 || !info[0].IsNumber()) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  Napi::Number value = info[0].As<Napi::Number>();
  this->_simpleClass->setValue(value.DoubleValue());
  return env
      .Null();  // No return value for this method since it modifies the state
}

Napi::Value WrappedClass::Add(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  int length = info.Length();
  if (length != 1 || !info[0].IsNumber()) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  Napi::Number value = info[0].As<Napi::Number>();
  double result = this->_simpleClass->add(value.DoubleValue());
  return Napi::Number::New(env, result);
}

SimpleClass* WrappedClass::GetInternalInstance() { return this->_simpleClass; }
