/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 23:04:46 by releanor          #+#    #+#             */
/*   Updated: 2020/03/01 16:24:29 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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