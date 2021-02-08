#pragma once

#include "Statement.h"
#include "../driver.hh"

class IfStatement: public Statement {
public:
    IfStatement(Expression* expr, Statement* then_condition, Statement* else_condition);
    void run() override;
private:
    Expression* expr_;
    Statement* then_condition_;
    Statement* else_condition_;
};