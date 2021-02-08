#include "StrExpression.h"

StrExpression::StrExpression(const std::string& value): value_(value) {}

std::string StrExpression::eval() const {
    return value_;
}