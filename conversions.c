/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:54:23 by releanor          #+#    #+#             */
/*   Updated: 2020/02/19 17:58:28 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	conversions(char c, va_list params, t_struct *new_struct)
{
	if (c == 'c')
		type_char(new_struct, params);
	// else if (c == 's')
	// 	type_string(new_struct, params);
	// else if (c == 'p')
	// 	type_pointer(new_struct, params, 2);

	// will add other types later
}

void	type_char(t_struct *new_struct, va_list params)
{
	int				num;
	unsigned char	c;

	num = 0;
	c = (unsigned char)va_arg(params, int);
	if (new_struct->width && new_struct->minus == 0)
	{
		num = new_struct->width - 1;
		if (new_struct->zero != 0)
			writezeros(num);
		else if (new_struct->zero == 0)
			writeblanks(num);
		write(1, &c, 1);
		new_struct->nprinted = new_struct->nprinted + num;
	}
	else if (new_struct->width && new_struct->minus == 1)
	{
		num = new_struct->width - 1;
		write(1, &c, 1);
		writeblanks(num);
		new_struct->nprinted = new_struct->nprinted + num;
	}
	else
		write(1, &c, 1);
	new_struct->nprinted++;
}
