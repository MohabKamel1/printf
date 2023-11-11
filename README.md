# 0x11. C - printf

## Introduction

This project provides a basic implementation of the printf function in the C programming language. 

## Features

- Supports basic format specifiers: `%d`, `%i`, `%c`, `%s`
- Handles variable arguments using `va_list`, `va_start`, and `va_end`

## How to Use

1. **Clone the repository:**

    ```bash
    git clone https://github.com/AbdalrhmanOmar2002/printf.git
    cd printf
    ```

2. **Compile the source code:**

    ```bash
    gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
    ```

3. **Run the executable:**

    ```bash
    ./printf
    ```


## Functionality

The implementation currently supports the following format specifiers:

- `%d` or `%i`: Integer
- `%c`: Character
- `%s`: String


## Example

```c
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
