/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:46:52 by releanor          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/03/03 04:55:17 by coclayto         ###   ########.fr       */
=======
/*   Updated: 2020/03/02 22:41:04 by releanor         ###   ########.fr       */
>>>>>>> 616f79774c1c2ee394a6f3f5db8bb21131611cec
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	length_field(const char *fmt, t_struct *params)
{
	int i;

	i = params->i;
	if (ft_strchr(LENGHTFLAGS, fmt[i]))
	{
		if (fmt[i] == 'h')
<<<<<<< HEAD
			params->length = SHORT;
		else if (fmt[i] == 'h' && fmt[i + 1] == 'h')
			params->length = SHORTSHORT;
		if (fmt[i] == 'l')
			params->length = LONG;
		else if (fmt[i] == 'l' && fmt[i + 1] == 'l')
			params->length = LONGLONG;
=======
			params.length = SHORT;
		if (fmt[i] == 'h' && fmt[i + 1] == 'h')
			params.length = SHORTSHORT;
		if (fmt[i] == 'l')
			params.length = LONG;
		if (fmt[i] == 'l' && fmt[i + 1] == 'l')
			params.length = LONGLONG;
>>>>>>> 616f79774c1c2ee394a6f3f5db8bb21131611cec
		if (fmt[i] == 'L')
			params->length = LONGDOUBLE;
	}
	while (ft_strchr(LENGHTFLAGS, fmt[i]))
		i++;
	params->i = i;
}

int		modifiers(va_list args, const char *fmt, t_struct *params)
{
	// Flags
	// Width
	// Precision
	if (args == NULL)
		return (0);
	length_field(fmt, params);
	return (params->i);
}