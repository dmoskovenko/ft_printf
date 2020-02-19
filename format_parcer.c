/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parcer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 23:35:59 by releanor          #+#    #+#             */
/*   Updated: 2020/02/19 00:12:25 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		format_parse(const char *format, t_struct *list, va_list ap, int pos)
{
	while (format[pos] != '\0')
	{
		if (format[pos] != '%' && format[pos])
			list->nprinted += write(1, &format[pos], 1);
		else if (format[pos] == '%')
		{
			if (!ft_strchr(VALIDSYM, format[pos + 1]))       // need to define VALIDSYM
				break;
			while (ft_strchr(VALIDSYM, format[pos + 1]))
			{
				pos += 1;
				if (ft_strchr("cspdiouxXfyb%", format[pos]))   //we don't need all these identifiers
				{
					pos = parsel2(list, pos, format, ap) + 2;  //maybe change the name of this func
					break;
				}
				else
					pos = parsel2(list, pos, format, ap);
			}
			continue;
		}
		pos++;
	}
	return (list->nprinted);
}