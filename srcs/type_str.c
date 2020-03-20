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

void	str_print(t_struct *params, char *s, int str_len, int indent)
{
	int	printed_here;

	printed_here = 0;

	if (params->dot && params->precision & params->precisionzero)
	{
		params->width = 0;
	}

	if (!params->minus)
	{
		if (params->width > str_len && !params->minus && !params->dot)
				indent = params->width - str_len;

		else if (params->width && params->width > str_len && params->precision && params->precision < str_len)
			indent = params->width - params->precision;

		else if (params->width > str_len && params->precision && params->precision > str_len)
			indent = params->width - str_len;
		else if (params->width && params->dot && !params->precision && !params->precisionzero)
			indent = params->width;
		else if (params->width && params->dot && params->precision \
		&& !params->precisionzero && params->width > params->precision)
			indent = params->width - params->precision;
	}

	while (indent--)
		printed_here += write(1, " ", 1);



	if (params->precision && params->precision < str_len)
	{
		if (params->width && params->width > params->precision && !params->minus)
			while (printed_here < params->width)
				printed_here += write(1, s, params->precision);
		else 
			while (printed_here < params->precision)
				printed_here += write(1, s, params->precision);
	}

	else if (params->dot && !params->precision)
		write(1, "", 0);
	else
		printed_here += write(1, s, str_len);



	if (params->width && params->minus)
		while (printed_here < params->width)
			printed_here += write(1, " ", 1);
	params->nprinted += printed_here;
}

void	type_str(va_list args, t_struct *params)
{
	char	*s;
	int		str_len;

	if (!(s = (char *)va_arg(args, char *)))
		s = "(null)";
	str_len = ft_strlen(s);
	str_print(params, s, str_len, 0);
	bzerostruct(params, 0);
}