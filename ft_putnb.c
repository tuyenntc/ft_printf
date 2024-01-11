#include "ft_printf.h"

int ft_putnb(int nb)
{
	char	result;
	int		count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnb(nb / 10);
	result = '0' + nb % 10;
	count += write(1, &result, 1);
	return (count);
}

/*
int main(void)
{
	int num1 = 392;
	int num2 = 555;
	printf("lib values %d %i\n", num1, num2);

	ft_putnb(num1);
	printf("\n");
	ft_putnb(num2);
	printf("\n");
	return (0);
}
*/
