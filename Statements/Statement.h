#pragma once
#include <string>
#include "../driver.hh"
#include "../Expressions/Expression.h"

class Statement {
public:
    virtual void run() = 0;
};