#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("%ld\n", 2147483647l);
	printf("%ld\n", 2147483647l);
	return (0);
}