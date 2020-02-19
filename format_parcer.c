/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parcer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 23:35:59 by releanor          #+#    #+#             */
/*   Updated: 2020/02/19 18:01:14 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		format_parse2(t_struct *new_struct, int position, const char *fmt, va_list params)
{
	new_struct->i = position;
	// if (!ft_strchr("cspdiouxXfyb%", fmt[position]))
	// 	modifiers(fmt, new_struct, params);
	/*else*/ if (ft_strchr(("cspdiouxXfyb%"), fmt[position]))
	{
		conversions(fmt[position], params, new_struct);
		//bezerostruct2(new_struct);
	}
	return (new_struct->i - 1);
}

int		format_parse(const char *fmt, t_struct *new_struct, va_list params, int pos)
{
	while (fmt[pos] != '\0')
	{
		if (fmt[pos] != '%' && fmt[pos])
			new_struct->nprinted += write(1, &fmt[pos], 1);
		else if (fmt[pos] == '%')
		{
			if (!ft_strchr(/*ALLSYMBOLS*/ "cspdiouxXfyb%#-+ .*0123456789hLljz", fmt[pos + 1]))       // need to define ALLSYMBOLS
				break;
			while (ft_strchr(/*ALLSYMBOLS*/ "cspdiouxXfyb%#-+ .*0123456789hLljz", fmt[pos + 1]))
			{
				pos += 1;
				if (ft_strchr("cspdiouxXfyb%", fmt[pos]))   //we don't need all these identifiers
				{
					pos = format_parse2(new_struct, pos, fmt, params) + 2;  //maybe change the name of this func
					break;
				}
				else
					pos = format_parse2(new_struct, pos, fmt, params);
			}
			continue;
		}
		pos++;
	}
	return (new_struct->nprinted);
}

