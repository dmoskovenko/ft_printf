/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:53:04 by coclayto          #+#    #+#             */
/*   Updated: 2020/02/20 09:33:17 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
int		format_parse2(va_list args, const char *fmt, t_struct params, int pos)
{
	params.i = pos;
	if (!ft_strchr("cspdiouxXf%", fmt[pos]))
		modifiers(args, fmt, params);
	else if (ft_strchr(("cspdiouxXf%"), fmt[pos]))
	{
		conversions(args, fmt[pos], params);
//		bezerostruct2(params);
	}
	return (params.i - 1);
}
*/

void	bezerostruct(t_struct *list)
{
	list->i = 0;
	list->nprinted = 0;
	list->len = 0;
	list->minus = 0;
	list->plus = 0;
	list->space = 0;
	list->zero = 0;
	list->hash = 0;
	list->width = 0;
	list->precisiontf = 0;
	list->precision = 0;
	list->length = 0;
}

void	bezerostruct2(t_struct params)
{
	params.len = 0;
	params.minus = 0;
	params.plus = 0;
	params.space = 0;
	params.zero = 0;
	params.hash = 0;
	params.width = 0;
	params.precisiontf = 0;
	params.precision = 0;
	params.length = 0;
}

int		format_parse(va_list args, const char *fmt, t_struct params, int pos)
{
	while (fmt[pos] != '\0')
	{
		if (fmt[pos] != '%' && fmt[pos])
			params.nprinted += write(1, &fmt[pos], 1);
		else if (fmt[pos] == '%')
		{
			if (!ft_strchr(VALIDSYM, fmt[pos + 1]))
				break;
			while (ft_strchr(VALIDSYM, fmt[pos + 1]))
			{
				pos++;
				params.i = pos;
				if (ft_strchr("cspdiouxXf%", fmt[pos]))
				{
					pos = conversions(args, fmt[pos], params) + 1;
					break;
				}
/*				else
					pos = modifiers(args, fmt, params) - 1;
*/
			}
			continue;
		}
		pos++;
	}
	return (params.nprinted);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		args;
	t_struct	params;
	int			printed;

	params.fmt = (char *) fmt;
	va_start(args, fmt);
	if (!fmt[0])
		return (0);
	if (fmt[0] == '%' && !fmt[1])
		return (0);
	printed = format_parse(args, fmt, params, 0);
	va_end(args);
	return (printed);
}
