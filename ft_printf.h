#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int	ft_printf(const char *format, ...);

int	ft_puthex_ulong(unsigned long n, char format);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putunsigned(unsigned int n);
int	ft_puthex(unsigned int n, char format);
int	ft_putptr(void *ptr);

#endif /* !FT_PRINTF_H */
