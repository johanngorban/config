#include "ValueArray.hpp"

using namespace Config::Core;

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

    values.push_back(std::move(value));
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