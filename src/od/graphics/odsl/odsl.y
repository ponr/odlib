
%{
#include <stdio.h>

extern "C"
{
    int yyparse(void);
    int yylex(void);
    int yywrap()
    {
        return 1;
    }
    void yyerror(char *s);
}

%}

%union {
}

%%

aee: ;

%%

void yyerror(char *s)
{
    fprintf(stderr, "Error %s\n", s);
}

