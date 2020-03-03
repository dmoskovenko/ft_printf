/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 07:27:41 by coclayto          #+#    #+#             */
/*   Updated: 2020/03/03 08:06:06 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		float_math(long double num, t_struct *params)
{
	int			i;
	long double buf;

	i = 0;
	buf = num - params->fdecimal;
	while (i < params->precision)
	{
		buf *= 10;
		i++;
	}
	if (params->length >= i)
	{
		
	}
}

t_struct	*type_float(va_list args, t_struct *params)
{
	long double num;

	if (params->length == LONG)
		num = (double)va_arg(args, double);
	if (params->length == LONGDOUBLE)  
		num = (long double)va_arg(args, long double);
	if (params->length == 0)
		num = (double)va_arg(args, double);
	if (!params->precision)
		params->precision = 6;
	params->fdecimal = num;
	ft_putnbr((long)num);
	write(1, ".", 1);
	float_math(num, params);
	ft_putstr(params->fres);
	return (params);
}