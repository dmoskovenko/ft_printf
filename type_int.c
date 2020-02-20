/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:34:13 by releanor          #+#    #+#             */
/*   Updated: 2020/02/20 23:06:42 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*itoa_base(int num, int base)  //китаец юзает intmax_t, интересно, ёк-макарёк, почему?
{
	char 	*out;
	int 	i;
	int		is_neg;
	int     tmp;

	i = 0;
	tmp = (num < 0 && base == 10) ? -num : num;
	is_neg = (num < 0 && base == 10) ? 1 : 0;
	num = tmp;
	while (tmp >= 1)
	{
	    tmp /= base;
		i++;
	}
	out = (char *)malloc(sizeof(char) * (is_neg + i + 1));
	out[i-- + is_neg] = '\0';
	while (i >= 0)
	{
		out[i + is_neg] = (num % base < 10) ? (num % base) + '0' : \
		(num % base + 'A' - 10);
		num /= base;
		i--;
	}
    out[0] = (is_neg == 1) ? '-' : out[0];
	return (out);
}

void	type_int(args, params)
{
	
}

