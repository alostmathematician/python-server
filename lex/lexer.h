#ifndef _Game_LEXER_H_
#define _Game_LEXER_H_
#include "../util/token_string.h"
#include "../util/hash_map.h"
#include "general.h"
#include "error.h"
#include <ctype.h>

void tokenize(FILE*);

#endif