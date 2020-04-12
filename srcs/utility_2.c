/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:53:04 by coclayto          #+#    #+#             */
/*   Updated: 2020/03/15 15:25:55 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			bzerostruct(t_struct *params, int full)
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
}

long double		power(long long n, int i)
{
	long long	j;
	long double	res;

	j = 0;
	res = n;
	if (!i)
		return (1);
	while (j++ < (i - 1))
		res *= n;
	return (res);
}

void			percent(t_struct *params)
{
	char_print(params, '%', 0);
	bzerostruct(params, 0);
}
