#include "ConfigValue.hpp"

#include <exception>

Config::Value::Value(
    const std::string &name
) : name_(name) {}

std::string Config::Value::getName() const noexcept {
    return name_;
}

int Config::Value::toInt() const {
    throw std::runtime_error("Cannot convert to integer");
}

std::string Config::Value::toString() const {
    throw std::runtime_error("Cannot convert to string");
}

double Config::Value::toDouble() const {
    throw std::runtime_error("Cannot convert to double");
}

bool Config::Value::toBool() const {
    throw std::runtime_error("Cannot convert to bool");
}

Config::IntValue::IntValue(
    const std::string &name, 
    int data
) : Value(name), data_(data) {}

int Config::IntValue::toInt() const {
    return data_;
}

Config::StringValue::StringValue(
    const std::string &name, 
    const std::string &data
) : Value(name), data_(data) {}

std::string Config::StringValue::toString() const {
    return data_;
}

Config::DoubleValue::DoubleValue(
    const std::string &name, 
    double data
) : Value(name), data_(data) {}

double Config::DoubleValue::toDouble() const {
    return data_;
}

Config::BoolValue::BoolValue(
    const std::string &name, 
    bool data
) : Value(name), data_(data) {}

bool Config::BoolValue::toBool() const {
    return data_;
}

void ValueArray::add(
    value_ptr value
) {
    const std::string &name = value->getName();

    for (const value_ptr &it : values) {
        if (it->getName() == name) {
            throw std::runtime_error(
                "Value with such name already exists: " + name
            );
        }
    }

    values.push_back(std::move(val));
}

const Value &ValueArray::operator[](
    const std::string &name
) const {
    for (const value_ptr &val : values) {
        if (val->getName() == name) {
            return *val;
        }
    }

    throw std::runtime_error(
        "Value with such name doesn't exist: " + name
    );
}