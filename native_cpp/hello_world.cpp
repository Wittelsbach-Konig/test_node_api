#include "hello_world.h"

std::string hello_world::hello() { return "Hello, World!"; }

int hello_world::add(int a, int b) { return a + b; }

Napi::Number hello_world::AddWrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
    Napi::Error::New(env, "Invalid arguments").ThrowAsJavaScriptException();
  }
  Napi::Number a = info[0].As<Napi::Number>();
  Napi::Number b = info[1].As<Napi::Number>();
  return Napi::Number::New(env,
                           hello_world::add(a.Int32Value(), b.Int32Value()));
}

Napi::String hello_world::HelloWrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::String::New(env, hello_world::hello());
}

Napi::Object hello_world::Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "hello"),
              Napi::Function::New(env, hello_world::HelloWrapped));
  exports.Set(Napi::String::New(env, "add"),
              Napi::Function::New(env, hello_world::AddWrapped));
  return exports;
}