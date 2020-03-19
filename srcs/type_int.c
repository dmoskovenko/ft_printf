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

int		int_print2(t_struct *params, char *s, int num_length)
{
	if ((!params->width && params->dot && params->zero_arg && params->precisionzero) \
	|| (!params->width && params->dot && !params->precision && !params->precisionzero && params->zero_arg))
		return (0);

	if (params->width && params->dot && params->zero_arg && !params->precision)
		if (params->plus)
			write(1, "", 0);
		else
			params->nprinted += write(1, " ", 1);
	else
		params->nprinted += write(1, s, num_length);

	if (params->width && params->minus)
		while (params->nprinted < params->width)
			params->nprinted += write(1, " ", 1);
	return (1);
}

void	int_print(t_struct *params, char *s, int num_length, int indent)
{

	if (params->negative  && params->zero)
		params->nprinted += write(1, "-", 1);

	if (params->plus && !params->negative && params->zero)
		params->nprinted += write(1, "+", 1);

	if (params->space && !params->negative && params->zero)
		params->nprinted += write(1, " ", 1);



	if (params->width > num_length)
			indent = params->width - num_length;
	
	if (params->negative || params->plus || params->space)
		indent--;
	if (params->zero_arg && params->plus && params->dot && params->width && !params->precision)
		indent++;

	if (params->width > num_length && !params->minus)
	{
		while (indent--)
		{
			params->nprinted += (params->zero && !params->precision) \
			? write(1, "0", 1) : \
			write(1, " ", 1);
		}
	}



	if (params->negative  && !params->zero)
		params->nprinted += write(1, "-", 1);


	if (params->plus && !params->negative && !params->zero)
		params->nprinted += write(1, "+", 1);

	if (params->space && !params->negative && !params->zero)
		params->nprinted += write(1, " ", 1);


	int_print2(params, s, num_length);
}


char	*int_with_prec(t_struct *params, char *s, int num_length, int i)
{
	char	*s_prec;
	int		j;

	j = 0;
	if (!(s_prec = (char *)malloc(sizeof(char) * (params->precision + 1))))
		s_prec = NULL;
	while (i < (params->precision - num_length))
	{
		s_prec[i] = '0';
		i++;
	}
	while (s[j])
	{
		s_prec[i] = s[j];
		i++;
		j++;
	}
	s_prec[i] = '\0';
	return (s_prec);
}


void	int_from_fmt(t_struct *params, intmax_t num, int i)
{
	char	*s;
	int		num_length;
	int		indent;

	indent = 0;
	num_length = num_len(num, 10);
	s = itoa_base(params, num, 10);

	if (/* params->minus || */ params->dot)
		params->zero = 0;

	if ((num == 0) && (num_length == 1))
		params->zero_arg++;
	
	if (params->precision && params->precision > num_length && !params->negative)
		s = int_with_prec(params, s, num_length, i);
	else if (params->precision && params->precision > num_length && params->negative)
		s = int_with_prec(params, s, num_length, i);
	num_length = ft_strlen(s);
	

	int_print(params, s, num_length, indent);
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
	if (num == LLONG_MIN)
	{
		params->nprinted += write(1, "-9223372036854775808", 20);
		return;
	}
	int_from_fmt(params, num, 0);
}
