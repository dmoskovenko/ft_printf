/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:53:04 by coclayto          #+#    #+#             */
/*   Updated: 2020/03/13 02:28:28 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
int		format_parse2(va_list args, const char *fmt, t_struct *params, int pos)
{
	params->i = pos;
	if (!ft_strchr("cspdiouxXf%", fmt[pos]))
		modifiers(args, fmt, params);
	else if (ft_strchr(("cspdiouxXf%"), fmt[pos]))
	{
		conversions(args, fmt[pos], params);
//		bezerostruct2(params);
	}
	return (params->i - 1);
}
*/ // переместил все в format_parse

int		retmsg(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit (1);
}

void	bzerostruct(t_struct *params, int full)
{
	if (full)
	{
		params->i = 0;
		params->nprinted = 0;
	}
	params->len = 0;
	params->negative = 0;
	params->minus = 0;
	params->plus = 0;
	params->space = 0;
	params->zero = 0;
	params->zero_arg = 0;
	params->hash = 0;
	params->hash_case = 0;
	params->hash_case_zero = 0;
	params->small_hex = 0;
	params->dot = 0;
	params->width = 0;
	params->precisionzero = 0;
	params->precision = 0;
	params->length = 0;
	/* Other float fields? */
}

int		format_parse(va_list args, const char *fmt, t_struct *params, int pos)
{
	while (fmt[pos])
	{
		if (fmt[pos] != '%' && fmt[pos])
			params->nprinted += write(1, &fmt[pos], 1);
		else if (fmt[pos] == '%')
		{
			if (!ft_strchr(VALIDSYM, fmt[pos + 1]))
				break;
			while (ft_strchr(VALIDSYM, fmt[pos + 1]))
			{
				pos++;
				params->i = pos;
				if (ft_strchr(TYPESYM, fmt[pos]))
				{
					pos = conversions(args, fmt[pos], params) + 1;
					break;
				}
				else if (ft_strchr(FLAGS, fmt[pos]) || ft_isdigit(fmt[pos]))
					pos = modifiers(args, fmt, params) - 1;
			}
			continue;
		}
		pos++;
	}
	return (params->nprinted);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		args;
	t_struct	*params;
	int			printed;

	if (!(params = (t_struct *)malloc(sizeof(t_struct))))
		return (0);
	bzerostruct(params, 1);
	params->fmt = (char *) fmt;
	va_start(args, fmt);
	if (!fmt[0])
		return (0);
	if (fmt[0] == '%' && !fmt[1])
		return (0);
	printed = format_parse(args, fmt, params, 0);
	va_end(args);
	return (printed);
}
