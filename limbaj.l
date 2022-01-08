%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
%}
%option noyywrap
%%

"int" {return Integer;}
"float" {return Float;}
"char" {return Character;}
"string" {return String;}
"bool" {return Bool;}
"const" {return CONST;}
"void" {return Void;}

"&&"    {return LOGICAL_AND;}
"||"    {return LOGICAL_OR;}
"<="    {return LS_EQ;}
">="    {return GR_EQ;}
"=="    {return EQ;}
"!="    {return NOT_EQ;}

"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"for" {return FOR;}
"--begin_stmt" {return BEGINSTMT;}
"--end_stmt" {return ENDSTMT;}

"class" {return CLASS;}
"--begin_class" {return BEGINCLASS;}
"--end_class" {return ENDCLASS;}
"private" {return PRIVATE;}
"protected" {return PROTECTED;}
"public" {return PUBLIC;}

"--begin_function" {return BEGINFNCTN;}
"--end_function" {return ENDFNCTN;}
"return" {return RTRN;}

"begin_progr" {return BGIN;}
"end_progr" {return END;}
@[_a-zA-Z][_a-zA-Z0-9]* {strcpy(yylval.string, yytext); return ID;}
":=" {return ASSIGN;}
[0-9]+ { yylval.intval = atoi(yytext); return NR; }
[ \t] ;
\n {yylineno++;}
. {return *yytext;}

 