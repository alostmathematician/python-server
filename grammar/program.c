#include "program.h"

void programme(void)
{
    segment();
    programme();
    return;
}

void segment(void)
{
    NEXT_TOKEN;
    if (cur_token.tag == KW_EXTERN)
    {
        type();
        def();
    }
    else
    {
        type();
        def();
    }
    return;
}

void type(void)
{
    NEXT_TOKEN;
    if (cur_token.tag == KW_INT || cur_token.tag == KW_VOID || cur_token.tag== KW_CHAR)
    {
        return;
    }
    else
    {
        GRAM_THROW_ERROR(GRAM_FORMAT(cur_token.str,KEY_WORD_UNSUPPORT));
    }
}

void funtail(void)
{
    NEXT_TOKEN;
    if (cur_token.tag == SEMICOLON)
    {
        return;
    }
    else
    {
        block();
        return;
    }
}

void def(void)
{
    NEXT_TOKEN;
    if (cur_token.tag==ID)
    {
        idtail();
        return;
    }
    else if (cur_token.tag == MUL)
    {
        NEXT_TOKEN;
        if (cur_token.tag == ID)
        {
            init();
            deflist();
            return;
        }
        else
        {
            /* error */
        }
    }
    else
    {
        /* error */
    }
    
}

void idtail(void)
{
    NEXT_TOKEN;
    if (cur_token.tag == LPAREN)
    {
        para();
        NEXT_TOKEN;
        if (cur_token.tag == RPAREN)
        {
            funtail();
            return;
        }
        else
        {
            /* error */
        }
    }
    else
    {
        vardef();
        deflist();
        return;
    }
}

void vardef(void)
{
    NEXT_TOKEN;
    if (cur_token.tag == LBRACKET)
    {
        NEXT_TOKEN;
        if (cur_token.tag == NUM)
        {
            NEXT_TOKEN;
            if (cur_token.tag == RBRACKET)
            {
                return;
            }
            else
            {
                /* error */
            }
        }
        else
        {
            /* error */
        }
    }
    else
    {
        init();
        return;
    }
    
}

void init(void)
{
    NEXT_TOKEN;
    if (cur_token.tag == ASSIGN)
    {
        expr();
    }
    return;
}

void deflist(void)
{
    NEXT_TOKEN;
    if (cur_token.tag == COMMA)
    {
        defdata();
        deflist();
        return;
    }
    else if (cur_token.tag == SEMICOLON)
    {
        return;
    }
    else
    {
        /* error */
    }
}

void defdata(void)
{
    NEXT_TOKEN;
    if (cur_token.tag == ID)
    {
        vardef();
        return;
    }
    else if (cur_token.tag == MUL)
    {
        if (cur_token.tag == ID)
        {
            init();
            return;
        }
        else
        {
            /* error */
        }
    }
    else
    {
        /* error */
    }
    
}

void paradata(void)
{
    NEXT_TOKEN;
    if (cur_token.tag == ID)
    {
        paradatadetail();
    }
    else if (cur_token.tag == MUL)
    {
        NEXT_TOKEN;
        if (cur_token.tag == ID)
        {
            return;
        }
        else
        {
            /* error */
        }
        
    }
    else
    {
        /* error */
    }
}

void paradatadetail(void)
{
    NEXT_TOKEN;
    if (cur_token.tag == LBRACKET)
    {
        NEXT_TOKEN;
        if (cur_token.tag == NUM)
        {
            NEXT_TOKEN;
            if (cur_token.tag == RBRACKET)
            {
                return;
            }
            else
            {
                /* error */
            }
            
        }
        else
        {
            /* error */
        }
        
    }
    else
    {
        /* error */
    }
    
}