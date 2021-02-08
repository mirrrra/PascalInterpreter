#pragma once

#include "Expression.h"
#include "../driver.hh"

class IntExpression: public Expression {
public:
    IntExpression(const std::string& value);
    std::string eval() const override;
private:
    std::string value_;
};