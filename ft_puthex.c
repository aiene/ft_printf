#include "ft_printf.h"

int	ft_puthex(unsigned int n, char format)
{
	int		count;
	char	*hex_lower;
	char	*hex_upper;

	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, format);
	if (format == 'x')
		count += ft_putchar(hex_lower[n % 16]);
	else
		count += ft_putchar(hex_upper[n % 16]);
	return (count);
}

int	ft_puthex_ulong(unsigned long n, char format)
{
	int		count;
	char	*hex_lower;
	char	*hex_upper;

	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_puthex_ulong(n / 16, format);
	if (format == 'x')
		count += ft_putchar(hex_lower[n % 16]);
	else
		count += ft_putchar(hex_upper[n % 16]);
	return (count);
}
