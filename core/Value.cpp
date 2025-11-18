#include "Value.hpp"

#include <exception>

using namespace Config::Core;

Value::Value(
    const std::string &name
) : name_(name) {}

std::string Value::getName() const noexcept {
    return name_;
}

int Value::toInt() const {
    throw std::runtime_error("Cannot convert to integer");
}

std::string Value::toString() const {
    throw std::runtime_error("Cannot convert to string");
}

double Value::toDouble() const {
    throw std::runtime_error("Cannot convert to double");
}

bool Value::toBool() const {
    throw std::runtime_error("Cannot convert to bool");
}

StringValue::StringValue(
    const std::string &name, 
    const std::string &data
) : Value(name), data_(data) {}

std::string StringValue::toString() const {
    return data_;
}

NumberValue::NumberValue(
    const std::string &name, 
    double data
) : Value(name), data_(data) {}

double NumberValue::toDouble() const {
    return data_;
}

double NumberValue::toInt() const {
    return static_cast<int>(data_);
}

BoolValue::BoolValue(
    const std::string &name, 
    bool data
) : Value(name), data_(data) {}

bool BoolValue::toBool() const {
    return data_;
}