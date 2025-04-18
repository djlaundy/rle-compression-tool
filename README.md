# rle-compression-tool
Udacity capstone project in C for compressing a .txt file using the .rle algorithm.

---

## Features

- **Compression**: Converts a `.txt` file into a `.rle` file using Run-Length Encoding.
- **Decompression**: Converts a `.rle` file back into its original `.txt` format.
- **Error Handling**: Handles invalid inputs, memory allocation failures, and file I/O errors gracefully.
- **Command-Line Interface**: Simple and intuitive CLI for specifying files to compress or decompress.

---

## Usage

### Command Syntax
```bash
./rle-compression-tool [OPTIONS]
```

### Options
- `-c path/to/file.txt`  
  Compress the specified `.txt` file into a `.rle` file.
  
- `-d path/to/file.rle`  
  Decompress the specified `.rle` file into a `.txt` file.
- `-h`
  Display the help message with usage instructions.

- No arguments: Displays the help message.

---

### Examples

#### Compress a File
```bash
./rle-compression-tool -c input.txt
```
This will create a compressed file named `input.rle` in the same directory.

#### Decompress a File
```bash
./rle-compression-tool -d input.rle
```
This will create a decompressed file named `input.txt` in the same directory.

#### Display Help
```bash
./rle-compression-tool
```

---

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/rle-compression-tool.git
   cd rle-compression-tool
   ```

2. Compile the source code:
   ```bash
   gcc -o rle-compression-tool src/main.c src/compress.c src/decompress.c src/utils.c
   ```

3. Run the tool:
   ```bash
   ./rle-compression-tool
   ```

---

## File Structure

```
rle-compression-tool/
├── src/
│   ├── main.c            # Entry point of the program
│   ├── compress.c        # Handles file compression
│   ├── decompress.c      # Handles file decompression
│   ├── utils.c           # Utility functions (e.g., file handling)
├── header_files/
│   ├── compress.h        # Header for compress.c
│   ├── decompress.h      # Header for decompress.c
│   ├── utils.h           # Header for utils.c
│   ├── constants.h       # Shared constants
├── test_files/           # Example input files for testing
└── README.md             # Project documentation
```

---

## Error Handling

- **Invalid Options**: Displays an error message if invalid options are provided.
- **File Errors**: If a file cannot be opened, the program will display an error message and terminate.
- **Memory Allocation Errors**: If memory allocation fails, the program will terminate with an appropriate error message.

---

## Limitations

- Assumes input files are properly formatted (e.g., `.txt` files for compression, `.rle` files for decompression).

---

## Future Improvements

- Add support for multi-threaded compression and decompression.
- Validate file extensions more robustly.
- Improve error messages for malformed `.rle` files.
- Add unit tests for edge cases.

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
