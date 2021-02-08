#include "NumExpression.h"

NumExpression::NumExpression(Driver* driver, const std::string& id): driver_(driver), id_(id) {}

std::string NumExpression::eval() const {
    if (driver_->variables.find(id_) == driver_->variables.end()) {
        throw std::logic_error("Identifier doesn't exist");
    }
    return driver_->variables[id_];
}