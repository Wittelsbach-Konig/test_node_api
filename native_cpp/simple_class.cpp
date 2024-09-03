#include "simple_class.h"

SimpleClass::SimpleClass() { this->_value = 0.0; }

SimpleClass::SimpleClass(double value) { this->_value = value; }

double SimpleClass::getValue() { return this->_value; }

void SimpleClass::setValue(double value) { this->_value = value; }

double SimpleClass::add(double otherValue) {
  this->_value += otherValue;
  return this->_value;
}

SimpleClass::~SimpleClass() {}