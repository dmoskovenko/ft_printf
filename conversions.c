/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:54:23 by releanor          #+#    #+#             */
/*   Updated: 2020/03/06 14:33:58 by releanor         ###   ########.fr       */
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

int		conversions(va_list args, char spec, t_struct *params)
{
	if (spec == 'c' || spec == 'C')
		type_char(args, params);
	if (spec == 's' || spec == 'S')
		type_str(args, params);
/*
	else if (c == 'p' || spec == 'P')
		type_pointer(params, params, 2);
*/
	else if (spec == 'd' || spec == 'i' || spec == 'D' || spec == 'I')
		type_int(args, params);
	else if (spec == 'u' || spec == 'U')
		type_u(args, params);
	else if (spec == 'x' || spec == 'X')
		type_hex(args, params, spec);
	else if (spec == 'f' || spec == 'F')
		type_float(args, params);
	else if (spec == 'o' || spec == 'O')
		type_oct(args, params);
	else
	bzerostruct(params, 0);
	return (params->i);
}
