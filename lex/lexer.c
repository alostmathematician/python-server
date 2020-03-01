#include "lexer.h"

void tokenize(FILE* file)
{
    init_hashmap();
    Token token;
    token.str=(char*)calloc(MAX_TOKEN_SIZE,sizeof(char));
    while (1)
    {
        scan(file);
        reset_str(token.str);
        if (ch=='_' || isalpha(ch))
        {
            do
            {
                push_back(token.str,ch);
                scan(file);
            } while (ch == '_' || isalpha(ch) || isdigit(ch));
            token.tag=hash_find(token.str);
            roll_back();
        }
        else if (isspace(ch))
        {continue;}
        else if (isdigit(ch))
        {
            if (ch > '0' && ch <= '9')
            {
                do
                {
                    push_back(token.str,ch);
                    scan(file);
                } while (isdigit(ch));
                token.tag=NUM;
                roll_back();
            }
            if (ch == '0')
            {
                push_back(token.str,ch);
                scan(file);
                if (ch == 'x' || ch == 'X')
                {
                    push_back(token.str,ch);
                    scan(file);
                    if (isdigit(ch) || (ch <= 'Z' && ch >= 'A') || (ch <= 'z' && ch >= 'a'))
                    {
                        do
                        {
                            push_back(token.str,ch);
                            scan(file);
                        } while (isdigit(ch) || (ch <= 'Z' && ch >= 'A') || (ch <= 'z' && ch >= 'a'));
                        token.tag=NUM;
                        roll_back();
                    }
                    else
                    {
                        token.tag=ERR;
                        push_back(token.str,ch);
                    }
                    
                }
                else if (ch == 'O' || ch == 'o')
                {
                    push_back(token.str,ch);
                    scan(file);
                    if (ch < '8' && ch >= '0')
                    {
                        do
                        {
                            push_back(token.str,ch);
                            scan(file);
                        } while (ch < '8' && ch >= '0');
                        token.tag=NUM;
                        roll_back();
                    }
                    else
                    {
                        token.tag=ERR;
                        push_back(token.str,ch);
                    }
                }
                else if (ch == 'b' || ch == 'B')
                {
                    push_back(token.str,ch);
                    scan(file);
                    if (ch == '0' || ch == '1')
                    {
                        do
                        {
                            push_back(token.str,ch);
                            scan(file);
                        } while (ch == '0' && ch == '1');
                        token.tag=NUM;
                        roll_back();
                    }
                    else
                    {
                        token.tag=ERR;
                        push_back(token.str,ch);
                    }
                }
                else
                {
                    token.tag=NUM;
                    push_back(token.str,ch);
                    roll_back();
                }
            }
        }
        else if (ch == '\'')
        {
            scan(file);
            if (ch == '\\')
            {
                scan(file);
                switch (ch)
                {
                case 'n':
                    token.tag=CH;
                    push_back(token.str,'\n');
                    break;
                case 't':
                    token.tag=CH;
                    push_back(token.str,'\t');
                    break;
                case '\\':
                    token.tag=CH;
                    push_back(token.str,'\\');
                    break;
                case '0':
                    token.tag=CH;
                    push_back(token.str,'\0');
                    break;
                case '\'':
                    token.tag=CH;
                    push_back(token.str,'\'');
                    break;
                default:
                    token.tag=ERR;
                    push_back(token.str,'\\');
                    push_back(token.str,ch);
                    break;
                }
            }
            else if (ch == -1 || ch == '\n')
            {
                token.tag=ERR;
                push_back(token.str,ch);
            }
            else if (ch == '\'')
            {
                token.tag=ERR;
                push_back(token.str,ch);
            }
            else
            {
                token.tag=CH;
                push_back(token.str,ch);
            }
            if (token.tag==CH)
            {
                scan(file);
                if (ch != '\'')
                {
                    token.tag=ERR;
                    push_back(token.str,ch);
                }
            }
        }
        else if (ch == '"')
        {
            do
            {
                scan(file);
                if (ch == '\\')
                {
                    scan(file);
                    switch (ch)
                    {
                    case 'n':
                        push_back(token.str,'\n');
                        break;
                    case 't':
                        push_back(token.str,'\t');
                        break;
                    case '\\':
                        push_back(token.str,'\\');
                        break;
                    case '0':
                        push_back(token.str,'\0');
                        break;
                    case '\'':
                        push_back(token.str,'\'');
                        break;
                    default:
                        push_back(token.str,ch);
                        break;
                    }
                }
                else if (ch == -1 || ch == '\n')
                {
                    token.tag=ERR;
                    push_back(token.str,ch);
                    break;
                }
                else
                {
                    push_back(token.str,ch);   
                }
            } while (ch != '"');
            if (token.tag != ERR)
            {
                token.tag=STR;
            }
        }
        else if (ch == '=')
        {
            push_back(token.str,ch);
            scan(file);
            if (ch =='=')
            {
                token.tag=EQU;
                push_back(token.str,ch);
            }
            else
            {
                token.tag=ASSIGN;
                roll_back();
            }
            
        }
        else if (ch == '>')
        {
            push_back(token.str,ch);
            scan(file);
            if (ch == '=')
            {
                token.tag=GE;
                push_back(token.str,ch);
            }
            else
            {
                token.tag=GT;
                roll_back();
            }
        }
        else if(ch == '<')
        {
            push_back(token.str,ch);
            scan(file);
            if (ch == '=')
            {
                token.tag=LE;
                push_back(token.str,ch);
            }
            else
            {
                token.tag=LT;
                roll_back();
            }
        }
        else if (ch == '+')
        {
            push_back(token.str,ch);
            scan(file);
            if (ch == '=' || ch == '+')
            {
                token.tag=INC;
                push_back(token.str,ch);
            }
            else
            {
                token.tag=ADD;
                roll_back();
            }
        }
        else if (ch == '-')
        {
            push_back(token.str,ch);
            scan(file);
            if (ch == '=' || ch == '-')
            {
                token.tag=DEC;
                push_back(token.str,ch);
            }
            else
            {
                token.tag=SUB;
                roll_back();
            }
        }
        else if (ch == '*')
        {
            push_back(token.str,ch);
            scan(file);
            if (ch == '=')
            {
                token.tag=INC_MUL;
                push_back(token.str,ch);
            }
            else
            {
                token.tag=MUL;
                roll_back();
            }
        }
        else if (ch == '/')
        {
            push_back(token.str,ch);
            scan(file);
            if (ch == '=')
            {
                token.tag=DEC_DIV;
                push_back(token.str,ch);
            }
            else if (ch == '/')
            {
                token.tag=FLOOR;
                push_back(token.str,ch);
            }
            else
            {
                token.tag=DIV;
                roll_back();
            }
        }
        else if (ch == ',')
        {
            token.tag=COMMA;
            push_back(token.str,ch);
        }
        else if (ch == ';')
        {
            token.tag=SEMICOLON;
            push_back(token.str,ch);
        }
        else if (ch == ':')
        {
            token.tag=COLON;
            push_back(token.str,ch);
        }
        else if (ch == '!')
        {
            push_back(token.str,ch);
            scan(file);
            if (ch == '=')
            {
                token.tag=NEQU;
                push_back(token.str,ch);
            }
            else
            {
                token.tag=NOT;
                roll_back();
            }
        }
        else if (ch == '(')
        {
            token.tag=LPAREN;
            push_back(token.str,ch);
        }
        else if (ch == ')')
        {
            token.tag=RPAREN;
            push_back(token.str,ch);
        }
        else if (ch == '[')
        {
            token.tag=LBRACKET;
            push_back(token.str,ch);
        }
        else if (ch == ']')
        {
            token.tag=RBRACKET;
            push_back(token.str,ch);
        }
        else if (ch == '{')
        {
            token.tag=LBRACE;
            push_back(token.str,ch);
        }
        else if (ch == '}')
        {
            token.tag=RBRACE;
            push_back(token.str,ch);
        }
        else if (ch == '&')
        {
            push_back(token.str,ch);
            scan(file);
            if (ch == '&')
            {
                token.tag=AND;
                push_back(token.str,ch);
            }
            else
            {
                scan(file);
                if (isspace(ch))
                {
                    token.tag=ELEMENT_AND;
                    roll_back();
                }
                else if (ch == '_' || isalpha(ch))
                {
                    token.tag=LEA;
                    roll_back();
                }
                else
                {
                    token.tag=ERR;
                    roll_back();
                }
            }
        }
        else if (ch == '|')
        {
            push_back(token.str,ch);
            scan(file);
            if (ch == '|')
            {
                token.tag=OR;
                push_back(token.str,ch);
            }
            else
            {
                token.tag=ELEMENT_OR;
                roll_back();
            }
        }
        else if (ch == EOF || ch == '\0')
        {
            token.tag=END;
            push_back(token.str,ch);
            printf("tag:%d,str:%s\n",token.tag,token.str);
            break;
        }
        else
        {
            token.tag=ERR;
        }
        printf("tag:%d,str:%s\n",token.tag,token.str);
    }
}