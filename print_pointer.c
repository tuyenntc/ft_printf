#include "ft_printf.h"

/*
static int print_hex_digit(uintptr_t nb)
{
	char	result;
	int		count;
	count = 0;
	if (nb <= 9)
		result = '0' + nb;
	else
		result = 'a' + (nb - 10);
	count += write(1, &result, 1);
	return (count);
}

static int print_pointer(uintptr_t nb)
{
	int	count;

	count = 0;
	if (nb >=16)
		count += print_pointer(nb / 16);
	count += print_hex_digit(nb % 16);
	return (count);
}
*/

static int convert_pointer(unsigned long long nb)
{
	char	result;
	int		count;

	count = 0;
	if (nb >= 16)
		count += convert_pointer(nb / 16);
	if (nb % 16 <= 9)
	{
		result = '0' + nb % 16;
		count += write(1, &result, 1);
	}
	else if (nb % 16 < 16)
	{
		result = 'a' + (nb % 16 - 10);
		count += write(1, &result, 1);
	}
	return (count);
}

int print_pointer(unsigned long long nb)
{
	if (nb == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (2 + convert_pointer(nb));
}
/*
int main(void)
{
	unsigned long long address1 = 0x12345678;
	uintptr_t address2 = 0;

//	printf("address 1 is: ");
//	fflush(stdout);
	int count1 = print_pointer(address1);
	printf("\n character count: %d\n", count1);
	return (0);
}
*/
