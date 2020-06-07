/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 07:27:41 by coclayto          #+#    #+#             */
/*   Updated: 2020/06/07 16:11:57 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		float_math2(long double num, t_struct *params)
{
	int		i;
	char	*str;

	i = 0;
	str = params->fstrafter;
	if (!(params->fstrafter = (char*)malloc(sizeof(str) * params->precision + 1)))
		exit(1);
	while (i < params->precision)
	{
		num *= (long double)10;
		params->fstrafter[i] = (int)(num) + '0';
		num -= (int)num;
		params->lenafter++;
		i++;
	}
	params->fstrafter[i] = '\0';
	rounding(num, params, i);
}

char		*decimal_math(long double num, t_struct *params, int len)
{
	long double temp;
	int			i;
	char		*ptr;

	i = 0;
	if (!(params->fstr = (char*)malloc(sizeof(params->fstr) * len + 1)))
		exit(1);
	ptr = params->fstr;
	while (len)
	{
		temp = num;
		while (i++ < (len - 1))
			temp /= 10;
		*ptr++ = (int)temp + '0';
		temp = (int)temp;
		while (i-- > 1)
			temp *= 10;
		num -= temp;
		len--;
	}
	*ptr = '\0';
	return (params->fstr);
}

void		float_math(long double num, t_struct *params)
{
	int			i;
	int			len;
	long double	temp;

	i = 0;
	temp = num * power(10, params->precision);
	len = float_num_len(temp);
	temp -= ft_atof(decimal_math(temp, params, len));
	if (temp > 0.5 || (temp == 0.5 && is_odd(params->fstr, len)))
		num += (0.5 / power(10, params->precision));
	len = float_num_len(num);
	params->fstrbefore = decimal_math(num, params, len);
	params->fdecimal = num - ft_atof(params->fstrbefore);
	float_math2(params->fdecimal, params);
	params->lenbefore = ft_strlen(params->fstrbefore);
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
