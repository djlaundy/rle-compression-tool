/* Include any necessary libraries and header files */
#include "../header_files/utils.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

void free_pointer(char *pntr)
{
    if (pntr != NULL)
    {
        free(pntr);
    }
}

void change_extension(char *file_name, const char *new_extension)
{
    strcpy(&file_name[strlen(file_name) - 4], new_extension);
}

void open_file(FILE **ptr, char *file_name, char *opt)
{
    *ptr = fopen(file_name, opt); // open original file for input
    if (*ptr == NULL)
    {
        fprintf(stderr, "Could not open source file to compress: %s\n", file_name);
        exit(EXIT_FAILURE);
    }
}

void print_to_file(FILE *file, const char *format, ...)
{
    va_list args;
    va_start(args, format);

    // Use vfprintf to handle the variable arguments
    if (vfprintf(file, format, args) < 0)
    {
        perror("Could not write to file");
        exit(EXIT_FAILURE);
    }

    va_end(args);
}