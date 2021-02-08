%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    #include <list>

    class Scanner;
    class Driver;
    class Program;
    class Expression;
    class NumExpression;
    class IntExpression;
    class OpExpression;
    class StrExpression;
    class Statement;
    class Assignment;
    class ForStatement;
    class WhileStatement;
    class IfStatement;
    class WriteStatement;
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "program.h"
    #include <list>
    #include "driver.hh"
    #include "location.hh"
    #include "Expressions/Expression.h"
    #include "Expressions/NumExpression.h"
    #include "Expressions/IntExpression.h"
    #include "Expressions/StrExpression.h"
    #include "Expressions/OpExpression.h"

    #include "Statements/Statement.h"
    #include "Statements/Assignment.h"
    #include "Statements/IfStatement.h"
    #include "Statements/ForStatement.h"
    #include "Statements/WhileStatement.h"
    #include "Statements/WriteStatement.h"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"
    POINT "."
    COMMA ","
    ASSIGN ":="
    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"
    LPAREN "("
    RPAREN ")"
    LE "<"
    GE ">"
    EQ "="
    AND "and"
    OR "or"
    COLON ":"
    SEMICOLON ";"
    PROGRAM "program"
    START "begin"
    FINISH "end"
    VAR "var"
    IF "if"
    THEN "then"
    ELSE "else"
    WHILE "while"
    DO "do"
    FOR "for"
    TO "to"
    WRITE "write"
    WRITELN "writeln"
    INT "int"
;

%token <std::string> IDENTIFIER "identifier"
%token <std::string> NUMBER "number"
%token <std::string> STR "str"
%nterm <Program*> start
%nterm <std::list<Statement*>> program_module
%nterm <std::list<Statement*>> block
%nterm <std::list<Statement*>> statements_seq
%nterm <Statement*> statement
%nterm <Statement*> assignment
%nterm <Statement*> if_statement
%nterm <Statement*> for_statement
%nterm <Statement*> while_statement
%nterm <Statement*> write_func

%nterm <std::list<Expression*>> args
%nterm <Expression*> arg
%nterm <Expression*> expression

//%printer { yyo << $$; } <*>;

%%
%start start;
start: program_module {
    $$ = new Program($1); driver.program = $$;
    };

program_module:
    "program" "identifier" ";" block "." { $$ = $4; };

block:
    "var" var_block "begin" statements_seq "end" { $$ = $4; }
    | "begin" statements_seq "end" { $$ = $2; };

var_block:
    %empty {}
    | var_decl ";" var_block {};

var_decl:
    id_list ":" "int" {};

id_list:
    "identifier" { driver.variables[$1] = ""; }
    | id_list "," "identifier" { driver.variables[$3] = ""; };

statements_seq:
    %empty { $$ = std::list<Statement*>(); }
    | statement ";" statements_seq {
        $3.push_back($1); $$ = $3;
    };

statement:
    assignment { $$ = $1; }
    | write_func { $$ = $1; }
    | if_statement { $$ = $1; }
    | while_statement { $$ = $1; }
    | for_statement { $$ = $1; }

assignment:
    "identifier" ":=" expression {
        $$ = new Assignment(&driver, $1, $3);
        // std::cout << drv.location.begin.line << "-" << drv.location.end.line << std::endl;
    };

write_func:
    "write" "(" args ")" { $$ = new WriteStatement($3, false); }
    | "writeln" "(" args ")" { $$ = new WriteStatement($3, true); };

args:
    arg { $$ = std::list<Expression*>(); $$.push_back($1); }
    | arg "," args { $3.push_back($1); $$ = $3; };

arg:
    expression { $$ = $1; }
    | "str" { $$ = new StrExpression($1); };

if_statement:
    "if" expression "then" statement "else" statement {
        $$ = new IfStatement($2, $4, $6);
    };

while_statement:
    "while" expression "do" statement{
        $$ = new WhileStatement($2, $4);
    };

for_statement:
    "for" "identifier" ":=" expression "to" expression "do" statement {
        $$ = new ForStatement(&driver, $2, $4, $6, $8);
    };

%left "and" "or";
%left "<" ">" "=";
%left "+" "-";
%left "*" "/";

expression:
    "number" {$$ = new IntExpression($1); }
    | "identifier" {$$ = new NumExpression(&driver, $1); }
    | expression "*" expression {$$ = new OpExpression('*', $1, $3); }
    | expression "/" expression {$$ = new OpExpression('/', $1, $3); }
    | expression "+" expression {$$ = new OpExpression('+', $1, $3); }
    | expression "-" expression {$$ = new OpExpression('-', $1, $3); }
    | expression "<" expression {$$ = new OpExpression('<', $1, $3); }
    | expression ">" expression {$$ = new OpExpression('>', $1, $3); }
    | expression "=" expression {$$ = new OpExpression('=', $1, $3); }
    | expression "and" expression {$$ = new OpExpression('&', $1, $3); }
    | expression "or" expression {$$ = new OpExpression('|', $1, $3); }
    | "(" expression ")" {$$ = $2; };

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
