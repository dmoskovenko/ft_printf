/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 07:27:41 by coclayto          #+#    #+#             */
/*   Updated: 2020/06/15 01:34:14 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rounding(long double num, t_struct *params, int i)
{
	if ((num > 0.5) \
	|| (num == 0.5 && is_odd(params->fafter[params->lenafter])))
	{
		if (i)
		{
			if (params->fafter[--i] != '9')
				params->fafter[i]++;
			else
			{
				while (params->fafter[i] == '9' && i >= 0)
					params->fafter[i--] = '0';
				(i >= 0) ? params->fafter[i]++ : f_increment(params);
			}
		}
		else
			f_increment(params);
	}
}

void	decimal_math(long double num, t_struct *params)
{
	int		i;
	char	*str;

	i = 0;
	str = params->fafter;
	if (!(params->fafter = (char*)malloc(sizeof(str) * params->precision + 1)))
		exit(1);
	while (i < params->precision)
	{
		num *= (long double)10;
		params->fafter[i] = (int)(num) + '0';
		num -= (int)num;
		params->lenafter++;
		i++;
	}
	params->fafter[i] = '\0';
	rounding(num, params, i);
	params->lenbefore = ft_strlen(params->fbefore);
}

char	*integer_math(long double num, int end)
{
	int			i;
	int			len;
	char		*str;
	char		*ptr;
	long double temp;

	i = 0;
	len = float_num_len(num);
	if (!(str = (char*)malloc(sizeof(str) * len + end)))
		exit(1);
	ptr = str;
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
	return (str);
}

void	float_math(long double num, t_struct *params)
{
	int			len;
	long double	temp;
	long double	fdecimal;
	char		*str;

	temp = num * power(10, params->precision);
	str = integer_math(temp, 1);
	temp -= ft_atof(str);
	len = ft_strlen(str);
	if (temp > 0.5 || (temp == 0.5 && is_odd(str[len - 1])))
		num += (0.5 / power(10, params->precision));
	free(str);
	params->fbefore = integer_math(num, 2);
	fdecimal = num - ft_atof(params->fbefore);
	decimal_math(fdecimal, params);
}

void	type_float(va_list args, t_struct *params)
{
	long double num;

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
	free(params->fbefore);
	free(params->fafter);
}
