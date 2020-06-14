/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 19:26:00 by coclayto          #+#    #+#             */
/*   Updated: 2020/06/14 23:30:13 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_increment(t_struct *params)
{
	long double fbefore;

	fbefore = ft_atof(params->fstrbef);
	fbefore++;
	params->fstrbef = itoa_base_unsigned((uintmax_t)fbefore, 10);
}

int		is_odd(char str)
{
	return ((str - '0') % 2);
}

int		is_infnan(t_struct *params, long double num)
{
	if (num == (1.0 / 0.0) || num == -(1.0 / 0.0))
	{
		params->nprinted_here = write(1, "inf", 3);
		return (1);
	}
	if (!(num == num))
	{
		params->plus = 0;
		params->nprinted_here = write(1, "nan", 3);
		return (1);
	}
	return (0);
}
