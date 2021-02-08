#include "NumExpression.h"

NumExpression::NumExpression(Driver* driver, const std::string& id): driver_(driver), id_(id) {}

std::string NumExpression::eval() const {
    return driver_->variables[id_];
}