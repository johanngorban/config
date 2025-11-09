#pragma once

#include <string>

namespace Config {
    namespace Lexer {
        enum class TokenType {
            Identifier,
            Equals,
            Number,
            String,
            Bool,
            Semicolon,
        };

        class Token {
        private:
            const TokenType type_;
        public:
            explicit Token(TokenType type);    

            virtual ~Token() = default;
        public:
            TokenType getType() const noexcept;

            virtual std::string toString() const noexcept = 0;
        };

        class NumberToken final : public Token {
        private:
            const double data_;
        public:
            explicit NumberToken(double data);

            double getValue() const noexcept;

            std::string toString() const noexcept override;
        };

        class IdentifierToken final : public Token {
        private:
            const std::string data_;
        public:
            explicit IdentifierToken(const std::string &data);

            std::string getValue() const noexcept;

            std::string toString() const noexcept override;
        };

        class StringToken final : public Token {
        private:
            const std::string data_;
        public:
            explicit StringToken(const std::string &data);

            std::string getValue() const noexcept;

            std::string toString() const noexcept override;
        };

        class BoolToken final : public Token {
        private:
            const bool data_;
        public:
            explicit BoolToken(bool data);

            bool getValue() const noexcept;

            std::string toString() const noexcept override;
        };

        class SymbolToken final : public Token {
        public:
            explicit SymbolToken(TokenType type);

            std::string toString() const noexcept override;
        };
    }
}