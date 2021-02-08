#pragma once

#include "Expression.h"
#include "../driver.hh"

class StrExpression: public Expression {
public:
    StrExpression(const std::string& value);
    std::string eval() const override;
private:
    std::string value_;
};