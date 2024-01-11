ft_printf will should display the same outcome as printf - to print formatted text to the standard output stream:
example: ("hello %s, your number is %d\n", "mooncake", 42);
the function will check the input string, if it encounters a % sign literal, then it will check the next index for the specifier && call the corresponding function to handle each case:
  %c: character --> ft_putchar (or write)
  %s: string --> ft_putstr
  %d, %i: decimal (base 10) --> ft_putnb
  %u: unsigned integer -->ft_putnb_unsigned
  %x: hexadecimal (lowercase)--> print_hexa_lower
  %X: hexadecimal (uppercase)--> print_hexa_upper
  %: a percent sign literal --> ft_putchar
if it encounters anything else, just write each character to the output (ft_putchar)
the returned value is the number of written characters
