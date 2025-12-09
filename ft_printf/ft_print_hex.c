#include "ft_printf.h"

int	ft_print_hex(unsigned int num, int uppercase)
{
	char	*base;
	int		count;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (num >= 16)
		count += ft_print_hex(num / 16, uppercase);
	count += ft_print_char(base[num % 16]);
	return (count);
}
