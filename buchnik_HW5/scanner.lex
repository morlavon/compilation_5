%{
#include "attributes.hpp"
#include "hw3_output.hpp"
#include "parser.tab.hpp"
#include <stdlib.h>
%}

%option yylineno
%option noyywrap
%option nounput

digit   		([0-9])
letter  		([a-zA-Z])
whitespace		([\t\n\r ])
colon           (:)
sc              (;)
comma           (,)
lparen          (\()
rparen          (\))
lbrace          (\{)
rbrace          (\})
assign          (=)
strong_relop    (<|>|<=|>=)
weak_relop      (==|!=)
strong_binop    ([*/])
weak_binop      ([+-])
%%

void                            yylval.type = yytext; return VOID;
int                             yylval.type = yytext; return INT;
byte                            yylval.type = yytext; return BYTE;
b                               yylval.type = yytext; return B;
bool                            yylval.type = yytext; return BOOL;
and                             return AND;
or                              return OR;
not                             return NOT;
true                            return TRUE;
false                           return FALSE;
return                          return RETURN;
if                              return IF;
else                            return ELSE;
while                           return WHILE;
break                           return BREAK;
continue                        return CONTINUE;
switch                          return SWITCH;
case                            return CASE;
default                         return DEFAULT;
{colon}                         return COLON;
{sc}                            return SC;
{comma}                         return COMMA;
{lparen}                        return LPAREN;
{rparen}                        return RPAREN;
{lbrace}                        return LBRACE;
{rbrace}                        return RBRACE;
{assign}                        return ASSIGN;
{strong_relop}                  yylval.s = yytext; return STRONG_RELOP;
{weak_relop}                    yylval.s = yytext; return WEAK_RELOP;
{strong_binop}                  yylval.s = yytext; return STRONG_BINOP;
{weak_binop}                    yylval.s = yytext; return WEAK_BINOP;
\/\/[^\r\n]*(\r|\n|\r\n)?       ;
{letter}+[a-zA-Z0-9]*           yylval.s = yytext; return ID;
0                               yylval.i = 0; return NUM;
[1-9]+{digit}*                  yylval.i = atoi(yytext); return NUM;
\"([^\n\r\"\\]|\\[rnt"\\])+\"   yylval.s = yytext; return STRING;
{whitespace}                    ;
.		                        output::errorLex(yylineno); exit(1);

%%


