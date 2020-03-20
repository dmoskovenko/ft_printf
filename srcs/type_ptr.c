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
	int			printed_here;
	char		*s;

	printed_here = 0;
	ptr = (uintmax_t)va_arg(args, void *);
	ptr_len = unsigned_num_len(ptr, 16);  //длина указателя всегда 6?
	s = itoa_base_unsigned(ptr, 16);
	if (params->width > ptr_len)
		indent = params->width - ptr_len - params->plus - 2;
	if (params->width && params->width > ptr_len && !params->zero && !params->minus)
	{
		while (indent--)
			printed_here += write(1, " ", 1);
		if (params->plus)
			printed_here += write(1, "+", 1);
		printed_here += write(1, "0x", 2);
		printed_here += write(1, s, ptr_len);
	}
	else if (params->width && params->width > ptr_len && params->zero && !params->minus)
	{
		if (params->plus)
			printed_here += write(1, "+", 1);
		printed_here += write(1, "0x", 2);
		while (indent--)
			printed_here += write(1, "0", 1);
		printed_here += write(1, s, ptr_len);
	}
	else
	{
		if (params->plus)
			printed_here += write(1, "+", 1);
		printed_here += write(1, "0x", 2);
		printed_here += write(1, s, ptr_len);
	}
	if (params->width && params->minus)
		while (printed_here < params->width)
			printed_here += write(1, " ", 1);
	params->nprinted += printed_here;
	bzerostruct(params, 0);
}