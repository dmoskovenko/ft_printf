#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("%F\n%D\n", 66666666666.21474568, 18);
	printf("%F\n%D\n", 66666666666.21474568, 18);
	return (0);
}