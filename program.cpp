#include "program.h"

Program::Program(const std::list<Statement*>& statements)
        : statements_(statements) {}

void Program::run() {
    for (auto it = statements_.rbegin(); it != statements_.rend(); it++) {
        (*it)->run();
    }
}