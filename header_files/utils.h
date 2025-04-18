#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
void free_pointer(char *pntr);
void change_extension(char *file_name, const char *new_extension);
void open_file(FILE **ptr, char *file_name, char *opt);
void print_to_file(FILE *file, const char *format, ...);

#endif