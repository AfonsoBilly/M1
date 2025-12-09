#include "ft_printf.h"

static int	ft_print_digit(int n)
{
	char	c;

	c = n + '0';
	return (write(1, &c, 1));
}

int	ft_print_nbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		count += ft_print_nbr(n / 10);
	count += ft_print_digit(n % 10);
	return (count);
}
