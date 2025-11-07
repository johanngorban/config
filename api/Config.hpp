#pragma once

#include "ValueArray.hpp"

#include <ifstream>
#include <string>

namespace Config {
    class Config {
    private:
        ValueArray values;
    public:
        explicit Config(const std::ifstream &is);
    private:
        void parseConfig(const std::string &cfg);
    public:
        const Value &operator[](const std::string &name) const;
    }
}