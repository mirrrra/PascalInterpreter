#pragma once

#include "Statements/Statement.h"
#include "Expressions/Expression.h"
#include <list>

class Program {
public:
    Program(const std::list<Statement*>& statements);
    void run();
private:
    std::list<Statement*> statements_;
};