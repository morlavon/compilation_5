%{
#include "utilities.hpp"
#include "hw3_output.hpp"
#include "parser.tab.hpp"
#include <stdlib.h>
%}

%option yylineno
%option noyywrap

whitespace ([\t\r\n ])
digit ([0-9])
byteseq (b)
comma (,)
lparen ([(])
rparen ([)])
lbrace ([{])
rbrace ([}])
comment (\/\/[^\r\n]*)
assign ([=])
sep ([;])
ret (return)
weak_relop (==|!=)
strong_relop ([<>]=?)
strong_binop ([*\/])
weak_binop ([+\-])
letter ([a-zA-Z])
id     ({letter}({letter}|{digit})*)
num    (0|[1-9]{digit}*)
quote ([\\"])
string (\"([^\n\r\"\\]|\\[rnt"\\])+\")


%%
void            {
                yylval.type = "VOID";
                return VOID;
                }
int             {
                yylval.type = "INT";
                return INT;
                }
byte            {
                yylval.type = "BYTE";
                return BYTE;
                }
const           {
                yylval.type = "CONST";
                yylval.isConst = true;
                return CONST;
                }
{byteseq}       {
                yylval.type = "B";
                return B;
                }
bool            {
                yylval.type = "BOOL";
                return BOOL;
                }
and             return AND;
or              return OR;
not             return NOT;
true            return TRUE;
false           return FALSE;
{ret}           return RETURN;
if              return IF;
else            return ELSE;
while           return WHILE;
break           return BREAK;
continue        return CONTINUE;
{comma}         return COMMA;
{assign}        return ASSIGN;
{lparen}        return LPAREN;
{rparen}        return RPAREN;
{lbrace}        return LBRACE;
{rbrace}        return RBRACE;
{strong_relop}  {
                yylval.name = yytext;
                return STRONG_RELOP;
                }
{weak_relop}    {
                yylval.name = yytext;
                return WEAK_RELOP;
                }
{strong_binop}  {
                yylval.name = yytext;
                return STRONG_BINOP;
                }
{weak_binop}    {
                yylval.name = yytext;
                return WEAK_BINOP;
                }
{comment}       ;
{id}            {
                yylval.name = yytext;
                return ID;
                }
{num}           {
                yylval.value=atoi(yytext);
                return NUM;
                }
{sep}           return SC;
{whitespace}    ;
{string}        {
                 yylval.name = yytext;
                 return STRING;
                 }
.               {
                output::errorLex(yylineno);
                exit(1);
                }
%%
