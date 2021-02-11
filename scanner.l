%{
    #include <cerrno>
    #include <climits>
    #include <cstdlib>
    #include <cstring> // strerror
    #include <string>
    #include <iostream>
    #include "driver.hh"
    #include "parser.hh"
%}

%option noyywrap nounput noinput batch debug

%option c++
%option yyclass="Scanner"

%{
  // A number symbol corresponding to the value in S.
  yy::parser::symbol_type make_NUMBER(
    const std::string &s,
    const yy::parser::location_type& loc
  );
%}

id    [a-zA-Z][a-zA-Z_0-9]*
int   [+-]?[0-9]+
blank [ \t\r]
str   ['][a-zA-Z_0-9 <>=!+*\/-]*[']

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}
%%
%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = driver.location;
  // Code run each time yylex is called.
  loc.step();
%}

{blank}+   loc.step ();
\n+        loc.lines (yyleng); loc.step ();

{str}      return yy::parser::make_STR(yytext, loc);
"-"        return yy::parser::make_MINUS  (loc);
"+"        return yy::parser::make_PLUS   (loc);
"*"        return yy::parser::make_STAR   (loc);
"/"        return yy::parser::make_SLASH  (loc);
"("        return yy::parser::make_LPAREN (loc);
")"        return yy::parser::make_RPAREN (loc);
":="       return yy::parser::make_ASSIGN (loc);
":"        return yy::parser::make_COLON  (loc);
";"        return yy::parser::make_SEMICOLON(loc);
","        return yy::parser::make_COMMA(loc);
"."        return yy::parser::make_POINT(loc);
"<"        return yy::parser::make_LE(loc);
">"        return yy::parser::make_GE(loc);
"="        return yy::parser::make_EQ(loc);
"program"  return yy::parser::make_PROGRAM (loc);
"begin"    return yy::parser::make_START  (loc);
"end"      return yy::parser::make_FINISH   (loc);
"var"      return yy::parser::make_VAR  (loc);
"if"       return yy::parser::make_IF   (loc);
"then"     return yy::parser::make_THEN  (loc);
"else"     return yy::parser::make_ELSE   (loc);
"while"    return yy::parser::make_WHILE  (loc);
"do"       return yy::parser::make_DO   (loc);
"for"      return yy::parser::make_FOR   (loc);
"to"       return yy::parser::make_TO   (loc);
"downto"   return yy::parser::make_DOWNTO   (loc);
"and"      return yy::parser::make_AND   (loc);
"or"       return yy::parser::make_OR   (loc);
"not"      return yy::parser::make_NOT   (loc);
"write"    return yy::parser::make_WRITE   (loc);
"writeln"  return yy::parser::make_WRITELN   (loc);
"integer"  return yy::parser::make_INT   (loc);

{int}      return yy::parser::make_NUMBER(yytext, loc);
{id}       {
                if (driver.location_debug) {
                    std::cerr << "ID found " << yytext << std::endl;
                }
                return yy::parser::make_IDENTIFIER(yytext, loc);
           }
.          {
                throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext));
           }
<<EOF>>    return yy::parser::make_END (loc);
%%

/* yy::parser::symbol_type make_NUMBER(
  const std::string &s,
  const yy::parser::location_type& loc
) {
  errno = 0;
  long n = strtol(s.c_str(), NULL, 10);
  if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
    throw yy::parser::syntax_error(loc, "integer is out of range: " + s);
  return yy::parser::make_NUMBER((int) n, loc);
} */