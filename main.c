#include "ft_printf.h"

int main(void)
{
	ft_printf("String: %s\n", "Hello");
	ft_printf("Number: %d\n", 42);
	ft_printf("Character: %c\n", 'A');
	ft_printf("Hex (lower): %x\n", 255);
	ft_printf("Hex (upper): %X\n", 255);
	ft_printf("Unsigned: %u\n", 3000000000);
	ft_printf("Pointer: %p\n", (void *)0x1234);
	ft_printf("Percent: %%\n");
	ft_printf("Mixed: %d + %s = %c\n", 1, "test", 'X');
	return (0);
}
