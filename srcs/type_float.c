/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 07:27:41 by coclayto          #+#    #+#             */
/*   Updated: 2020/06/08 11:59:53 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rounding(long double num, t_struct *params, int i)
{
	if (num >= 0.5)
	{
		if (i)
		{
			if (params->fstraft[--i] != '9')
				params->fstraft[i]++;
			else
			{
				while (params->fstraft[i] == '9' && i >= 0)
					params->fstraft[i--] = '0';
				if (i >= 0)
					params->fstraft[i]++;
				else
					params->fbefore++;
			}
		}
		else
			params->fbefore++;
	}
}

void	float_math2(long double num, t_struct *params)
{
	int		i;
	char	*str;

	i = 0;
	str = params->fstraft;
	if (!(params->fstraft = (char*)malloc(sizeof(str) * params->precision + 1)))
		exit(1);
	while (i < params->precision)
	{
		num *= (long double)10;
		params->fstraft[i] = (int)(num) + '0';
		num -= (int)num;
		params->lenafter++;
		i++;
	}
	params->fstraft[i] = '\0';
	rounding(num, params, i);
}

char	*decimal_math(long double num, char *str, int len)
{
	long double temp;
	int			i;
	char		*ptr;

	i = 0;
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
	int			i;
	int			len;
	long double	temp;

	i = 0;
	temp = num * power(10, params->precision);
	len = float_num_len(temp);
	if (!(params->fstr = (char*)malloc(sizeof(params->fstr) * len + 1)))
		exit(1);
	temp -= ft_atof(decimal_math(temp, params->fstr, len));
	if (temp > 0.5 || (temp == 0.5 && is_odd(params->fstr, len)))
		num += (0.5 / power(10, params->precision));
	len = float_num_len(num);
	if (!(params->fstrbef = (char*)malloc(sizeof(params->fstrbef) * len + 1)))
		exit(1);
	decimal_math(num, params->fstrbef, len);
	params->fdecimal = num - ft_atof(params->fstrbef);
	float_math2(params->fdecimal, params);
	params->lenbefore = ft_strlen(params->fstrbef);
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
	float_free(params);
}
