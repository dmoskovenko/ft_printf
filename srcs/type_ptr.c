/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:45:48 by releanor          #+#    #+#             */
/*   Updated: 2020/03/06 14:58:36 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ptr_print2(t_struct *prms, char*s)
{
	while (prms->indent--)
		prms->nprinted_here += write(1, " ", 1);
	if (prms->plus)
		prms->nprinted_here += write(1, "+", 1);
	prms->nprinted_here += write(1, "0x", 2);
	if (prms->dot && !prms->precision_was && !prms->precision)
		write(1, "", 0);
	else
		prms->nprinted_here += write(1, s, prms->lenbefore);
}

void	ptr_print3(t_struct *prms, char *s)
{
	if (prms->plus)
		prms->nprinted_here += write(1, "+", 1);
	prms->nprinted_here += write(1, "0x", 2);
	while (prms->indent--)
		prms->nprinted_here += write(1, "0", 1);
	if (prms->dot && !prms->precision)
		write(1, "", 0);
	else
		prms->nprinted_here += write(1, s, prms->lenbefore);
}

void	ptr_print4(t_struct *prms, char *s)
{
	if (prms->plus)
		prms->nprinted_here += write(1, "+", 1);
	prms->nprinted_here += write(1, "0x", 2);
	if (prms->dot && !prms->precision)
		write(1, "", 0);
	else
		prms->nprinted_here += write(1, s, prms->lenbefore);
}

void	ptr_print(t_struct *prms, char *s)
{
	ptr_chk(prms);
	if (prms->width && prms->width > prms->lenbefore \
	&& !prms->zero && !prms->minus)
		ptr_print2(prms, s);
	else if (prms->width && prms->width > prms->lenbefore \
	&& prms->zero && !prms->minus)
		ptr_print3(prms, s);
	else if (prms->precision && prms->precision > prms->lenbefore)
	{
		prms->nprinted_here += write(1, "0x", 2);
		while (prms->nprinted_here < prms->precision \
		+ 2 - prms->lenbefore)
			prms->nprinted_here += write(1, "0", 1);
		prms->nprinted_here += write(1, s, prms->lenbefore);
	}
	else
		ptr_print4(prms, s);
	if (prms->width && prms->minus)
		while (prms->nprinted_here < prms->width)
			prms->nprinted_here += write(1, " ", 1);
}

void	type_ptr(va_list args, t_struct *params)
{
	uintmax_t	ptr;
	char		*s;

	ptr = (uintmax_t)va_arg(args, void *);
	params->lenbefore = unsigned_num_len(ptr, 16);
	s = itoa_base_unsigned(ptr, 16);
	ptr_print(params, s);
	params->nprinted += params->nprinted_here;
	free (s);
	bzerostruct(params, 0);
}
