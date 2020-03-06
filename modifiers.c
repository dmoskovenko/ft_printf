/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:46:52 by releanor          #+#    #+#             */
/*   Updated: 2020/03/06 10:22:12 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	length_field(const char *fmt, t_struct *params)
{
	//int i;

	//i = params->i;
	if (ft_strchr(LENGHTFLAGS, fmt[params->i]))
	{
		if (fmt[params->i] == 'h')
			params->length = SHORT;
		else if (fmt[params->i] == 'h' && fmt[params->i + 1] == 'h')
			params->length = SHORTSHORT;
		if (fmt[params->i] == 'l')
			params->length = LONG;
		else if (fmt[params->i] == 'l' && fmt[params->i + 1] == 'l')
			params->length = LONGLONG;
		if (fmt[params->i] == 'L')
			params->length = LONGDOUBLE;
	}
	while (ft_strchr(LENGHTFLAGS, fmt[params->i]))
		params->i++;
	//params->i = i;
}

int		modifiers(va_list args, const char *fmt, t_struct *params)
{
	// Flags
	// Width
	// Precision
	if (args == NULL)
		return (0);
	length_field(fmt, params);
	return (params->i);
}