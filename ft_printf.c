#include <stdarg.h>
#include <stdio.h>
#include "libft/includes/libft.h"

void ft_printf(const char *fmt, ...)
{
	va_list	args;
	const char	*str;
	char		*s;
	int			d;

	va_start(args, fmt);
	str = fmt;
	while (*str)
	{
		if (*str != '%')
			write(1, str, 1);
		else
		{
			if (*++str == 'd')
			{
				d = va_arg(args, int);
				ft_putnbr(d);
			}
			else if (*str == 's')
			{
				s = va_arg(args, char *);
				while (*s)
					write(1, s++, 1);
			}
			else
				write(1, str, 1);
		}
		str++;
	}
	va_end(args);
}

int main(void)
{
	ft_printf("digit: %d %s\n", 30, "tis");
	printf("digit: %d %s\n", 30, "tis");
	return (0);
}