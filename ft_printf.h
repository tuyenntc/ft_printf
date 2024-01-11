#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnb(int nb);
int		ft_putnb_unsigned(unsigned int nb);
int		print_hexa_lower(unsigned int nb);
int		print_hexa_upper(unsigned int nb);
int		print_pointer(unsigned long long nb);


#endif
