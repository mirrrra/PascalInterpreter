#include "IntExpression.h"

IntExpression::IntExpression(const std::string& value): value_(value) {}

std::string IntExpression::eval() const {
    return value_;
}