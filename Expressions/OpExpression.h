#pragma once

#include "Expression.h"
#include "../driver.hh"

class BinaryOpExpression: public Expression {
public:
    BinaryOpExpression(char op, Expression* exp1, Expression* exp2);
    std::string eval() const override;
private:
    char op_;
    Expression* exp1_;
    Expression* exp2_;
};

class UnaryOpExpression: public Expression {
public:
    UnaryOpExpression(char op, Expression* exp);
    std::string eval() const override;
private:
    char op_;
    Expression* exp_;
};