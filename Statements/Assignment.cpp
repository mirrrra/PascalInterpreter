#include "Assignment.h"

Assignment::Assignment(Driver* driver, const std::string& id, Expression* value)
        : driver_(driver), id_(id), value_(value) {}

void Assignment::run() {
    driver_->variables[id_] = value_->eval();
}