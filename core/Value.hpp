#pragma once

#include <string>
#include <memory>

namespace Config {
    namespace Core {
        class Value;

        using value_ptr = std::unique_ptr<Value>;

        class Value {
        private:
            std::string name_;
        public:
            Value(const std::string &name);

            virtual ~Value() = default;
        public:
            std::string getName() const noexcept;

            virtual int toInt() const = 0;

            virtual std::string toString() const = 0;

            virtual double toDouble() const = 0;

            virtual bool toBool() const = 0;
        };

        class StringValue : public Value {
        private:
            std::string data_;
        public:
            StringValue(const std::string &name, const std::string &data);
        public:
            std::string toString() const override;
        };

        class NumberValue : public Value {
        private:
            double data_;
        public:
            NumberValue(const std::string &name, double data);
        public:
            double toDouble() const override;

            int toInt() const override;
        };

        class BoolValue : public Value {
        private:
            bool data_;
        public:
            BoolValue(const std::string &name, bool data);
        public:
            bool toBool() const override;
        };
    }
}