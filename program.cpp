#include "program.h"

Program::Program(const std::list<Statement*>& statements)
        : statements_(statements) {}

void Program::run() {
    for (Statement* elem: statements_) {
        elem->run();
    }
}