#include "ft_printf.h"

long double		power(long long n, int i)
{
	long long	j;
	long double	res;

	j = 0;
	res = n;
	if (!i)
		return (1);
	while (j++ < (i - 1))
		res *= n;
	return (res);
}