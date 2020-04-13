/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:43:43 by releanor          #+#    #+#             */
/*   Updated: 2020/03/13 02:18:27 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	b_from_fmt(t_struct *prms, uintmax_t num, int i)
{
	char	*s;

	prms->lenbefore = unsigned_num_len(num, 2);
	s = itoa_base_unsigned(num, 2);
	if (prms->precision && prms->precision > prms->lenbefore)
	{
		s = u_with_prec(prms, s, i);
		prms->lenbefore = ft_strlen(s);
	}
	if (prms->plus)
		prms->plus = 0;
	if (prms->hash)
		prms->hash = 0;
	if (prms->space)
		prms->space = 0;
	u_print(prms, s, 0);
	prms->nprinted += prms->nprinted_here;
	free(s);
	bzerostruct(prms, 0);
}

void	type_b(va_list args, t_struct *prms)
{
	uintmax_t num;

	num = 0;
	if (prms->length)
		num = (unsigned int)va_arg(args, int);
	else if (prms->length == SHORTSHORT)
		num = (unsigned char)va_arg(args, int);
	else if (prms->length == SHORT)
		num = (unsigned short)va_arg(args, int);
	else if (prms->length == LONG)
		num = (unsigned long)va_arg(args, unsigned long);
	else if (prms->length == LONGLONG)
		num = (unsigned long long)va_arg(args, \
		unsigned long long);
	if (prms->length == SIZET)
		num = (size_t)va_arg(args, size_t);
	if (prms->length == INTUINTMAX)
		num = (uintmax_t)va_arg(args, uintmax_t);
	b_from_fmt(prms, num, 0);
}
