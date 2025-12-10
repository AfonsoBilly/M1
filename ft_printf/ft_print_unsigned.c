
#include "ft_printf. h"

static int	ft_unsigned_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_put_unsigned(unsigned int n)
{
	char	c;

	if (n >= 10)
		ft_put_unsigned(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	ft_print_unsigned(unsigned int n)
{
	ft_put_unsigned(n);
	return (ft_unsigned_len(n));
}