#include "ft_printf.h"

int print_hexa_upper(unsigned int nb)
{
	char	result;
	int		count;

	count = 0;
	if (nb >= 16)
		count += print_hexa_upper(nb / 16);
	if (nb % 16 <= 9)
	{
		result = '0' + nb % 16;
		count += write(1, &result, 1);
	}
	else
	{
		result = 'A' + (nb % 16 - 10);
		count += write(1, &result, 1);
	}
	return (count);
}

int main(void)
{
	unsigned int add1 = 782356413;
	printf("address 1 is: ");
	fflush(stdout);
	int count = print_hexa_upper(add1);
	printf("character count: %d\n", count);
	return (0);
}
