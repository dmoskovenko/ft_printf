#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("%F\n", 66666666666.21474568);
	printf("%F\n", 66666666666.21474568);
	return (0);
}