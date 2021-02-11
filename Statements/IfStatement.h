#pragma once

#include "Statement.h"
#include "../driver.hh"

class IfElseStatement: public Statement {
public:
    IfElseStatement(Expression* expr, Statement* then_condition, Statement* else_condition);
    void run() override;
private:
    Expression* expr_;
    Statement* then_condition_;
    Statement* else_condition_;
};

class IfStatement: public Statement {
public:
    IfStatement(Expression* expr, Statement* then_condition);
    void run() override;
private:
    Expression* expr_;
    Statement* then_condition_;
};