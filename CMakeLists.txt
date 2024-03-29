cmake_minimum_required(VERSION 3.0)
project(SimpleInterpreter)

set(CMAKE_CXX_STANDARD 14)
if (CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin")
    execute_process(
            COMMAND brew --prefix bison
            RESULT_VARIABLE BREW_BISON
            OUTPUT_VARIABLE BREW_BISON_PREFIX
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (BREW_BISON EQUAL 0 AND EXISTS "${BREW_BISON_PREFIX}")
        message(STATUS "Found Bison keg installed by Homebrew at ${BREW_BISON_PREFIX}")
        set(BISON_EXECUTABLE "${BREW_BISON_PREFIX}/bin/bison")
    endif ()

    execute_process(
            COMMAND brew --prefix flex
            RESULT_VARIABLE BREW_FLEX
            OUTPUT_VARIABLE BREW_FLEX_PREFIX
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (BREW_FLEX EQUAL 0 AND EXISTS "${BREW_FLEX_PREFIX}")
        message(STATUS "Found Flex keg installed by Homebrew at ${BREW_FLEX_PREFIX}")
        set(FLEX_EXECUTABLE "${BREW_FLEX_PREFIX}/bin/flex")
        include_directories(${BREW_FLEX_PREFIX}/include)
    endif ()
endif ()

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

set(
        HEADERS
        ${SimpleInterpreter_SOURCE_DIR}/driver.hh
        ${SimpleInterpreter_SOURCE_DIR}/parser.hh
)

BISON_TARGET(
        MyParser
        parser.y
        ${SimpleInterpreter_SOURCE_DIR}/parser.cpp
        DEFINES_FILE ${SimpleInterpreter_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
        MyScanner
        scanner.l
        ${SimpleInterpreter_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_executable(
        SimpleInterpreter
        main.cpp
        driver.cpp
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS}
        Expressions/NumExpression.cpp
        Expressions/IntExpression.cpp
        Expressions/OpExpression.cpp
        Expressions/StrExpression.cpp
        Statements/ForStatement.cpp
        Statements/Assignment.cpp
        Statements/WhileStatement.cpp
        Statements/IfStatement.cpp
        Statements/WriteStatement.cpp
        Program.cpp
)
target_include_directories(SimpleInterpreter PRIVATE ${SimpleInterpreter_SOURCE_DIR})



