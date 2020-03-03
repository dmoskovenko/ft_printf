/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:54:23 by releanor          #+#    #+#             */
/*   Updated: 2020/03/03 04:54:53 by coclayto         ###   ########.fr       */
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
/*
	else if (c == 's' || spec == 'S')
		type_string(params, params);
	else if (c == 'p' || spec == 'P')
		type_pointer(params, params, 2);
*/
	else if (spec == 'd' || spec == 'i' || spec == 'D' || spec == 'I')
		type_int(args, params);
	else if (spec == 'f' || spec == 'F')
		type_float(args, params);
	bzerostruct(params, 0);
	return (params->i);
}
