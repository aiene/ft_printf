#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int		count;
	char	digit;

	count = 0;
	if (n >= 10)
		count += ft_putunsigned(n / 10);
	digit = (n % 10) + '0';
	count += ft_putchar(digit);
	return (count);
}
