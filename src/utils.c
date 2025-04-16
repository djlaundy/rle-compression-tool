/* Include any necessary libraries and header files */
#include "../header_files/utils.h"
#include <stdlib.h>
#include <string.h>

void free_pointer(char *pntr) {
    if ( pntr != NULL ) {
        free(pntr);
    }
}

void change_extension(char *file_name,const char *new_extension) {
    strcpy(&file_name[strlen(file_name) - 4], new_extension);
}