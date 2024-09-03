#include <napi.h>

namespace temperatureConverter {
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);
Napi::Number celsiusToFahrenheitWrapped(const Napi::CallbackInfo& info);
Napi::Number fahrenheitToCelsiusWrapped(const Napi::CallbackInfo& info);
Napi::Object Init(Napi::Env env, Napi::Object exports);
}  // namespace temperatureConverter
