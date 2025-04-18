/* Include any necessary libraries and header files */
#include "../header_files/compress.h"
#include <stdio.h>
#include <stdlib.h>
#include "../header_files/utils.h"

int compress(char *input_file_name)
{
    printf("Compressing file: %s\n", input_file_name);
    FILE *file;
    open_file(&file, input_file_name, "r");
    // update file with .rle extension
    char *output_file_name = input_file_name;
    change_extension(output_file_name, ".rle");
    FILE *compressed_file;
    open_file(&compressed_file, output_file_name, "w");
    char c;
    char prev_c = '\0';
    int cnt = 0;
    while ((c = fgetc(file)) != EOF) // copy file character by character
    {
        if (c == '\0')
        {
            prev_c = '\0';
            cnt = 0;
        }
        else if (prev_c == c)
        {
            cnt++;
        }
        else if ((prev_c != '\0') && (prev_c != '\n'))
        {
            print_to_file(compressed_file, "%c%d", prev_c, cnt + 1);
            cnt = 0;
        }
        else if (prev_c == '\n')
        {
            print_to_file(compressed_file, "%c", prev_c);
            cnt = 0;
        }
        else if (prev_c == '\n')
        {
            print_to_file(compressed_file, "%c", prev_c);
        }
        prev_c = c;
    }
    // Handle the last character after the loop
    if (prev_c != '\0' && prev_c != '\n')
    {
        print_to_file(compressed_file, "%c%d", prev_c, cnt + 1);
    }
    // close files when done
    fclose(file);
    fclose(compressed_file);
    return 0;
}