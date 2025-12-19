# Get Next Line

### This project has been created as part of the 42 curriculum by adiogo-f.
Description
Get Next Line is a function that reads and returns a line from a file descriptor. This project teaches fundamental concepts of file I/O operations, static variables, and memory management in C. The function must handle multiple file descriptors simultaneously and work efficiently with various buffer sizes.
The main goal is to implement a function that can read a text file line by line, where each call to get_next_line() returns the next line from the file until the end is reached. This is a common operation in programming and forms the basis for understanding how standard input/output functions work under the hood.
Instructions
Compilation
Compile the project with your desired buffer size:
bashcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl_test
You can adjust the BUFFER_SIZE value to any positive integer. The function must work correctly with various buffer sizes (1, 42, 9999, 10000000, etc.).
Files Structure

get_next_line.c - Main function implementation
get_next_line_utils.c - Helper functions
get_next_line.h - Header file with prototypes and definitions

Function Prototype
cchar *get_next_line(int fd);
Usage Example
c#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
Key Requirements

Returns one line at a time, including the terminating \n character
Returns NULL when there's nothing left to read or an error occurs
Works with files and standard input
Must handle multiple file descriptors without mixing data
No use of lseek() or global variables
Memory must be properly managed (no leaks)

Algorithm Explanation
The algorithm selected for this project uses a static buffer with leftover management approach. Here's how it works:
Core Strategy

Static Variable for Persistence: A static variable stores leftover data between function calls. This is crucial because when we read from a file descriptor, we might read more than one line at a time. The excess data needs to be preserved for the next call.
Read-Parse-Store Cycle:

Check if there's leftover data from the previous call
If a complete line exists in the leftover, extract and return it
Otherwise, read more data from the file descriptor
Append new data to existing leftovers
Search for newline character (\n)
Extract the line up to and including \n
Save remaining data for the next call


Memory Management:

Each line returned is dynamically allocated
The static buffer is reallocated as needed when reading new chunks
All memory is freed when reaching EOF or encountering an error



Why This Algorithm?
This approach was chosen because:

Efficiency: Minimizes the number of read() system calls by reading in chunks (BUFFER_SIZE) rather than byte-by-byte
Simplicity: The static variable naturally maintains state between calls without complex data structures
Flexibility: Works with any buffer size from 1 to very large values
Memory Optimization: Only allocates memory for the actual line being returned, not the entire file

Edge Cases Handled

Files ending without a newline character
Empty files
Very long lines (larger than BUFFER_SIZE)
Very small buffer sizes (BUFFER_SIZE = 1)

# get_next_line

> 42cursus project by **adiogo-f**

---

## 📚 Description

`get_next_line` is a function that reads and returns a line from a file descriptor. It teaches fundamental concepts of file I/O, static variables, and memory management in C. The function must handle multiple file descriptors and work efficiently with any buffer size.

---

## 🚀 Compilation

Compile with your desired buffer size:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl_test
```

You can adjust `BUFFER_SIZE` to any positive integer (1, 42, 9999, 10000000, etc.).

---

## 📂 File Structure

- `get_next_line.c` — Main function implementation
- `get_next_line_utils.c` — Helper functions
- `get_next_line.h` — Header file with prototypes and definitions

---

## 📝 Function Prototype

```c
char *get_next_line(int fd);
```

---

## 💡 Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

---

## ✅ Key Requirements

- Returns one line at a time, including the terminating `\n`
- Returns `NULL` when there's nothing left to read or on error
- Works with files and standard input
- Handles multiple file descriptors without mixing data
- No use of `lseek()` or global variables
- No memory leaks

---

## ⚙️ Algorithm Overview

The algorithm uses a static buffer with leftover management:

1. **Static Variable for Persistence:** Stores leftover data between calls.
2. **Read-Parse-Store Cycle:**
    - Check for leftover data
    - If a complete line exists, extract and return it
    - Otherwise, read more data
    - Append new data to leftovers
    - Search for `\n`, extract the line, save remaining data
3. **Memory Management:**
    - Each line is dynamically allocated
    - All memory is freed at EOF or error

---

## 🧠 Why This Algorithm?

- **Efficiency:** Minimizes `read()` calls by reading in chunks
- **Simplicity:** Static variable maintains state between calls
- **Flexibility:** Works with any buffer size
- **Memory Optimization:** Allocates only for the line being returned

---

## 🛡️ Edge Cases Handled

- Files ending without a newline
- Empty files
- Very long lines (larger than `BUFFER_SIZE`)
- Very small buffer sizes (`BUFFER_SIZE = 1`)
- Multiple file descriptors read alternately
- Read errors or invalid file descriptors

---

## 📚 Resources

- [Linux man pages - read(2)](https://man7.org/linux/man-pages/man2/read.2.html)
- [Linux man pages - malloc(3)](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [Static variables in C](https://en.cppreference.com/w/c/language/storage_duration)

---

## 🧪 Testing

Test your implementation with:
- Different buffer sizes (1, 42, 1000, 10000000)
- Various file types (empty, no final newline, very long lines)
- Multiple file descriptors
- Standard input
- Invalid file descriptors

---

> **Note:** This implementation strictly follows 42 School's Norm and coding standards.