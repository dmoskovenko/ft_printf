/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parcer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 23:35:59 by releanor          #+#    #+#             */
/*   Updated: 2020/02/20 09:16:53 by coclayto         ###   ########.fr       */
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