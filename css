%{
#include "parser.tab.h"
%}

%%
"<"[a-zA-Z]+[[:alnum:]_-]*[^>]*">"  { yylval.strval = strdup(yytext); return OPEN_TAG; }
"</"[a-zA-Z]+[[:alnum:]_-]*[^>]*">" { yylval.strval = strdup(yytext); return CLOSE_TAG; }
"<"[a-zA-Z]+[[:alnum:]_-]*[^>]*"/>" { yylval.strval = strdup(yytext); return SELF_CLOSE_TAG; }
[^<]+                              { yylval.strval = strdup(yytext); return TEXT; }
"<"[^>]*">"                        { yylval.strval = strdup(yytext); return INVALID_TAG; }
