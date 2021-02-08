#pragma once

#include "Statement.h"
#include "../driver.hh"
#include "../Expressions/Expression.h"
#include <list>
#include <string>

class WriteStatement: public Statement {
public:
    WriteStatement(std::list<Expression*> args, bool need_break);
    void run() override;
private:
    std::list<Expression*> args_;
    bool need_break_;
};