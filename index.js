const testnapi = require("./build/Release/testnapi.node");

console.log("addon", testnapi);

console.log(testnapi.hello());

console.log("add func ", testnapi.add(2, 3));

const classInstance = new testnapi.WrappedClass(3.3);

console.log("class instance", classInstance.getValue());

console.log("add ", classInstance.add(4.4));

const prevInstance = new testnapi.WrappedClass(5.5);

console.log("Initial value : ", prevInstance.getValue());
console.log("After add : ", prevInstance.add(6.6));

const newFromExisting = new testnapi.WrappedClass(prevInstance);

console.log("New instance from existing : ", newFromExisting.getValue());

console.log("Celsius 100 = ", testnapi.celsiusToFahrenheit(100), " Fahrenheit");

module.exports = testnapi;
