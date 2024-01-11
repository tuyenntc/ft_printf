#include "ft_printf.h"

int ft_putnb_unsigned(unsigned int nb)
{
	char	result;
	int		count;

	count = 0;
	if (nb >= 10)
		count += ft_putnb_unsigned(nb / 10);
	result = '0' + nb % 10;
	count += write(1, &result, 1);
	return (count);
}
