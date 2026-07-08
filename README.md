# ft_printf

*This project has been created as part of the 42 curriculum.*

## Description

`ft_printf` is a recreation of the standard C library function `printf()`. This project helps you discover fundamental building blocks of C programming, particularly:

- **Variadic functions**: Functions that accept a variable number of arguments using `va_start`, `va_arg`, and `va_end` macros.
- **Format string parsing**: Processing and interpreting format specifiers.
- **Type conversions**: Converting different data types to their string representations.
- **String output**: Using the `write()` system call for low-level output.

The implementation handles all essential format specifiers and demonstrates proper code structure, error handling, and memory management without buffer management complexity.

## Instructions

### Compilation

```bash
make
```

This will create `libftprintf.a` at the root of the repository.

### Linking

To use `ft_printf` in your projects:

```bash
cc -c main.c -o main.o
cc main.o -L. -lftprintf -o program
./program
```

Or compile with the library directly:

```bash
cc main.c -L. -lftprintf -o program -Ift_printf.h
```

### Supported Format Specifiers

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string (handles NULL as "(null)") |
| `%p` | Prints a pointer in hexadecimal format with `0x` prefix (NULL as "(nil)") |
| `%d` | Prints a decimal (base 10) integer |
| `%i` | Prints an integer in base 10 |
| `%u` | Prints an unsigned decimal (base 10) number |
| `%x` | Prints a number in lowercase hexadecimal (base 16) |
| `%X` | Prints a number in uppercase hexadecimal (base 16) |
| `%% ` | Prints a percent sign |

### Example Usage

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("String: %s\n", "Hello");
    ft_printf("Number: %d\n", 42);
    ft_printf("Character: %c\n", 'A');
    ft_printf("Hex (lower): %x\n", 255);
    ft_printf("Hex (upper): %X\n", 255);
    ft_printf("Pointer: %p\n", (void *)0x1234);
    ft_printf("Percent: %%\n");
    return 0;
}
```

### Cleanup

```bash
make clean    # Remove object files
make fclean   # Remove object files and library
make re       # Rebuild everything
```

## Algorithm and Data Structure

### Architecture

The implementation uses a modular design with helper functions:

1. **Main Parser** (`ft_printf`): Iterates through the format string, identifies format specifiers (%), and dispatches to appropriate handlers.

2. **Type-Specific Handlers**:
   - `ft_putchar()`: Outputs a single character
   - `ft_putstr()`: Outputs a string with NULL safety
   - `ft_putnbr()`: Converts integers to decimal recursively
   - `ft_putunsigned()`: Handles unsigned integers
   - `ft_puthex()`: Converts to hexadecimal (recursive approach)
   - `ft_putptr()`: Formats pointer addresses

### Design Choices

**Recursive Conversion**: Number-to-string conversion uses recursion:
```c
// Converts number digit by digit from most significant to least
if (n >= 10)
    ft_putnbr(n / 10);  // Recursive call for remaining digits
digit = (n % 10) + '0'; // Current digit
```

**Advantages**:
- Clean and elegant code
- Natural digit extraction from most significant digit
- No need for temporary buffers or string reversal
- Stack depth proportional to number of digits

**Return Value Tracking**: Each helper function returns the character count, enabling the main function to accumulate and return the total printed character count (matching `printf` behavior).

**Variadic Arguments**: Uses standard C variadic macros:
- `va_start()`: Initializes the argument list
- `va_arg()`: Extracts next argument of specified type
- `va_end()`: Cleans up the argument list

**Direct Output**: Uses `write(1, ...)` for immediate output to stdout without internal buffering, simplifying the implementation.

## Resources

### Documentation
- [C Variadic Functions (stdarg.h)](https://en.cppreference.com/w/c/variadic)
- [Printf Format Specifiers](https://www.cplusplus.com/reference/cstdio/printf/)
- [Write System Call](https://man7.org/linux/man-pages/man2/write.2.html)
- [AR Command](https://man7.org/linux/man-pages/man1/ar.1.html)

### References
- The C Programming Language (Kernighan & Ritchie)
- System Programming with C (Linux)

### How AI Was Used

AI was used for:
- **Code review and optimization**: Verifying algorithm correctness and edge case handling
- **Documentation**: Structuring this README and explaining design choices
- **Format specifier reference**: Listing all supported conversions and their behaviors

AI was NOT used for:
- Writing the core implementation directly
- Solving the problem mechanically
- Skipping the learning process

The implementation reflects genuine understanding of variadic functions and C programming fundamentals.

## Author

Created as part of 42 School curriculum.
