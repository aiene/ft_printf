#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	ft_printf("Testing %%d: %d\n", 42);
	ft_printf("Testing %%i: %i\n", 123);
	ft_printf("Testing %%s: %s\n", "Hello");
	ft_printf("Testing %%c: %c\n", 'X');
	ft_printf("Testing %%x: %x\n", 255);
	ft_printf("Testing %%X: %X\n", 255);
	ft_printf("Testing %%u: %u\n", 3000000000);
	ft_printf("Testing %%p: %p\n", (void *)0x12345678);
	ft_printf("Testing %%%%: %%\n");
	ft_printf("Testing NULL pointer: %p\n", (void *)NULL);
	return (0);
}
