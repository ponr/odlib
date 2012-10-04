/*

*/
%{
#include "odsl.parser.h"

int lineno = 0;
%}

string  \"[^\n"]+\"
ws      [ \t]+
alpha   [A-Za-z]
digit   [0-9]

%%

\"      return QUOTE;
\{      return BLOCK_BEGIN;
\}      return BLOCK_END;
"if"    return KW_IF;
"else"  return KW_ELSE;

%%
/* */

