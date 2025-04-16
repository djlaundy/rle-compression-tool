/* Include any necessary libraries and header files */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../header_files/constants.h"
#include "../header_files/compress.h"
#include "../header_files/decompress.h"
#include "../header_files/utils.h"

char* compress_file = NULL; // Define variable for file to compress 
char* decompress_file = NULL; // define variable for file to decompress 

void print_help(const char *program_name)
{
    printf("Usage: %s [OPTIONS]\n", program_name);
    printf("Options:\n");
    printf("  -c path/to/file.txt    A file to compress (must be a .txt file)\n");
    printf("  -b path/to/file.rle    A file to decompress (must be a .rle)\n");
}

void cleanup(){
    free_pointer(compress_file);
    free_pointer(decompress_file);
}

int main(int argc, char *argv[])
{
    atexit(cleanup);
    int opt; // Variable to store the option
    if (argc == 1)
    {
        print_help(argv[0]);
        return 0; // Exit with success
    }
    int compress_flag = 0;   // Flag for compression
    int decompress_flag = 0; // Flag for decompression
    // Loop through options
    while ((opt = getopt(argc, argv, "c:d:")) != -1) {
        switch (opt) {
            case 'c':
                if (optarg) {
                    printf("Option -c with value: %s\n", optarg);
                    compress_flag = 1; // Set compression flag
                    compress_file = malloc(strlen(optarg) + 1); // Reallocate the correct amount of memory
                    if (compress_file == NULL) {
                        perror("Memory allocation failed for compress_file: ");
                        exit(EXIT_FAILURE);
                    }
                    strcpy(compress_file,optarg);
                } else {
                    printf("For -c option please provide a relative path to a .txt file.\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case 'd':
            if (optarg) {
                    printf("Option -d with value: %s\n", optarg);
                    decompress_flag = 1; // Set decompression flag
                    decompress_file = malloc(strlen(optarg) + 1); // Reallocate the correct amount of memory
                    if (decompress_file == NULL) {
                        perror("Memory allocation failed for decompress_file: ");
                        exit(EXIT_FAILURE);
                    }
                    strcpy(decompress_file,optarg);
            } else {
                printf("For -d option please provide a relative path to a .rle file.\n");
                exit(EXIT_FAILURE);
            }
                break;
            case '?':
                printf("Unknown option: -%c\n", optopt);
                exit(EXIT_FAILURE);
                break;
        }}
    if (decompress_flag && compress_flag) {
        printf("Error: Cannot use both -c and -d options at the same time.\n");
        exit(EXIT_FAILURE);
    }
    if (compress_flag) {
        int compress_result = compress(compress_file);
        if (compress_result != 0) {
            printf("Error compressing file: %s\n", compress_file);
            exit(EXIT_FAILURE);
        }
    } else if (decompress_flag) {
        int decompress_result = decompress(decompress_file);
        if (decompress_result != 0) {
            printf("Error decompressing file: %s\n", decompress_file);
            exit(EXIT_FAILURE);
        }
    }
    return 0;
