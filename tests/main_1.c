#include "../includes/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
** char	*float_gen(char *res)
** {
** 	int			random;
** 	int			i;
** 	int			n;
** 	int			n2;
** 
** 	i = 0;
** 	srand((unsigned)(time(0)));
** 	n2 = (double)(rand()) / (double)RAND_MAX * 7;
** 	n = (double)(rand()) / (double)RAND_MAX * 7;
** 	if (!(res = (char*)malloc(sizeof(res) * 35)))
** 		return (NULL);
** 	while (i < n)
** 	{
** 		random = (double)(rand()) / (double)RAND_MAX * 9;
** 		res[i++] = random + '0';
** 	}
** 	res[i++] = '.';
** 	while (i < (n + n2 + 1))
** 	{
** 		random = (double)(rand()) / (double)RAND_MAX * 9;
** 		res[i++] = random + '0';
** 	}
** 	return (res);
** }
*/

int		main(void)
{
	int			ret;
	double		dmax;
	long long	i;
	double		arr[COUT + 1];
	int			random;

	i = 0;
	dmax = 1000000;
	srand((unsigned)(time(0)));
	while (i <= COUT)
	{
		random = (double)(rand()) / (double)RAND_MAX * 15;
		arr[i++] = (((double)rand() / ((double)RAND_MAX / dmax)) / random);
/*
** 		arr[i++] = (double)(rand()%25000000 + 1)/(double)1000000;
** 		arr[i++] = (double)((rand() << (15 + rand())) & ((1 << 24) - 1)) / (1 << 24);
** 		res = float_gen(res);
** 		arr[i++] = atof(res);
*/
	}
	i = 0;
	while (i <= COUT)
	{
		ret = printf("%f\n", arr[i++]);
		printf("%d\n", ret);
	}
	return (0);
}