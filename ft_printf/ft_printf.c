#include "ft_printf.h"

static int	ft_handle_conversion(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (specifier == 'p')
		count += ft_print_ptr(va_arg(args, unsigned long));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_nbr(va_arg(args, int));
	else if (specifier == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (specifier == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), 1);
	else if (specifier == '%')
		count += ft_print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += ft_handle_conversion(format[i], args);
		}
		else if (format[i] != '%')
			count += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
