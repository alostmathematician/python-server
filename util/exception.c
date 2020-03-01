#include "./exception.h"

char* fine_lex_error(LexError le)
{
    char* words;
    switch (le)
    {
    case CHAR_NO_R_QUOTION:
        words="Character has no right quotion";
        break;
    case CHAR_NO_CONTENT:
        words="Cannot define a empty character";
        break;
    case STR_NO_R_DOUBLE_QUOTION:
        words="String has no right double quotion";
        break;
    case NUM_BIN_NO_DATA:
        words="Binary number is not finished";
        break;
    case NUM_HEX_NO_DATA:
        words="Hex number is not finished";
        break;
    case NUM_OCT_NO_DATA:
        words="Oct num is not finished";
        break;
    case TOKEN_NO_EXIST:
        words="Illegal input";
        break;
    default:
        words="";
        break;
    }
    return words;
}

char* find_gram_error(GramError ge)
{
    char* words;
    switch (ge)
    {
    case LEFT_PAREN_LOST:
        words="Left parenthese is lost";
        break;
    case RIGHT_PAREN_LOST:
        words="Right parenthese is lost";
        break;
    case LEFT_BRAC_LOST:
        words="Left bracket is lost";
        break;
    case RIGHT_BRAC_LOST:
        words="Right bracket is lost";
        break;
    case COLON_LOST:
        words="Colon is lost";
        break;
    case SEMICOLON_LOST:
        words="Semicolon is lost";
        break;
    case COMMA_LOST:
        words="Comma is lost";
        break;
    case IF_LOST:
        words="If is lost";
        break;
    case IF_WRONG:
        words="If is inappropriate at here";
        break;
    case ELSE_LOST:
        words="Else is lost";
        break;
    case ELSE_WRONG:
        words="Else is inappropriate at here";
        break;
    case WHILE_LOST:
        words="While is lost";
        break;
    case WHILE_WRONG:
        words="While is inappropriate at here";
        break;
    case SWITCH_LOST:
        words="Switch is lost";
        break;
    case SWITCH_WRONG:
        words="Switch is inappropriate at here";
        break;
    case CASE_LOST:
        words="Case is lost";
        break;
    case CASE_WRONG:
        words="Case is inappropriate at here";
        break;
    case ASSIGN_LOST:
        words="= is lost";
        break;
    case ASSIGN_WRONG:
        words="= is inappropriate at here";
        break;
    case KEY_WORD_UNSUPPORT:
        words="key word is undefined";
        break;
    default:
        words="";
        break;
    }
}