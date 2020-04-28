/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 07:27:41 by coclayto          #+#    #+#             */
/*   Updated: 2020/04/28 19:11:12 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_infnan(t_struct *params, long double num)
{
	if (num == (1.0 / 0.0) || num == -(1.0 / 0.0))
	{
		params->nprinted = write(1, "inf", 3);
		return (1);
	}
	if (!(num == num))
	{
		params->plus = 0;
		params->nprinted = write(1, "nan", 3);
		return (1);
	}
	return (0);
}

void		float_print2(t_struct *params)
{
	int	i;

	i = 0;
	ft_putnbr(params->fbefore);
	params->nprinted += params->lenbefore;
	if (params->hash || params->precision)
		params->nprinted += write(1, ".", 1);
	if (params->precision)
	{
		while (i++ < params->precision - params->lenafter)
			params->nprinted += write(1, "0", 1);
		ft_putstr(params->fstr);
		params->nprinted += params->lenafter;
	}
	if (params->width && params->minus)
		while (params->nprinted < params->width)
			params->nprinted += write(1, " ", 1);
	free(params->fstr);
}

void		float_print(t_struct *params)
{
	int len;
	int	indent;

	indent = 0;
	len = params->lenbefore + params->lenafter;
	(params->hash || params->precision) ? len++ : len--;
	if (params->width > len)
		indent = params->width - len;
	if (params->negative || params->plus || params->space)
		indent--;
	if (params->width > len && !params->minus && !params->zero)
		while (indent--)
			params->nprinted += write(1, " ", 1);
	if (params->space && !params->negative)
		params->nprinted += write(1, " ", 1);
	if (params->negative)
		params->nprinted += write(1, "-", 1);
	if (params->plus && !params->negative)
		params->nprinted += write(1, "+", 1);
	if (params->width > len && !params->minus && params->zero)
		while (indent--)
			params->nprinted += write(1, "0", 1);
	float_print2(params);
}

void		float_math(long double num, t_struct *params)
{
	int			i;
	long double	fbuf;
	long double fpower;
	long long	fbuf2;

	i = 0;
	params->fbefore = num;
	params->fdecimal = num - params->fbefore;
	fbuf = params->fdecimal;
	fpower = power(10, params->precision);
	params->fdecimal *= fpower;
	fbuf2 = params->fdecimal;
	fbuf = params->fdecimal - fbuf2;
	if (fbuf >= 0.5)
		params->fdecimal += 0.5;
	params->fafter = params->fdecimal;
	if ((int)params->fdecimal == fpower)
	{
		params->fbefore++;
		params->fafter = 0;
	}
	params->fstr = itoa_base_unsigned(params->fafter, 10);
	params->lenbefore = unsigned_num_len(params->fbefore, 10);
	params->lenafter = ft_strlen(params->fstr);
}

void		type_float(va_list args, t_struct *params)
{
	long double num;
	int			negative;

	negative = 0;
	if (params->length == LONG)
		num = (double)va_arg(args, double);
	if (params->length == LONGDOUBLE)
		num = (long double)va_arg(args, long double);
	if (params->length == 0)
		num = (double)va_arg(args, double);
	if (is_infnan(params, num))
	{
		params->hash = 0;
		params->zero = 0;
		return ;
	}
	if (!params->precision && !params->precisionzero)
		params->precision = 6;
	if (num < 0)
	{
		params->negative++;
		num *= -1;
	}
	float_math(num, params);
	float_print(params);
}
