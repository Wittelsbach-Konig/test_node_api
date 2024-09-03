#include "converter.h"

double temperatureConverter::celsiusToFahrenheit(double temperature) {
  return (temperature * 9 / 5) + 32;
}

double temperatureConverter::fahrenheitToCelsius(double temperature) {
  return (temperature - 32) * 5 / 9;
}

Napi::Number temperatureConverter::celsiusToFahrenheitWrapped(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
  }
  double temperature = info[0].As<Napi::Number>().DoubleValue();
  return Napi::Number::New(
      env, temperatureConverter::celsiusToFahrenheit(temperature));
}

Napi::Number temperatureConverter::fahrenheitToCelsiusWrapped(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
  }
  double temperature = info[0].As<Napi::Number>().DoubleValue();
  return Napi::Number::New(
      env, temperatureConverter::fahrenheitToCelsius(temperature));
}

Napi::Object temperatureConverter::Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "celsiusToFahrenheit"),
              Napi::Function::New(env, celsiusToFahrenheitWrapped));
  exports.Set(Napi::String::New(env, "fahrenheitToCelsius"),
              Napi::Function::New(env, fahrenheitToCelsiusWrapped));
  return exports;
}
