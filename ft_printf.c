#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	if (!format)
		return (-1);
	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			count += ft_putchar(format[i]);
			i++;
		}
		else
		{
			i++;
			if (format[i] == 'd' || format[i] == 'i')
				count += ft_putnbr(va_arg(args, int));
			else if (format[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (format[i] == 'c')
				count += ft_putchar(va_arg(args, int));
			else if (format[i] == 'p')
				count += ft_putptr(va_arg(args, void *));
			else if (format[i] == 'x')
				count += ft_puthex(va_arg(args, unsigned int), 'x');
			else if (format[i] == 'X')
				count += ft_puthex(va_arg(args, unsigned int), 'X');
			else if (format[i] == 'u')
				count += ft_putunsigned(va_arg(args, unsigned int));
			else if (format[i] == '%')
				count += ft_putchar('%');
			i++;
		}
	}
	va_end(args);
	return (count);
}