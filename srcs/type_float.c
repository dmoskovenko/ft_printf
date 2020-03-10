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

void		float_print(t_struct *params)
{
	int len;
	int	indent;

	indent = 0;
	if (params->width > params->len)
		indent = params->width - params->len;
	if (params->negative || params->plus || params->space)
		indent--;
	if (params->width > params->len && !params->minus)
	{
		while(indent--)
		{
			if (params->zero)
				params->nprinted += write(1, "0", 1);
			else
				params->nprinted += write(1, " ", 1);
		}
	}
	if (params->negative)
		params->nprinted += write(1, "-", 1);
	if (params->plus)
		params->nprinted += write(1, "+", 1);
	if (params->space && !params->negative)
		params->nprinted += write(1, " ", 1);
//	params->nprinted += ft_strlen(itoa_base_unsigned(params->fbefore, 10));
	ft_putnbr(params->fbefore);
	params->nprinted += unsigned_num_len(params->fbefore, 10);
	if (params->hash || params->precision)
		params->nprinted += write(1, ".", 1);
	if(params->precision)
	{
/*		params->nprinted += write(1, ".", 1);*/

		len = ft_strlen(params->fstr);
		params->nprinted += len;
		while (len++ < params->precision)
			params->nprinted += write(1, "0", 1);
//		params->nprinted += len;
		ft_putstr(params->fstr);
	}
	if (params->width && params->minus)
	while(params->nprinted < params->width)
		params->nprinted += write(1, " ", 1);
}

void		float_math(long double num, t_struct *params)
{
	int			i;
	long long	buf;
	long double	fbuf;
	long double fpower;

	i = 0;
	params->fdecimal = num - params->fbefore;
	fbuf = params->fdecimal;
	fpower = power(10, params->precision);
	params->fdecimal *= fpower;
	buf = params->fdecimal * 10;
/*
** 	fbuf =+ (params->fstr[i]) - '0';
*/
	if ((buf % 10) >= 5)
		params->fdecimal += 0.5;
	params->fafter = params->fdecimal;
	if ((int)params->fdecimal == fpower)
	{
		params->fbefore++;
		params->fafter = 0;
	}
	params->fstr = itoa_base_unsigned(params->fafter, 10);
	params->len = unsigned_num_len(params->fbefore, 10);
	if (params->precision != 0)
		params->len += ft_strlen(params->fstr) + 1;
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

void		type_float(va_list args, t_struct *params)
{
	long double num;
	int			negative;

	negative = 0;
//	params->precision = 1;
	if (params->length == LONG)
		num = (double)va_arg(args, double);
	if (params->length == LONGDOUBLE)  
		num = (long double)va_arg(args, long double);
	if (params->length == 0)
		num = (double)va_arg(args, double);
	if (is_nan(num) || is_inf(num))
	{
		params->hash = 0;
		params->zero = 0;
		if (is_inf(num))
		{
			params->nprinted = write(1, "inf", 3);
			return;
		}
		if (is_nan(num))
		{
			params->plus = 0;
			params->nprinted = write(1, "nan", 3);
			return;
		}
	}
	if (!params->precision && !params->precisionzero)
		params->precision = 6;
	if (num < 0)
	{
		params->negative++;
		num *= -1;
	}
	params->fbefore = num;
	float_math(num, params);
	float_print(params);
	return;
} 