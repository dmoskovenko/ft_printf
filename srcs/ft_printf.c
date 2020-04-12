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
	exit(1);
}

int		parse_normal(va_list args, t_struct *prms, const char *fmt)
{
	prms->i++;
	if (ft_strchr(TYPESYM, fmt[prms->i]))
	{
		prms->i = conversions(args, fmt[prms->i], prms) + 1;
		prms->after_percent = 0;
		return (0);
	}
	else if (ft_strchr(FLAGS, fmt[prms->i]) || ft_isdigit(fmt[prms->i]))
	{
		prms->i = modifiers(args, fmt, prms) - 1;
		if (prms->i > (int)ft_strlen(fmt) - 1 && fmt[prms->i] != '\0')
		{
			prms->i--;
			return (0);
		}
	}
	return (1);
}

int		parse_text_after_percent(t_struct *prms, const char *fmt)
{
	if (fmt[prms->i] == '%')
		prms->i++;
	if (fmt[prms->i] == ' ' && prms->i == 1)
	{
		if (fmt[prms->i + 1] == '\0')
			return (0);
		prms->i++;
	}
	while (ft_strchr(FLAGS, fmt[prms->i]))
		prms->i++;
	if (fmt[prms->i] == '\0')
		exit(0);
	if (fmt[prms->i + 1] == '%' && fmt[prms->i + 2] != '\0')
	{
		return (0);
		prms->i--;
	}
	prms->nprinted += write(1, &fmt[prms->i], 1);
	prms->after_percent = 0;
	prms->i++;
	return (1);
}

int		format_parse(va_list args, const char *fmt, t_struct *prms)
{
	prms->after_percent = 0;
	while (fmt[prms->i] && prms->i < (int)ft_strlen(fmt))
	{
		if (fmt[prms->i] != '%' && fmt[prms->i])
			prms->nprinted += write(1, &fmt[prms->i], 1);
		else if (fmt[prms->i] == '%')
		{
			if (!ft_strchr(VALIDSYM, fmt[prms->i + 1]) && prms->after_percent)
				break ;
			prms->after_percent = 1;
			while (ft_strchr(VALIDSYM, fmt[prms->i + 1]) \
			&& prms->i < (int)ft_strlen(fmt))
				if (!parse_normal(args, prms, fmt))
					break ;
			while (!ft_strchr("%", fmt[prms->i + 1]) \
			&& prms->i < (int)ft_strlen(fmt) && prms->after_percent)
				if (!parse_text_after_percent(prms, fmt))
					break ;
			continue;
		}
		prms->i++;
	}
	return (prms->nprinted);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		args;
	t_struct	*params;
	int			printed;

	if (!(params = (t_struct *)malloc(sizeof(t_struct))))
		return (0);
	bzerostruct(params, 1);
	params->fmt = (char *)fmt;
	va_start(args, fmt);
	if (!fmt[0])
		return (0);
	if (fmt[0] == '%' && !fmt[1])
		return (0);
	printed = format_parse(args, fmt, params);
	va_end(args);
	free(params);
	return (printed);
}
