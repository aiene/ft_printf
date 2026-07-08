#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		count;
	char	digit;
    long	nb;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	digit = (nb % 10) + '0';
	count += ft_putchar(digit);
	return (count);
}
