*This project has been created as part of the 42 curriculum by adiogo-f.*

## Description

**ft_printf** is a custom implementation of the standard C library function `printf()`. The goal of this project is to recreate the behavior of `printf()` by handling variadic arguments and formatting output to the standard output. 

This implementation supports the following conversions:
- `%c` - Prints a single character
- `%s` - Prints a string
- `%p` - Prints a pointer address in hexadecimal
- `%d` - Prints a decimal number
- `%i` - Prints an integer
- `%u` - Prints an unsigned decimal number
- `%x` - Prints a hexadecimal number (lowercase)
- `%X` - Prints a hexadecimal number (uppercase)
- `%%` - Prints a percent sign

## Instructions

### Compilation

```bash
make        # Compiles the library
make clean  # Removes object files
make fclean # Removes object files and the library
make re     # Recompiles everything
```

### Usage

Include the header and link the library:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "42");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    return (0);
}
```

Compile with:
```bash
cc main.c -L. -lftprintf -o program
```

## Algorithm and Data Structure

### Algorithm Choice

The implementation uses a **linear parsing algorithm** that iterates through the format string character by character: 

1. **Iteration**:  The main loop traverses the format string
2. **Detection**: When a `%` is found, the next character determines the conversion type
3. **Dispatch**: A dispatcher function routes to the appropriate handler based on the specifier
4. **Recursion**: Number conversions use recursion to print digits in correct order

### Why This Approach? 

- **Simplicity**: Single-pass parsing is efficient (O(n) complexity)
- **Modularity**: Each conversion has its own function, making the code maintainable
- **No Buffer**:  Direct `write()` calls avoid buffer management complexity
- **Recursion for Numbers**: Elegant solution to print digits left-to-right without arrays

### Data Structures

- **va_list**: Standard C variadic argument list for handling variable arguments
- **No dynamic allocation**: The implementation avoids `malloc()` for number conversions by using recursion

## Resources

- [printf(3) - Linux Manual Page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Variadic Functions in C](https://en.cppreference.com/w/c/variadic)
- [42 Docs - ft_printf](https://harm-smits.github.io/42docs/projects/ft_printf)

### AI Usage

AI (GitHub Copilot) was used as a learning aid to: 
- Understand the structure and requirements of the project
- Generate initial code templates following 42 Norm
- Explain variadic functions and their usage in C
- Review edge cases (NULL pointers, INT_MIN, etc.)

All code was reviewed and understood before submission.