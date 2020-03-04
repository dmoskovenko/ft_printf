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
	int			len;
	long long	buf;
	

	i = 0;
	params->fdecimal = num - params->fbefore;
	while (i++ < params->precision)
		params->fdecimal *= 10;
	buf = params->fdecimal * 10;
	if ((buf % 10) >= 5)
		params->fdecimal += 0.5;
	params->fafter = params->fdecimal;
	params->fstr = itoa_base_unsigned(params->fafter, 10);
	len = ft_strlen(params->fstr);
	while (len++ < params->precision)
		write(1, "0", 1);

/*
** 	if (params->precision >= i)
** 	{
** 		params->fdecimal = decimal;
** 		params->fafter = ft_itoa(params->fdecimal);
** 		if (params->fafter[i - 1] == 5)
** 
** 	}
*/
}

t_struct	*type_float(va_list args, t_struct *params)
{
	long double num;

//	params->precision = 1;
	if (params->length == LONG)
		num = (double)va_arg(args, double);
	if (params->length == LONGDOUBLE)  
		num = (long double)va_arg(args, long double);
	if (params->length == 0)
		num = (double)va_arg(args, double);
	if (!params->precision)
		params->precision = 6;
	params->fbefore = num;
	ft_putnbr(params->fbefore);
	write(1, ".", 1);
	float_math(num, params);
	ft_putstr(params->fstr);
	return (params);
}