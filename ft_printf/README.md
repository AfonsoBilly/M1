*This project has been created as part of the 42 curriculum by AfonsoBilly.*

# ft_printf

## Description

**ft_printf** is a reimplementation of the standard C library function `printf()`. This project is part of the 42 school curriculum and focuses on understanding variadic functions, type conversion, and formatted output. The implementation handles the most common format specifiers while maintaining compliance with the original printf behavior.

The goal of this project is to create a library (`libftprintf.a`) that provides a custom printf function capable of handling multiple conversion specifiers including characters, strings, pointers, integers (signed and unsigned), and hexadecimal values.

### Key Features
- Handles 9 conversion specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`
- Returns the total number of characters printed
- Proper error handling for NULL pointers and strings
- No buffer management (writes directly to standard output)

## Instructions

### Compilation

To compile the library, run:
```bash
make
```

This will create the `libftprintf.a` static library in the current directory.

### Makefile Rules

The following rules are available:
- `make all` - Compiles the library (default)
- `make clean` - Removes object files
- `make fclean` - Removes object files and the library
- `make re` - Performs fclean followed by all (recompiles everything)

### Usage in Your Project

1. Include the header file in your C source:
```c
#include "ft_printf.h"
```

2. Compile your project with the library:
```bash
cc your_file.c -L. -lftprintf -o your_program
```

Or if you're in a different directory:
```bash
cc your_file.c -L/path/to/ft_printf -lftprintf -I/path/to/ft_printf -o your_program
```

### Example Usage

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "Hello, World!");
    ft_printf("Pointer: %p\n", &main);
    ft_printf("Decimal: %d\n", 42);
    ft_printf("Integer: %i\n", -42);
    ft_printf("Unsigned: %u\n", 4294967295U);
    ft_printf("Hex (lower): %x\n", 255);
    ft_printf("Hex (upper): %X\n", 255);
    ft_printf("Percent: %%\n");
    
    return (0);
}
```

## Resources

### Classic References
- [printf man page](https://man7.org/linux/man-pages/man3/printf.3.html) - Official documentation for the printf family of functions
- [Variadic Functions in C](https://en.cppreference.com/w/c/variadic) - Understanding va_list, va_start, va_arg, and va_end
- [42 Docs - ft_printf](https://harm-smits.github.io/42docs/projects/ft_printf) - Community documentation for the project
- [C Type Conversions](https://en.cppreference.com/w/c/language/conversion) - Understanding implicit and explicit type conversions

### AI Usage

AI tools were used to assist with the following aspects of this project:

1. **Code Structure Planning**: AI helped outline the modular structure of separating each conversion specifier into its own file for better maintainability and clarity.

2. **Edge Case Identification**: AI assisted in identifying important edge cases such as:
   - NULL pointer handling for `%s` (printing "(null)")
   - NULL pointer handling for `%p` (printing "(nil)")
   - INT_MIN handling for signed integers (-2147483648)

3. **Documentation**: AI assisted in creating comprehensive documentation including this README with clear examples and structured sections.

4. **Makefile Optimization**: AI helped ensure the Makefile follows best practices and includes all required rules with proper dependencies.

The core algorithm implementation, logic, and debugging were performed manually to ensure deep understanding of variadic functions and format string parsing.

## Algorithm and Data Structure

### Parsing Approach

The ft_printf function uses a **linear scan parser** that processes the format string character by character:

1. **Main Loop**: Iterates through each character in the format string
2. **Format Detection**: When a `%` character is encountered, the parser advances to check the next character
3. **Specifier Dispatch**: Based on the character following `%`, the appropriate handler function is called
4. **Regular Character Handling**: Non-format characters are printed directly

**Justification**: This approach is chosen for its simplicity and efficiency. It requires only O(n) time complexity where n is the length of the format string, and uses minimal memory (no buffering). The linear scan is optimal for this use case since every character must be examined exactly once.

### Function Dispatch Mechanism

The implementation uses a **conditional dispatch pattern** in the `ft_handle_conversion()` function:

```c
if (specifier == 'c')
    count += ft_print_char(va_arg(args, int));
else if (specifier == 's')
    count += ft_print_str(va_arg(args, char *));
// ... etc
```

**Justification**: While a function pointer array could be used, the conditional approach was chosen because:
- It's more straightforward and easier to understand
- The number of specifiers is small (9 cases)
- Modern compilers optimize conditional chains effectively
- It avoids the complexity of managing function pointer arrays and index mapping

### Conversion Algorithms

#### Integer to String Conversion

Both signed and unsigned integer printing use **recursive digit extraction**:

1. For numbers >= base (10), recursively print higher-order digits first
2. Print the current digit (number % 10)
3. Special case handling for INT_MIN to avoid overflow

**Justification**: Recursion naturally handles digit reversal (we need most significant digits first) without requiring a buffer to store digits. The recursion depth is limited to log₁₀(n), which is at most 10 levels for 32-bit integers.

#### Hexadecimal Conversion

Hexadecimal printing also uses **recursive base-16 conversion**:

1. Select the appropriate digit set (uppercase or lowercase)
2. Recursively print higher-order hex digits (number / 16)
3. Print current hex digit (number % 16)

**Justification**: Same recursive approach as decimal, but with base 16. This keeps the code consistent and maintainable across different number bases.

#### Pointer Printing

Pointer printing combines:
1. NULL check (special case: print "(nil)")
2. Prefix addition ("0x")
3. Hexadecimal conversion of the address value

**Justification**: Pointers are essentially unsigned long integers, so reusing the hexadecimal conversion logic (with a recursive helper) avoids code duplication while handling the pointer-specific formatting requirements.

### Memory and Performance Characteristics

- **Time Complexity**: O(n + m) where n is the format string length and m is the total output length
- **Space Complexity**: O(d) where d is the maximum recursion depth (log₁₀ or log₁₆ of the largest number)
- **No Dynamic Allocation**: The implementation uses only stack memory (recursion) and direct writes
- **No Buffering**: Unlike the standard printf, this implementation writes immediately to stdout

This design prioritizes code clarity and correctness over absolute performance, which is appropriate for an educational project focused on understanding the fundamentals of formatted output.
