/* Include any necessary libraries and header files */
#include "../header_files/compress.h"
#include <stdio.h>
#include <stdlib.h>
#include "../header_files/utils.h"

int compress(char *input_file_name)
{
    printf("Compressing file: %s\n", input_file_name);
    FILE *file = fopen(input_file_name, "r"); // open original file for input
    if (file == NULL)
    {
        perror("Could not open source file to compress");
        exit(EXIT_FAILURE);
    }
    // update file with .rle extension
    char *output_file_name = input_file_name;
    change_extension(output_file_name, ".rle");
    FILE *compressed_file = fopen(output_file_name, "w");
    if (compressed_file == NULL)
    {
        perror("Could not create compressed file");
        exit(EXIT_FAILURE);
    }
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
            } else if ( (prev_c != '\0') && (prev_c != '\n') ) {
                if(fprintf(compressed_file, "%c%d",prev_c,cnt+1) < 0) {
                    perror("Could not write to compressed file");
                    fclose(file);
                    fclose(compressed_file);
                    exit(EXIT_FAILURE);        
                } 
            cnt = 0;
        } else if (prev_c == '\n') {
            if(fprintf(compressed_file, "%c",prev_c) < 0) {
                perror("Could not write to compressed file");
                fclose(file);
                fclose(compressed_file);
                exit(EXIT_FAILURE);
            }
            cnt = 0;
        }
        else if (prev_c == '\n')
        {
            if (fprintf(compressed_file, "%c", prev_c) < 0)
            {
                perror("Could not write to compressed file");
                fclose(file);
                fclose(compressed_file);
                exit(EXIT_FAILURE);
            }
        }
        prev_c = c;
    }
// Handle the last character after the loop
if (prev_c != '\0' && prev_c != '\n') {
    if (fprintf(compressed_file, "%c%d", prev_c, cnt + 1) < 0) {
        perror("Could not write to compressed file");
        fclose(file);
        fclose(compressed_file);
        exit(EXIT_FAILURE);
    }
    // close files when done
    fclose(file);
    fclose(compressed_file);
    return 0;
