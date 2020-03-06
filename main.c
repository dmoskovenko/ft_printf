#include "includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int			ret;
	int			ret_ft;

	ret = printf("%f\n", 0.682581);
	printf("%d\n", ret);
	ret_ft = ft_printf("%f\n", 0.682581);
	ft_printf("%d\n", ret);
	return (0);
}