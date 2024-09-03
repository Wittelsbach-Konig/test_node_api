#include <napi.h>

#include "converter.h"
#include "hello_world.h"
#include "wrapped_class.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  temperatureConverter::Init(env, exports);
  hello_world::Init(env, exports);
  return WrappedClass::Init(env, exports);
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)