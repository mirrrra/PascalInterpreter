#include "StrExpression.h"

StrExpression::StrExpression(const std::string& value) {
    value_ = value.substr(1, value.size() - 2);
}

std::string StrExpression::eval() const {
    return value_;
}