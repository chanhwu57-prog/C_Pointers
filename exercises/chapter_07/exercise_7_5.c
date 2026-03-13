#include <stdio.h>
#include <stdarg.h>

void my_printf(char *format, ...) {
    va_list args;
    va_start(args, format);
    
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'd': {
                    int val = va_arg(args, int);
                    printf("%d", val);
                    break;
                }
                case 'f': {
                    double val = va_arg(args, double);
                    printf("%f", val);
                    break;
                }
                case 's': {
                    char *val = va_arg(args, char *);
                    printf("%s", val);
                    break;
                }
                case 'c': {
                    int val = va_arg(args, int);
                    putchar(val);
                    break;
                }
                case '%':
                    putchar('%');
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    break;
            }
        } else {
            putchar(*format);
        }
        format++;
    }
    
    va_end(args);
}

int main(void) {
    my_printf("Integer: %d\n", 42);
    my_printf("Float: %f\n", 3.14159);
    my_printf("String: %s\n", "Hello, World!");
    my_printf("Char: %c\n", 'A');
    my_printf("Mixed: %d, %f, %s, %c\n", 100, 2.5, "test", 'X');
    my_printf("Percent sign: %%\n");
    
    return 0;
}
