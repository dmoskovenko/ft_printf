#include "ft_printf.h"

/*
** int				is_nan(long double nb)
** {
** 	return (!(nb == nb));
** }
** 
** int				is_inf(long double nb)
** {
** 	if (nb == (1.0 / 0.0) || nb == -(1.0 / 0.0))
** 		return (1);
** 	else
** 		return (0);
** }
*/

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