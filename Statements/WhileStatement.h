#pragma once

#include "Statement.h"
#include "../driver.hh"

class WhileStatement: public Statement {
public:
    WhileStatement(Expression* expr, Statement* statement);
    void run() override;
private:
    Expression* expr_;
    Statement* statement_;
};