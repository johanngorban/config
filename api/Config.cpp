#include "Config.hpp"

Config::Config(
    const std::ifstream &is
) : values() {
    std::stringstream buffer;
    buffer << is.rdbuf();

    std::string content = buffer.str();
    parseConfig(content);
}

void Config::parseConfig(
    const std::string &cfg
) {
    // TODO: parse it!
}

const Value &Config::operator[](
    const std::string &name
) const {
    return values[name];
}