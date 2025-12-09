#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}
