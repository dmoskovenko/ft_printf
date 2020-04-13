/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:54:23 by releanor          #+#    #+#             */
/*   Updated: 2020/03/06 14:53:35 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conversions(va_list args, char spec, t_struct *params)
{
	if (spec == 'c' || spec == 'C')
		type_char(args, params);
	else if (spec == 's' || spec == 'S')
		type_str(args, params);
	else if (spec == 'p' || spec == 'P')
		type_ptr(args, params);
	else if (spec == 'd' || spec == 'i' || spec == 'D' || spec == 'I')
		type_int(args, params);
	else if (spec == 'u' || spec == 'U')
		type_u(args, params, spec);
	else if (spec == 'x' || spec == 'X')
		type_hex(args, params, spec);
	else if (spec == 'f' || spec == 'F')
		type_float(args, params);
	else if (spec == 'o' || spec == 'O')
		type_oct(args, params);
	else if (spec == '%')
		percent(params);
	else if (spec == 'r')
		create_nonprint_str(args, params);
	else
		bzerostruct(params, 0);
	return (params->i);
}
