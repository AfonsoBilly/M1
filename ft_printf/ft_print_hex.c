
#include "ft_printf.h"

static int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static void	ft_put_hex(unsigned int n, int uppercase)
{
	char	*hex;

	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
		ft_put_hex(n / 16, uppercase);
	write(1, &hex[n % 16], 1);
}

int	ft_print_hex(unsigned int n, int uppercase)
{
	ft_put_hex(n, uppercase);
	return (ft_hex_len(n));
}