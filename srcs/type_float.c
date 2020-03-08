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

static int			is_nan(long double nb)
{
	return (!(nb == nb));
}

static int			is_inf(long double nb)
{
	if (nb == (1.0 / 0.0) || nb == -(1.0 / 0.0))
		return (1);
	else
		return (0);
}

long double		power(long long n, int i)
{
	long long	j;
	long double	res;

	j = 0;
	res = n;
	if (!i)
		return (1);
	while (j++ < (i - 1))
		res *= n;
	return (res);
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
	params->fstr = itoa_base_unsigned(buf, 10);
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

void		float_print(int negative, t_struct *params)
{
	int len;

	if (negative)
		params->nprinted += write(1, "-", 1);
	params->nprinted += ft_strlen(itoa_base_unsigned(params->fbefore, 10));
	ft_putnbr(params->fbefore);
	params->nprinted += write(1, ".", 1);
	len = ft_strlen(params->fstr);
	params->nprinted += len;
	while (len++ < params->precision)
		params->nprinted += write(1, "0", 1);
	ft_putstr(params->fstr);
}

t_struct	*type_float(va_list args, t_struct *params)
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
			return (params);
		}
		if (is_nan(num))
		{
			params->plus = 0;
			params->nprinted = write(1, "nan", 3);
			return (params);
		}
	}
	if (!params->precision)
		params->precision = 6;
	if (num < 0)
	{
		negative++;
		num *= -1;
	}
	params->fbefore = num;
	float_math(num, params);
	float_print(negative, params);
	return (params);
} 