/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 13:19:20 by coclayto          #+#    #+#             */
/*   Updated: 2020/06/07 16:08:59 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		float_print2(t_struct *params)
{
	int	i;

	i = 0;
	ft_putstr(params->fstrbefore);
	params->nprinted += params->lenbefore;
	if (params->hash || params->precision)
		params->nprinted += write(1, ".", 1);
	if (params->precision)
	{
		while (i++ < params->precision - params->lenafter)
			params->nprinted += write(1, "0", 1);
		ft_putstr(params->fstrafter);
		params->nprinted += params->lenafter;
	}
	if (params->width && params->minus)
		while (params->nprinted < params->width)
			params->nprinted += write(1, " ", 1);
	free(params->fstrafter);
}

void		float_print(t_struct *params)
{
	int len;
	int	indent;

	indent = 0;
	len = params->lenbefore + params->lenafter;
	if (params->hash || params->precision)
		len++;
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

void		rounding(long double num, t_struct *params, int i)
{
	if (num >= 0.5)
	{
		if (i)
		{
			if (params->fstrafter[--i] != '9')
				params->fstrafter[i]++;
			else
			{
				while (params->fstrafter[i] == '9' && i >= 0)
					params->fstrafter[i--] = '0';
				if (i >= 0)
					params->fstrafter[i]++;
				else
					params->fbefore++;
			}
		}
		else
			params->fbefore++;
	}
}

int			is_odd(char *str, int len)
{
	return ((str[len - 1] - '0') % 2);
}

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