/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parcer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 23:35:59 by releanor          #+#    #+#             */
/*   Updated: 2020/02/19 17:18:42 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		format_parse(const char *format, t_struct *new_struct, va_list params, int pos)
{
	while (format[pos] != '\0')
	{
		if (format[pos] != '%' && format[pos])
			new_struct->nprinted += write(1, &format[pos], 1);
		else if (format[pos] == '%')
		{
			if (!ft_strchr(ALLSYMBOLS, format[pos + 1]))       // need to define ALLSYMBOLS
				break;
			while (ft_strchr(ALLSYMBOLS, format[pos + 1]))
			{
				pos += 1;
				if (ft_strchr("cspdiouxXfyb%", format[pos]))   //we don't need all these identifiers
				{
					pos = parsel2(new_struct, pos, format, params) + 2;  //maybe change the name of this func
					break;
				}
				else
					pos = parsel2(new_struct, pos, format, params);
			}
			continue;
		}
		pos++;
	}
	return (new_struct->nprinted);
}
