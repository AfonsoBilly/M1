#include "ft_printf.h"

static int	ft_print_digit(unsigned int n)
{
	char	c;

	c = n + '0';
	return (write(1, &c, 1));
}

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_unsigned(n / 10);
	count += ft_print_digit(n % 10);
	return (count);
}
