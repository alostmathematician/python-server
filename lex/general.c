#include "general.h"

FILE* open_file(char* file_addr)
{
    FILE* file = fopen(file_addr,"r");
    if (file == NULL)
    {
        FILEERROR(FILE_OPEN_ERROR);
        exit(EXIT_FAILURE);
    }
    return file;
}

void scan(FILE* file)
{
    if (!file)
    {
        FILEERROR(FILE_HANDLER_ERROR);
        exit(EXIT_FAILURE);
    }
    if (read_pos==strlen(buffer))
    {
        if (fgets(buffer,MAX_BUFFER_SIZE,file) != NULL)
        {
            read_pos=0;
        }
        else
        {
            ch=EOF;
            return;
        }
    }
    ch=buffer[read_pos++];
}
