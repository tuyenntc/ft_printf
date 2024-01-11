/*
cspdiuxX%: placeholder, specifier

*/
#include "ft_printf.h"

static void	check_format(const char *format, va_list args, int *result)
{
	char	spec = format[0];

	if (spec == 'c')
		*result += ft_putchar(va_arg(args, int));
	else if (spec == 's')
		*result += ft_putstr(va_arg(args, char *));
	else if (spec == 'd' || spec == 'i')
		*result += ft_putnb(va_arg(args, int));
	else if (spec == 'u')
		*result += ft_putnb_unsigned(va_arg(args, unsigned int));
	else if (spec == 'x')
		*result += print_hexa_lower(va_arg(args, unsigned int));
	else if (spec == 'X')
		*result += print_hexa_upper(va_arg(args, unsigned int));
	else if (spec == 'p')
		*result += print_pointer(va_arg(args, unsigned long long));
	else if (spec == '%')
		*result += ft_putchar('%');
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int		result;

	result = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
			check_format(++format, args, &result);
		else
		{
			ft_putchar(*format);
			result++;
		}
		format++;
	}
	va_end(args);
	return (result);
}

int main(void) {
    void *pointer = (void *)0xb8000000;

    printf("lib: %c | %c | %c\n", 'z', 42, ' ');
    ft_printf("mine: %c | %c | %c\n", 'z', 42, ' ');

    printf("lib: %s\n", "this is a string");
    ft_printf("mine: %s\n", "this is a string");

    printf("lib: %x\n", 0x7fa);
    ft_printf("mine: %x\n", 0x7fa);

    printf("lib: %X\n", 0x7FA);
    ft_printf("mine: %X\n", 0x7FA);

    printf("lib: %d | %i | %li | %i\n", -2, 555, -2147483648, 2147483647);
    ft_printf("mine: %d | %i | %li | %i\n", -2, 555, -2147483648, 2147483647);

    printf("lib: %u\n", 7235);
    ft_printf("mine: %u\n", 7235);

    printf("lib: pointer (memory address) %p\n", pointer);
    ft_printf("mine: pointer (memory address) %p\n", pointer);

    printf("lib percent sign literal: %%\n");
    ft_printf("my percent sign literal: %%\n");

    return 0;
}
