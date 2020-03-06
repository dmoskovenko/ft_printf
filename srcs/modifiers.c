/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:46:52 by releanor          #+#    #+#             */
/*   Updated: 2020/03/03 08:30:48 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags(const char *fmt, t_struct *params)
{
	while (ft_strchr("-+ #0", fmt[params->i]))
	{
		if (fmt[params->i] == '-')
			params->minus = 1;
		if (fmt[params->i] == '+')
			params->plus = 1;
		if (fmt[params->i] == ' ')
			params->space = 1;
		if (fmt[params->i] == '#')
			params->hash = 1;
		if (fmt[params->i] == '0')
			params->zero = 1;
		params->i++;
	}
	if (params->plus == 1)
		params->space = 0;
}

void	length_field(const char *fmt, t_struct *params)
{
	int i;

	i = params->i;
	if (ft_strchr(LENGHTFLAGS, fmt[i]))
	{
		if (fmt[i] == 'h')
			params->length = SHORT;
		else if (fmt[i] == 'h' && fmt[i + 1] == 'h')
			params->length = SHORTSHORT;
		if (fmt[i] == 'l')
			params->length = LONG;
		else if (fmt[i] == 'l' && fmt[i + 1] == 'l')
			params->length = LONGLONG;
		if (fmt[i] == 'L')
			params->length = LONGDOUBLE;
	}
	while (ft_strchr(LENGHTFLAGS, fmt[i]))
		i++;
	params->i = i;
}

int		modifiers(va_list args, const char *fmt, t_struct *params)
{
	if (args == NULL)
		return (0);
	length_field(fmt, params);
 	flags(fmt, params);
/*
**  width(fmt, params, args);
**  precision(fmt, params, args, 0);
*/
	return (params->i);
}