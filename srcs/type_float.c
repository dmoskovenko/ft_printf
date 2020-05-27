/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 07:27:41 by coclayto          #+#    #+#             */
/*   Updated: 2020/05/26 23:58:51 by coclayto         ###   ########.fr       */
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
//	ft_putnbr(params->fbefore);
	ft_putstr(params->fstrbefore);
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

void		float_math2(long double num, t_struct *params)
{
	int		i;

	i = 0;
	if (!(params->fstr = (char*)malloc(sizeof(params->fstr) * params->precision + 1)))
		exit(1);
	while (i < params->precision)
	{
		num *= (long double)10;
		params->fstr[i] = (int)(num) + '0';
		num -= (int)num;
		params->lenafter++;
		i++;
	}
	params->fstr[i] = '\0';
	if (num >= 0.5)
	{
		if (i)
		{
			if (params->fstr[--i] != '9')
				params->fstr[i]++;
			else
			{
				//params->fstr[i] = '0';
				while (params->fstr[i] == '9' && i >= 0)
					params->fstr[i--] = '0';
				if (i >= 0)
					params->fstr[i]++;
				else
					params->fbefore++;
			}
		}
		else 
			params->fbefore++;
	}
}

char		*decimal_math(long double num)
{
	long double temp;
	int			len;
	int			i;
	char		*str;
	char		*ptr;

	len = float_num_len(num);
	if (!(str = (char*)malloc(sizeof(str) * len + 1)))
		exit(1);
	ptr = str;
	while (len)
	{
		i = 0;
		temp = num;
		while (i < (len - 1))
		{
			temp /= 10;
			i++;
		}
		*ptr++ = (int)temp + '0';
		temp = (int)temp;
		while (i--)
			temp *= 10;
		num -= temp;
		len--;
	}
	*ptr = '\0';
	return (str);
}

void		float_math(long double num, t_struct *params)
{
	int			i;
	long double	temp;
//	long double	temp2;
//	long double fpower;	

	i = 0;
	temp = num * power(10, params->precision);
	temp -= ft_atof(decimal_math(temp));
	if (temp >= 0.5)
		num += (0.5 / power(10, params->precision));
	params->fstrbefore = decimal_math(num);
	params->fdecimal = num - ft_atof(params->fstrbefore);
//	params->fdecimal += (temp / power(10, params->precision));
	float_math2(params->fdecimal, params);
/*
** 	params->fdecimal *= fpower;
** 	fbuf2 = params->fdecimal;
** 	fbuf = params->fdecimal - fbuf2;
** 	if (fbuf >= 0.5)
** 		params->fdecimal += 0.5;
** 	params->fafter = params->fdecimal;
** 	if ((int)params->fdecimal == fpower)
** 	{
** 		params->fbefore++;
** 		params->fafter = 0;
** 	}
** 	params->fstr = itoa_base_unsigned(params->fafter, 10);
*/ 	params->lenbefore = ft_strlen(params->fstrbefore);
// 	params->lenafter = ft_strlen(params->fstr);
//
}

/*
** void		float_math(long double num, t_struct *params)
** {
** 	int			i;
** 	long double	fbuf;
** 	long double fpower;
** 	long long	fbuf2;
** 
** 	i = 0;
** 	params->fbefore = num;
** 	params->fdecimal = num - params->fbefore;
** 	fbuf = params->fdecimal;
** 	fpower = power(10, params->precision);
** 	params->fdecimal *= fpower;
** 	fbuf2 = params->fdecimal;
** 	fbuf = params->fdecimal - fbuf2;
** 	if (fbuf >= 0.5)
** 		params->fdecimal += 0.5;
** 	params->fafter = params->fdecimal;
** 	if ((int)params->fdecimal == fpower)
** 	{
** 		params->fbefore++;
** 		params->fafter = 0;
** 	}
** 	params->fstr = itoa_base_unsigned(params->fafter, 10);
** 	params->lenbefore = unsigned_num_len(params->fbefore, 10);
** 	params->lenafter = ft_strlen(params->fstr);
** }
*/

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
