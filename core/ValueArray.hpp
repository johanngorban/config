#pragma once

#include "Value.hpp"

#include <vector>

namespace Config {
    class ValueArray {
    private:
        std::vector<value_ptr> values;
    public:
        void add(value_ptr value);

        const Value &operator[](const std::string &name) const;
    };
}