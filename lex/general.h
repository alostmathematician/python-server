#ifndef _LEX_GENERAL_H_
#define _LEX_GENERAL_H_
#define MAX_BUFFER_SIZE 80
#define TOKEN_LEN 30
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../error/error.h"

int read_pos;

char ch;
char buffer[MAX_BUFFER_SIZE];
static int line_num=1;
static int col_num=0;

typedef enum {
    ERR,
    END,
    ID,
    KW_INT,KW_CHAR,KW_VOID,
    KW_EXTERN,
    NUM,CH,STR,
    NOT,LEA,
    ADD,SUB,MUL,DIV,MOD,FLOOR,
    INC,DEC,INC_MUL,DEC_DIV,
    GT,GE,LT,LE,EQU,NEQU,
    AND,OR,ELEMENT_AND,ELEMENT_OR,
    LPAREN,RPAREN,
    LBRACKET,RBRACKET,
    LBRACE,RBRACE,
    COMMA,COLON,SEMICOLON,
    ASSIGN,
    KW_IF,KW_ELSE,
    KW_SWITCH,KW_CASE,KW_DEFAULT,
    KW_WHILE,KW_DO,KW_FOR,
    KW_BREAK,KW_CONTINUE,KW_RETURN
}Tag;

typedef struct 
{
    Tag tag;
    char* str;
}Token;


FILE* open_file(char*);
void scan(FILE*);
#endif