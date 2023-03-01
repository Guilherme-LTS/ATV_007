%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void yyerror(char const *s);
int yylex(void);
%}

%union {
    char *strval;
}

%token <strval> TEXT
%token <strval> OPEN_TAG
%token <strval> CLOSE_TAG
%token <strval> SELF_CLOSE_TAG
%token <strval> INVALID_TAG

%start html

%%

html : 
    | html element
    ;

element :
    TEXT
    | OPEN_TAG attributes CLOSE_TAG html CLOSE_TAG
    | SELF_CLOSE_TAG
    | INVALID_TAG
    ;

attributes :
    | attributes attribute
    ;

attribute :
    TEXT "=" TEXT
    ;

%%

void yyerror(char const *s) {
    fprintf(stderr, "%s\n", s);
}

int main() {
    yyparse();
    return 0;
}
