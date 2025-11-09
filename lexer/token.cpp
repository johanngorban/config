#inclue "token.hpp"

using namespace Config::Lexer;

Token::Token(
    TokenType type
) : type_(type) {}

TokenType Token::getType() const noexcept {
    return type_;
}

NumberToken::NumberToken(
    double data
) : Token(TokenType::Number), data_(data) {}

double NumberToken::getValue() const noexcept {
    return data_;
}

std::string NumberToken::toString() const noexcept {
    return "data: " + std::to_string(data_);
}

IdentifierToken::IdentifierToken(
    const std::string &data
) : Token(TokenType::Identifier), data_(data) {}

std::string IdentifierToken::getValue() const noexcept {
    return data_;
}

std::string IdentifierToken::toString() const noexcept {
    return "data: " + data_;
}

StringToken::StringToken(
    const std::string &data
) : Token(TokenType::String), data_(data) {}

std::string StringToken::getValue() const noexcept {
    return data_;
}

std::string StringToken::toString() const noexcept {
    return "data: " + data_;
}

BoolToken::BoolToken(
    bool data
) : Token(TokenType::Bool), data_(data) {}

bool BoolToken::getValue() const noexcept {
    return data_;
}

std::string BoolToken::toString() const noexcept {
    return "data: " + std::to_string(data_);
}

SymbolToken::SymbolToken(
    TokenType type
) : Token(type) {}

std::string SymbolToken::toString() const noexcept {
    switch (getType()) {
        case TokenType::Equals: 
            return "Symbol(=)";
        case TokenType::Semicolon: 
            return "Symbol(;)";
        default: 
            return "Symbol(?)";
    }
}