
#include "ft_printf. h"

static int	ft_ptr_len(unsigned long long n)
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

static void	ft_put_ptr(unsigned long long n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		ft_put_ptr(n / 16);
	write(1, &hex[n % 16], 1);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long long	addr;
	int					count;

	if (! ptr)
		return (write(1, "(nil)", 5));
	addr = (unsigned long long)ptr;
	count = write(1, "0x", 2);
	ft_put_ptr(addr);
	count += ft_ptr_len(addr);
	return (count);
}