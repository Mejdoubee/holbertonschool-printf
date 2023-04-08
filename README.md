# Custom Printf Implementation

This project is an implementation of the C standard library function `printf()`. The custom implementation, called `_printf()`, can handle several format specifiers for outputting text, numbers, and other data types.

## Supported Format Specifiers

The following format specifiers are supported:

- `%c`: Character
- `%s`: String
- `%i`, `%d`: Signed decimal integer
- `%u`: Unsigned decimal integer
- `%o`: Unsigned octal
- `%x`: Unsigned hexadecimal (lowercase)
- `%X`: Unsigned hexadecimal (uppercase)
- `%b`: Unsigned binary

## Usage

Include the header file `main.h` in your C source file, and compile the source files together. Then, you can use the `_printf()` function similarly to how you would use the standard `printf()` function.

Example:

```c
#include "main.h"

int main(void)
{
    _printf("Hello, %s!\n", "world");
    _printf("Number of bytes: %d\n", 1024);
    _printf("Unsigned integer: %u\n", 12345);
    _printf("Octal: %o\n", 12345);
    _printf("Hexadecimal: %x\n", 12345);
    _printf("Binary: %b\n", 12345);
    return 0;
}

