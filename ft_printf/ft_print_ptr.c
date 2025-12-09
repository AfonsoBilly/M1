#include "ft_printf.h"

static int	ft_print_hex_recursive(unsigned long num, int uppercase)
{
	char	*base;
	int		count;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (num >= 16)
		count += ft_print_hex_recursive(num / 16, uppercase);
	count += ft_print_char(base[num % 16]);
	return (count);
}

int	ft_print_ptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	count += write(1, "0x", 2);
	count += ft_print_hex_recursive(ptr, 0);
	return (count);
}
