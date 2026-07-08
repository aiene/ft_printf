#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	int				count;
	char			*hex;

	hex = "0123456789abcdef";
	count = 0;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	addr = (unsigned long)ptr;
	count += ft_putstr("0x");
	if (addr >= 16)
		count += ft_puthex_ulong(addr / 16, 'x');
	count += ft_putchar(hex[addr % 16]);
	return (count);
}
