/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:53:04 by coclayto          #+#    #+#             */
/*   Updated: 2020/03/15 15:25:55 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	params->nprinted_here = 0;
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
	params->precision = 0;
	params->precision_was = 0;
	params->indent = 0;
	params->indent_was = 0;
	params->precisionzero = 0;
	params->length = 0;
	params->lenbefore = 0;
	params->after_percent = 0;
}

int		format_parse(va_list args, const char *fmt, t_struct *params, int pos)
{
	while (fmt[pos] && pos < (int)ft_strlen(fmt))
	{

		if (fmt[pos] != '%' && fmt[pos])
			params->nprinted += write(1, &fmt[pos], 1);
		else if (fmt[pos] == '%')
		{
			
			if (!ft_strchr(VALIDSYM, fmt[pos + 1]) && params->after_percent)
				break;
			params->after_percent = 1;
			while (ft_strchr(VALIDSYM, fmt[pos + 1]) && pos < (int)ft_strlen(fmt))
			{
				pos++;
				params->i = pos;
			
				if (ft_strchr(TYPESYM, fmt[pos]))
				{
					pos = conversions(args, fmt[pos], params) + 1;
					params->after_percent = 0;
					break;
				}
				else if (ft_strchr(FLAGS, fmt[pos]) || ft_isdigit(fmt[pos]))
				{
					pos = modifiers(args, fmt, params) - 1;
					if (pos > (int)ft_strlen(fmt) - 1 && fmt[pos] != '\0')
					{
						pos--;
						break;
					}
				}
			}
			while (!ft_strchr("%", fmt[pos + 1]) && pos < (int)ft_strlen(fmt) && params->after_percent)
			{
				if (fmt[pos] == '%')
					pos++;
				if (fmt[pos] == ' ' && pos == 1)
				{
					if (fmt[pos + 1] == '\0')
						break;
					pos++;
				}
				while (ft_strchr(FLAGS, fmt[pos]))
					pos++;
			
				if (fmt[pos] == '\0')
					exit(0);
				if (fmt[pos + 1] == '%' && fmt[pos + 2] != '\0')
				{
					break;
					pos--;
				}
				params->nprinted += write(1, &fmt[pos], 1);
				params->after_percent = 0;
				 pos++;
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
	free(params);
	return (printed);
}
