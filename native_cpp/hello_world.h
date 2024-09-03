#include <napi.h>

namespace hello_world {
std::string hello();
int add(int a, int b);
Napi::Number AddWrapped(const Napi::CallbackInfo& info);
Napi::String HelloWrapped(const Napi::CallbackInfo& info);
Napi::Object Init(Napi::Env env, Napi::Object exports);
}  // namespace hello_world