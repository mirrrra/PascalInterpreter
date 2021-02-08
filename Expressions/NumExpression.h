#pragma once

#include "Expression.h"
#include "../driver.hh"

class NumExpression: public Expression {
public:
    NumExpression(Driver* driver, const std::string& id);
    std::string eval() const override;
private:
    std::string id_;
    Driver* driver_;
};