#include "../includes/ft_printf.h"
#include "../gnl/get_next_line.h"
#include <stdio.h>

int		main(void)
{
	int			fd;
	int			ret_gnl;
	int			ret_ft;
	char		*line;
	long long	i;
	long long	j;
	long long	k;
	double		arr[COUT + 1];
	
	i = 0;
	j = 0;
	k = 0;
 	if((fd = open("tests/printf_out", O_RDWR)) < 0)
 		printf("Cannot create printf_out");
	while (i <= (COUT * 2) && (ret_gnl = get_next_line(fd, &line)) == 1)
	{
		if(!(k = i % 2) || i == 0)
			arr[j++] = atof(line);
		i++;
	}
	i = 0;
	while (i <= COUT)
	{
		ret_ft = ft_printf("%f\n", arr[i++]);
		ft_printf("%d\n", ret_ft);
	}
	close(fd);
	return (0);
}