/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:54:23 by releanor          #+#    #+#             */
/*   Updated: 2020/03/02 13:47:34 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
void	writezeros(int n)
{
	while (n > 0)
	{
		write(1, "0", 1);
		n--;
	}
}

void	writeblanks(int n)
{
	while (n > 0)
	{
		write(1, " ", 1);
		n--;
	}
}
*/

int     conversions(va_list args, char spec, t_struct params)
{
	if (spec == 'c')
		type_char(args, params);
/*
	else if (c == 's')
        type_string(params, params);
	else if (c == 'p')
	 	type_pointer(params, params, 2);
*/
	else if (spec == 'd' || spec == 'i')
		type_int(args, params);
	else if (spec == 'o')
		type_oct(args, params);	

    bzerostruct(params, 0);
    return (params.i);
}
