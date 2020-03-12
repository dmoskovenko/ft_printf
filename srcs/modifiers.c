/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:46:52 by releanor          #+#    #+#             */
/*   Updated: 2020/03/09 10:08:20 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			precision(const char *fmt, t_struct	*params)
{
	if (fmt[params->i] == '.')
		params->i++;
	if (ft_isdigit(fmt[params->i]))
	{
		params->precision = ft_atoi(&fmt[params->i]);
		if (fmt[params->i] == '0')
			params->precisionzero++;
		params->i += unsigned_num_len(params->precision, 10);
	}
}

void			width(const char *fmt, t_struct *params)
{
	if (ft_isdigit(fmt[params->i]))
	{
		params->width = ft_atoi(&fmt[params->i]);
		params->i += unsigned_num_len(params->width, 10);
	}
 }

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
	if (ft_strchr("hlL", fmt[params->i]))
	{
		if (fmt[params->i] == 'h')
			params->length = SHORT;
		if (fmt[params->i] == 'h' && fmt[params->i + 1] == 'h')
			params->length = SHORTSHORT;
		if (fmt[params->i] == 'l')
			params->length = LONG;
		if (fmt[params->i] == 'l' && fmt[params->i + 1] == 'l')
			params->length = LONGLONG;
		if (fmt[params->i] == 'L')
			params->length = LONGDOUBLE;
	}
	while (ft_strchr("hlL", fmt[params->i]))
		params->i++;
}

int		modifiers(va_list args, const char *fmt, t_struct *params)
{
	if (args == NULL)
		return (0);
 	flags(fmt, params);
	width(fmt, params);
	length_field(fmt, params);
	precision(fmt, params);
	return (params->i);
}