#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("%f\n %D\n", 66666666666.21474568, 100500);
	printf("%f\n %D\n", 66666666666.21474568, 100500);
	return (0);
}