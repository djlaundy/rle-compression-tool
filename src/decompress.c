/* Include any necessary libraries and header files */
#include "../header_files/decompress.h"
#include "../header_files/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int decompress(char *input_file_name)
{
    printf("Decompressing file: %s\n", input_file_name);
    FILE *file;
    open_file(&file, input_file_name, "r");
    // update file with .rle extension
    char *output_file_name = input_file_name;
    change_extension(output_file_name, ".txt");
    FILE *uncompressed_file;
    open_file(&uncompressed_file, output_file_name, "w");
    char c;
    char num[10] = ""; // Allocate sufficient space for storing digits
    int c_int = 0;
    char prev_c = '\0';
    while ((c = fgetc(file)) != EOF) // copy file character by character\
    {
        if (c == '\0')
        {
            num[0] = '\0';
        }
        else if (isdigit(c))
        {
            if (num[0] == '\0')
            {
                num[0] = c;    // Assign the character to the first index
                num[1] = '\0'; // Null-terminate the string
            }
            else
            {
                char temp[2] = {c, '\0'}; // Create a temporary string for the character
                strcat(num, temp);
            }
        }
        else
        {
            if (prev_c != '\0')
            {
                c_int = atoi(num);
                for (int i = 0; i < c_int; i++)
                {
                    print_to_file(uncompressed_file, "%c", prev_c);
                }
                num[0] = '\0';
            }
            c_int = 0;
            prev_c = c;
            if (c == '\n')
            {
                prev_c = '\0';
                print_to_file(uncompressed_file, "%c", c);
            }
        }
    if (prev_c != '\0' && prev_c != '\n')
    {
        c_int = atoi(num);
        for (int i = 0; i < c_int; i++)
        {
            print_to_file(uncompressed_file, "%c", prev_c);
        }
    }
    // close files when done
    fclose(file);
    fclose(uncompressed_file);
    return 0;
}