#include <stdarg.h>
#include <stdio.h>
#include "libft/includes/libft.h"

void minprintf(char *fmt, ...)
{
	va_list	ap;
	char	*p;
	char	*s;
	int		i;
//	double	d;

	va_start(ap, fmt);
	p = fmt;
	while (*p)
	{
		if (*p != '%')
			write(1, p, 1);
		else
		{
			if (*++p == 'd')
			{
				i = va_arg(ap, int);
				ft_putnbr(i);
			}
/*			else if (*p == 'f')
			{
				d = va_arg(ap, double);
				printf("%f", d);
			}
*/
			else if (*p == 's')
			{
				s = va_arg(ap, char *);
				while (*s)
					write(1, s++, 1);
			}
			else
				write(1, p, 1);
		}
		p++;
	}
	va_end(ap);
}

int main(void)
{
	minprintf("digit: %d %s\n", 30, "tis");
	printf("digit: %d %s\n", 30, "tis");
	return (0);
}