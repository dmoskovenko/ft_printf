/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:54:23 by releanor          #+#    #+#             */
/*   Updated: 2020/02/20 09:51:08 by coclayto         ###   ########.fr       */
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

int     conversions(va_list args, char fmt, t_struct params)
{
	if (fmt == 'c')
		type_char(args, params);
/*  else if (c == 's')
        type_string(params, params);
	else if (c == 'p')
	 	type_pointer(params, params, 2);
*/  // will add other types later
    bezerostruct2(params);
    return (params.i);
}

void     type_char(va_list args, t_struct params)
{
	int				num;
	unsigned char	c;

	num = 0;
	c = (unsigned char)va_arg(args, int);
/*
	if (params.width && params.minus == 0)
	{
		num = params.width - 1;
		if (params.zero != 0)
			writezeros(num);
		else if (params.zero == 0)
			writeblanks(num);
		write(1, &c, 1);
		params.nprinted = params.nprinted + num;
	}
	else if (params.width && params.minus == 1)
	{
		num = params.width - 1;
		write(1, &c, 1);
		writeblanks(num);
		params.nprinted = params.nprinted + num;
	}
	else
*/
		write(1, &c, 1);
	params.nprinted++;
}