/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:55:06 by releanor          #+#    #+#             */
/*   Updated: 2020/03/06 20:00:16 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hex_print2(t_struct *params, char *s)
{
	if ((!params->width && params->dot && params->zero_arg \
	&& params->precisionzero) || (!params->width && params->dot \
	&& !params->precision && !params->precisionzero && params->zero_arg)) 
		return (0);
	if (params->width && params->dot && \
	params->zero_arg && !params->precision)
		params->nprinted_here += write(1, " ", 1);
	else   
		params->nprinted_here += write(1, s, params->lenbefore);
	if (params->width && params->minus)
		while (params->nprinted_here < params->width)
			params->nprinted_here += write(1, " ", 1);
	return (1);
}

void	hex_print(t_struct *prms, char *s, int indent)
{
	if (prms->width > prms->lenbefore)
		indent = prms->width - prms->lenbefore;
	if (prms->negative || prms->plus || prms->space)
		indent--;
	if (prms->hash_case_zero)
	{
		prms->nprinted_here += (prms->small_hex == 1) ? \
		write(1, "0x", 2) : write(1, "0X", 2);
		indent -= 2;
	}
	if (prms->width > prms->lenbefore && !prms->minus)
	{
		while (indent--)
		{
			prms->nprinted_here += (prms->zero \
			&& !prms->precision) ? write(1, "0", 1) : \
			write(1, " ", 1);
		}
	}
	if (prms->space && !prms->negative)
		prms->nprinted_here += write(1, " ", 1);
	hex_print2(prms, s);
}

void	hex_from_fmt2(t_struct *params, char *s, int indent)
{
	if (params->hash)
	{
		s = hex_hash(params, s);
		params->hash = 0;
	}
	params->lenbefore = ft_strlen(s);
	if (params->plus)
		params->plus = 0;
	if (params->space)
		params->space = 0;
	hex_print(params, s, indent);
	params->nprinted += params->nprinted_here;
	free(s);
	bzerostruct(params, 0);
}

void	hex_from_fmt(t_struct *params, uintmax_t num, int i)
{
	char	*s;
	int 	indent;

	indent = 0;
	params->lenbefore = unsigned_num_len(num, 16);
	s = (params->small_hex == 1) ? \
	itoa_base_unsigned(num, 16) : itoa_base_upp(num, 16);
	hex_hash_chk(params, num);
	if (params->precision > params->lenbefore)
		s = hex_with_prec(params, s, i);
	if (params->hash && params->zero && \
	params->width && !params->precision)
	{
		params->hash_case_zero++;
		params->hash = 0;
	}
	hex_from_fmt2(params, s, indent);
}

void	type_hex(va_list args, t_struct *prms, char spec)
{
	uintmax_t num;
	
	num = 0;
	if (!prms->length)
		num = va_arg(args, unsigned int);
	if (prms->length == SHORTSHORT)
		num = (unsigned char)va_arg(args, unsigned int);
	if (prms->length == SHORT)
		num = (unsigned short)va_arg(args, unsigned int);
	if (prms->length == LONG)
		num = (unsigned long)va_arg(args, unsigned long);
	if (prms->length == LONGLONG)
		num = (unsigned long long)va_arg(args, \
		unsigned long long);
	if (prms->length == SIZET)
		num = (size_t)va_arg(args, size_t);
	if (prms->length == INTUINTMAX)
		num = (uintmax_t)va_arg(args, uintmax_t);
	prms->small_hex = (spec == 'x') ? 1 : 0;	
	hex_from_fmt(prms, num, 0);
}
