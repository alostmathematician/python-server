#include "include/lex/lexer.h"

int main()
{
    char addr[]="/mnt/c/Users/qin/desktop/123.txt";
    FILE* file=open_file(addr);
    tokenize(file);
    return 0;
}