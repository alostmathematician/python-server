#ifndef _GAME_ERROR_H_
#define _GAME_ERROR_H_
#define FILE_OPEN_ERROR "Failed to open file\n"
#define FILE_HANDLER_ERROR "File handler is null\n"
#define FILE_GET_POS_ERROR "Failed to get file position\n"
#define FILE_SET_POS_ERROR "Failed to set file position\n"
#define CHAR_NO_QUOTION "character has no right quotion\n"
#define CHAR_INVALID "invalid character\n"
#define CHAR_NO_DATA "no character between quotion\n"
#define STR_INVALID "invalid character in string\n"
#define STR_NO_QUOTION "string has no right quotion\n"
#define BIN_DATA_ERROR "invalid binary data\n"
#define HEX_DATA_ERROR "invalid binary data\n"
#define GRAM_TYPE_ERROR "keyword type has mismatched\n"

#define LEXERROR(s) fprintf(stderr,s)
#define FILEERROR(s) fprintf(stderr,s)
#define GRAMERROR(s) fprintf(stderr,s)
#endif