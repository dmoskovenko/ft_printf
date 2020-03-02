/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:46:52 by releanor          #+#    #+#             */
/*   Updated: 2020/03/02 21:32:37 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct		length_field(const char *fmt, t_struct params)
{
	int i;

	// i = params.i;
	if (ft_strchr(LENGHTFLAGS, fmt[i]))
	{
		if (fmt[i] == 'h')
			params.length = SHORT;
		if (fmt[i] == 'h' && fmt[i + 1] == 'h')
			params.length = SHORTSHORT;
		if (fmt[i] == 'l')
			params.length = LONG;
		if (fmt[i] == 'l' && fmt[i + 1] == 'l')
			params.length = LONGLONG;
		if (fmt[i] == 'L')
			params.length = LONGDOUBLE;
	}
	while (ft_strchr(LENGHTFLAGS, fmt[i]))
		params.i++;
	// params.i = i;
	return (params);
}

int		modifiers(va_list args, const char *fmt, t_struct params)
{
	// Flags
	// Width
	// Precision
	if (args == NULL)
		return (0);
	params = length_field(fmt, params);
	return (params);
}