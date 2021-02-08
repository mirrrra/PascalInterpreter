#pragma once

#include "Expression.h"
#include "../driver.hh"

class OpExpression: public Expression {
public:
    OpExpression(char op, Expression* exp1, Expression* exp2);
    std::string eval() const override;
private:
    char op_;
    Expression* exp1_;
    Expression* exp2_;
};