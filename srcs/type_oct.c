/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_oct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:36:52 by releanor          #+#    #+#             */
/*   Updated: 2020/03/13 04:36:11 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		oct_print2(t_struct *prms, char *s)
{
	if ((!prms->width && prms->dot && prms->zero_arg \
	&& prms->precisionzero) \
	|| (!prms->width && prms->dot && !prms->precision && \
	!prms->precisionzero && prms->zero_arg))
	{
		if (prms->hash_case)
		{
			prms->nprinted_here += write(1, "0", 1);
			return (1);
		}
		return (0);
	}
	if (prms->width && prms->dot && prms->zero_arg && \
	!prms->precision && !prms->hash_case)
		prms->nprinted_here += write(1, " ", 1);
	else   
		prms->nprinted_here += write(1, s, prms->lenbefore);
	if (prms->width && prms->minus)
		while (prms->nprinted_here < prms->width)
			prms->nprinted_here += write(1, " ", 1);
	return (1);
}

void	oct_print(t_struct *prms, char *s, int indent)
{
	if (prms->width > prms->lenbefore)
		indent = prms->width - prms->lenbefore;
	if (prms->negative || prms->plus || prms->space)
		indent--;
	if (prms->width > prms->lenbefore && !prms->minus)
	{
		while (indent--)
		{
			prms->nprinted_here += (prms->zero && !prms->precision) \
			? write(1, "0", 1) : \
			write(1, " ", 1);
		}
	}
	if (prms->negative)
		prms->nprinted_here += write(1, "-", 1);
	if (prms->space && !prms->negative)
		prms->nprinted_here += write(1, " ", 1);
	oct_print2(prms, s);
}

void	oct_hash_chk(t_struct *prms, int num)
{
	if ((num == 0) && (prms->lenbefore == 1))
		prms->zero_arg++;
	if (!prms->width && prms->hash && prms->dot && prms->zero_arg)
		prms->hash_case++;
	if (prms->hash && prms->width && !prms->precision && prms->zero_arg)
		prms->hash_case++;
	if (prms->hash && prms->dot && !prms->precision \
	&& !prms->precisionzero && prms->zero_arg)
		prms->hash = 0;
	if (prms->zero_arg)
		prms->hash = 0;
	if (prms->hash && prms->dot && prms->precision > prms->lenbefore)
		prms->hash = 0;
}

void	oct_from_fmt(t_struct *prms, uintmax_t num, int i)
{
	char	*s;
	int		indent;

	indent = 0;
	prms->lenbefore = unsigned_num_len(num, 8);
	s = itoa_base_unsigned(num, 8);
	oct_hash_chk(prms, num);
	if (prms->hash)
		s = oct_hash(prms, s);
	if (prms->precision > prms->lenbefore)
		s = oct_with_prec(prms, s, i);
	prms->lenbefore = ft_strlen(s);
	if (prms->plus)
		prms->plus = 0;
	if (prms->space)
		prms->space = 0;
	oct_print(prms, s, indent);
	prms->nprinted += prms->nprinted_here;
	free(s);
	bzerostruct(prms, 0);
}

void	type_oct(va_list args, t_struct *prms)
{
	uintmax_t num;
	
	num = 0;
	if (prms->length == 0)
		num = va_arg(args, unsigned int);
	if (prms->length == SHORTSHORT)
		num = (unsigned char)va_arg(args, unsigned int);
	if (prms->length == SHORT)
		num = (unsigned short)va_arg(args, unsigned int);
	if (prms->length == LONG)
		num = (unsigned long)va_arg(args, unsigned long);
	if (prms->length == LONGLONG)
		num = (unsigned long long)va_arg(args, unsigned long long);
	oct_from_fmt(prms, num, 0);
}
