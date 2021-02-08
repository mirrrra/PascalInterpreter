#include "Assignment.h"

Assignment::Assignment(Driver* driver, const std::string& id, Expression* value)
        : driver_(driver), id_(id), value_(value) {}

void Assignment::run() {
    if (driver_->variables.find(id_) == driver_->variables.end()) {
        throw std::logic_error("Identifier doesn't exist");
    }
    driver_->variables[id_] = value_->eval();
}