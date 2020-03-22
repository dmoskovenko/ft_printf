/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 23:04:46 by releanor          #+#    #+#             */
/*   Updated: 2020/03/03 08:23:36 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_print(t_struct *prms, char c, int indent)
{
	if (prms->width > 1 && !prms->minus)
	{
		indent = prms->width - 1;
		{
			while (indent--)
				prms->nprinted_here += (prms->zero \
				&& !prms->precision) ? write(1, "0", 1) : \
				write(1, " ", 1);
		}
	}
	if (c == '\0')
		prms->nprinted_here += write(1, "\0", 1);
	else
		prms->nprinted_here += write(1, &c, 1);
	if (prms->width && prms->minus)
		while (prms->nprinted_here < prms->width)
			prms->nprinted_here += write(1, " ", 1);
	prms->nprinted += prms->nprinted_here;
}

void	type_char(va_list args, t_struct *params)
{
	unsigned char	c;

	c = (unsigned char)va_arg(args, int);
	char_print(params, c, 0);
	bzerostruct(params, 0);
}