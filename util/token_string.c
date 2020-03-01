#include "token_string.h"

bool push_back(char* str,const char ch)
{
    if (strlen(str)==MAX_TOKEN_SIZE)
    {
        return false;
    }
    str[pos++]=ch;
    return true;
}

void reset_str(char* str)
{
    memset(str,'\0',strlen(str));
    pos=0;
}

void roll_back(void)
{
    read_pos-=1;
}