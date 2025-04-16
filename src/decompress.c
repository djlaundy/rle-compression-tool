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
    FILE *file = fopen(input_file_name, "r"); // open original file for input
    if (file == NULL)
    {
        perror("Could not open source file to decompress");
        exit(EXIT_FAILURE);
    }
    // update file with .rle extension
    char *output_file_name = input_file_name;
    change_extension(output_file_name, ".txt");
    FILE *uncompressed_file = fopen(output_file_name, "w");
    if (uncompressed_file == NULL)
    {
        perror("Could not create decompressed file");
        exit(EXIT_FAILURE);
    }
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
                    if (fprintf(uncompressed_file, "%c", prev_c) < 0)
                    {
                        perror("Could not write to decompressed file");
                        fclose(file);
                        fclose(uncompressed_file);
                        exit(EXIT_FAILURE);
                    }
                }
                num[0] = '\0';
            }
            c_int = 0;
            prev_c = c;
            if (c == '\n')
            {
                prev_c = '\0';
                if (fprintf(uncompressed_file, "%c", c) < 0)
                {
                    perror("Could not write to decompressed file");
                    fclose(file);
                    fclose(uncompressed_file);
                    exit(EXIT_FAILURE);
                }
            }
        }
    if (prev_c != '\0' && prev_c != '\n')
    {
        c_int = atoi(num);
        for (int i = 0; i < c_int; i++)
        {
            if (fprintf(uncompressed_file, "%c", prev_c) < 0)
            {
                perror("Could not write to decompressed file");
                fclose(file);
                fclose(uncompressed_file);
                exit(EXIT_FAILURE);
            }
        }
    }
    // close files when done
    fclose(file);
    fclose(uncompressed_file);
    return 0;
}