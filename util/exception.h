#ifndef _UTIL_EXCEPTION_H_
#define _UTIL_EXCEPTION_H_

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

#if defined(_MSC_VER) && _MSC_VER <= 1900
#define __func__ __FUNCTION__
#endif

static bool pass=true;
typedef enum {
    CHAR_NO_R_QUOTION,CHAR_NO_CONTENT,
    STR_NO_R_DOUBLE_QUOTION,
    NUM_BIN_NO_DATA,NUM_HEX_NO_DATA,NUM_OCT_NO_DATA,
    TOKEN_NO_EXIST
} LexError;

typedef enum {
    LEFT_PAREN_LOST,RIGHT_PAREN_LOST,
    LEFT_BRAC_LOST,RIGHT_BRAC_LOST,
    COLON_LOST,SEMICOLON_LOST,COMMA_LOST,
    IF_LOST,IF_WRONG,
    ELSE_LOST,ELSE_WRONG,
    WHILE_LOST,WHILE_WRONG,
    SWITCH_LOST,SWITCH_WRONG,
    CASE_LOST,CASE_WRONG,
    ASSIGN_LOST,ASSIGN_WRONG,
    KEY_WORD_UNSUPPORT
} GramError;
#define LEX_THROW_ERROR(fmt, ...) fprintf(stderr,"Unidentified Word:%s , %s , %d,Word:"fmt,__FILE__,__func__,__LINE__,##__VA_ARGS__)
#define GRAM_THROW_ERROR(fmt,...) fprintf(stderr,"Grammar Error:%s , %s, %d"fmt,__FILE__,__func__,__LINE__,##__VA_ARGS__)
#define GRAM_FORMAT(token,lexError) token.str##lexError

char* fine_lex_error(LexError);
char* find_gram_error(GramError);
#endif