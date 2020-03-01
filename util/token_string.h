#ifndef _GAME_TOKEN_STRING_H_
#define _GAME_TOKEN_STRING_H_
#define MAX_TOKEN_SIZE 100
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../lex/general.h"

static int pos=0;
bool push_back(char*,const char);
void reset_str(char*);
void roll_back(void);
#endif
