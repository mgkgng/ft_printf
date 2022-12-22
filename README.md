# ft_printf  🎈🖨
## 💁🏻‍♂️ Introduction
The printf function is a widely used function in C for outputting formatted strings. This project is a reimplementation of the printf function that includes support for various conversion specifiers, flags, and the ability to specify width and precision.

As this was my first program that required multiple files, it provided a valuable opportunity to develop skills in organizing and structuring code. In addition, I gained experience in using variadic functions and the va_arg, va_start, and va_end macros for handling a variable number of arguments. I also learned about creating and using static libraries (.a files) and the ar command.

## 📌 Conversion specifiers and flags
Ft_printf allows you to control the output of the function using conversion specifiers and flags. Here is a list of the conversion specifiers and flags that are supported by this reimplementation of printf:

### Conversion specifiers
- c: character
- s: string
- p: pointer address
- d: signed decimal integer
- i: signed decimal integer
- u: unsigned decimal integer
- x: unsigned hexadecimal integer (lowercase)
- X: unsigned hexadecimal integer (uppercase)
- %: percent sign

### Flags
- '-' : left-justify the output
- '0' : pad with zeros if the width is specified
- '.' : specify the precision (number of decimal places for f conversions, or maximum number of characters for s conversions)
- '#' : include the base prefix for o, x, and X conversions
- '+' : include a plus sign for positive numbers
- ' ' : include a space for positive numbers

### Width and precision
The width and precision of the output can be specified by including a number after the % character and before the conversion specifier. The width specifies the minimum number of characters to output, and the precision specifies the number of decimal places for f conversions or the maximum number of characters for s conversions.

For example, to output a floating-point number with a width of 10 and a precision of 3, you can use the following format string: "%10.3f". This will output the number with at least 10 characters, including 3 decimal places.

## 👨🏻‍💻 Usage
To use ft_printf in your own project, follow these steps:

1. Build the libftprintf.a library file by running *make* in the printf project directory.

2. In your own project, include the ft_printf.h header file and link to the libftprintf.a library file. For example:
    
            gcc myprogram.c -Lpath/to/printf/project -o myprogram

3. Call the ft_printf function in your code as you would the standard printf function. Consult the documentation or the source code for a complete list of the available conversion specifiers and flags.
Here is an example of how to use the myprintf function in a program:

    #include "ft_printf.h"

    int main(int argc, char *argv[]) {
        // Print a string
        ft_printf("Hello, world!\n");

        // Print an integer
        ft_printf("The value of argc is %d\n", argc);

        // Print a string with a minimum field width and left-justified
        ft_printf("%-10s\n", "ft_printf");

        return 0;
    }

## 👨🏻‍🎓 History
- November 17, 2021: Project completed
- March 17, 2022: Project reviewed
