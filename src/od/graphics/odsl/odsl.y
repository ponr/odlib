
%{
#include <stdio.h>

int yyparse(void);
int yylex(void);

int yywrap()
{
    return 1;
}

void yyerror(const char *s);

%}

%union {
}

%token QUOTE
%token BLOCK_BEGIN BLOCK_END
%token KW_IF KW_ELSE

%%

aee: ;

%%

void yyerror(const char *s)
{
    fprintf(stderr, "Error %s\n", s);
}

