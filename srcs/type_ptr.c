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

void	type_ptr(va_list args, t_struct *params)
{
	uintmax_t	ptr;
	int			ptr_len;
	int			indent;
	int			indent_was;
	int			precision_was;
	int			printed_here;
	char		*s;

	printed_here = 0;
	indent = 0;
	indent_was = 0;
	precision_was = 0;
	ptr = (uintmax_t)va_arg(args, void *);
	ptr_len = unsigned_num_len(ptr, 16);
	s = itoa_base_unsigned(ptr, 16);
	if (params->zero && params->dot)
		params->zero = 0;
	if (params->width > params->precision)
	{
		params->precision = 0;
		precision_was = 1;
	}
	if (params->precision > params->width)
		params->width = 0;

	if (params->width > ptr_len)
	{
		indent = params->width - params->precision - ptr_len - params->plus - 2;
		indent_was = indent;
	}
	if (params->width && params->width > ptr_len && !params->zero && !params->minus)
	{
		while (indent--)
			printed_here += write(1, " ", 1);
		if (params->plus)
			printed_here += write(1, "+", 1);
		printed_here += write(1, "0x", 2);
		if (params->dot && !precision_was && !params->precision)
			write(1, "", 0);
		else
			printed_here += write(1, s, ptr_len);
	}
	else if (params->width && params->width > ptr_len && params->zero && !params->minus)
	{
		if (params->plus)
			printed_here += write(1, "+", 1);
		printed_here += write(1, "0x", 2);
		while (indent--)
			printed_here += write(1, "0", 1);
		if (params->dot && !params->precision)
			write(1, "", 0);
		else
			printed_here += write(1, s, ptr_len);
	}
	else if (params->precision && params->precision > ptr_len)
	{
		printed_here += write(1, "0x", 2);
		while (printed_here < params->precision + 2 - ptr_len)
			printed_here += write(1, "0", 1);
		printed_here += write(1, s, ptr_len);
	}
	else
	{
		if (params->plus)
			printed_here += write(1, "+", 1);
		printed_here += write(1, "0x", 2);
		if (params->dot && !params->precision)
			write(1, "", 0);
		else
			printed_here += write(1, s, ptr_len);
	}
	if (params->width && params->minus)
		while (printed_here < params->width)
			printed_here += write(1, " ", 1);
	params->nprinted += printed_here;
	free (s);
	bzerostruct(params, 0);
}