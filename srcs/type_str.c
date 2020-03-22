/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:38:17 by releanor          #+#    #+#             */
/*   Updated: 2020/03/06 14:34:54 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_print2(t_struct *prms)
{
	if (prms->width > prms->lenbefore && !prms->minus && !prms->dot)
			prms->indent = prms->width - prms->lenbefore;
	else if (prms->width && prms->width > prms->lenbefore && prms->precision \
	&& prms->precision < prms->lenbefore)
		prms->indent = prms->width - prms->precision;
	else if (prms->width > prms->lenbefore && prms->precision \
	&& prms->precision > prms->lenbefore)
		prms->indent = prms->width - prms->lenbefore;
	else if (prms->width && prms->dot && !prms->precision && !prms->precisionzero)
		prms->indent = prms->width;
	else if (prms->width && prms->dot && prms->precision \
	&& !prms->precisionzero && prms->width > prms->precision)
		prms->indent = prms->width - prms->precision;
}

void	str_print(t_struct *prms, char *s)
{
	if (prms->dot && prms->precision & prms->precisionzero)
		prms->width = 0;
	if (!prms->minus)
		str_print2(prms);
	while (prms->indent--)
		prms->nprinted_here += (prms->zero) ? write(1, "0", 1) \
		: write(1, " ", 1);
	if (prms->precision && prms->precision < prms->lenbefore)
	{
		if (prms->width && prms->width > prms->precision && !prms->minus)
			while (prms->nprinted_here < prms->width)
				prms->nprinted_here += write(1, s, prms->precision);
		else 
			while (prms->nprinted_here < prms->precision)
				prms->nprinted_here += write(1, s, prms->precision);
	}
	else if (prms->dot && !prms->precision)
		write(1, "", 0);
	else
		prms->nprinted_here += write(1, s, prms->lenbefore);
	if (prms->width && prms->minus)
		while (prms->nprinted_here < prms->width)
			prms->nprinted_here += write(1, " ", 1);
	prms->nprinted += prms->nprinted_here;
}

void	type_str(va_list args, t_struct *params)
{
	char	*s;

	if (!(s = (char *)va_arg(args, char *)))
		s = "(null)";
	params->lenbefore = ft_strlen(s);
	str_print(params, s);
	bzerostruct(params, 0);
}