/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:34:13 by releanor          #+#    #+#             */
/*   Updated: 2020/03/06 12:33:06 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_chk(t_struct *params)
{
	if (params->negative  && params->zero)
		params->nprinted_here += write(1, "-", 1);
	if (params->plus && !params->negative && params->zero)
		params->nprinted_here += write(1, "+", 1);
	if (params->space && !params->negative && params->zero)
		params->nprinted_here += write(1, " ", 1);
}

int		int_print2(t_struct *params, char *s)
{
	if ((!params->width && params->dot && params->zero_arg \
	&& params->precisionzero) || (!params->width && \
	params->dot && !params->precision && !params->precisionzero \
	&& params->zero_arg))
		return (0);
	if (params->width && params->dot && params->zero_arg \
	&& !params->precision)
		if (params->plus)
			write(1, "", 0);
		else
			params->nprinted_here += write(1, " ", 1);
	else
		params->nprinted_here += write(1, s, params->lenbefore);
	if (params->width && params->minus)
		while (params->nprinted_here < params->width)
			params->nprinted_here += write(1, " ", 1);
	return (1);
}

void	int_print(t_struct *params, char *s, int indent)
{
	int_chk(params);
	if (params->width > params->lenbefore)
			indent = params->width - params->lenbefore;
	if (params->negative || params->plus || params->space)
		indent--;
	if (params->zero_arg && params->plus && params->dot && \
	params->width && !params->precision)
		indent++;
	if (params->width > params->lenbefore && !params->minus)
	{
		while (indent--)
		{
			params->nprinted_here += (params->zero \
			&& !params->precision) \
			? write(1, "0", 1) : \
			write(1, " ", 1);
		}
	}
	if (params->negative  && !params->zero)
		params->nprinted_here += write(1, "-", 1);
	if (params->plus && !params->negative && !params->zero)
		params->nprinted_here += write(1, "+", 1);
	if (params->space && !params->negative && !params->zero)
		params->nprinted_here += write(1, " ", 1);
	int_print2(params, s);
}

void	int_from_fmt(t_struct *params, intmax_t num, int i)
{
	char	*s;
	int		indent;

	indent = 0;
	params->lenbefore = num_len(num, 10);
	s = itoa_base(params, num, 10);
	s = int_overflow_chk(num, s);
	if (params->dot)
		params->zero = 0;
	if ((num == 0) && (params->lenbefore == 1))
		params->zero_arg++;
	if (params->precision && params->precision \
	> params->lenbefore && !params->negative)
		s = int_with_prec(params, s, i);
	else if (params->precision && params->precision > \
	params->lenbefore && params->negative)
		s = int_with_prec(params, s, i);
	params->lenbefore = ft_strlen(s);
	int_print(params, s, indent);
	params->nprinted += params->nprinted_here;
	if (num != LLONG_MAX && num != LLONG_MIN)
		free(s);
	bzerostruct(params, 0);
}

void	type_int(va_list args, t_struct *params)
{
	intmax_t num;
	
	num = 0;
	if (params->length == 0)
		num = (int)va_arg(args, int);
	if (params->length == SHORTSHORT)
		num = (signed char)va_arg(args, int);
	if (params->length == SHORT)
		num = (short int)va_arg(args, int);
	if (params->length == LONG)
		num = (long int)va_arg(args, long int);
	if (params->length == LONGLONG)
		num = (long long int)va_arg(args, long long int);
	if (params->length == SIZET)
		num = (size_t)va_arg(args, size_t);
	if (params->length == INTUINTMAX)
		num = (intmax_t)va_arg(args, intmax_t);
	if (params->dot > 1 && params->precision)
	{
		params->dot = 0;
		params->zero = 0;
		params->precision = 0;
	}
	int_from_fmt(params, num, 0);
}
