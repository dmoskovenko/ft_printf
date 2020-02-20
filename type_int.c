/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:34:13 by releanor          #+#    #+#             */
/*   Updated: 2020/02/20 22:38:47 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*itoa_base(int num, int base)  //китаец юзает intmax_t, интересно, ёк-макарёк, почему?
{
	char 	*result;
	int 	i;
	int		is_neg;
	int     tmp;

	i = 0;
	tmp = (num < 0 && base == 10) ? -num : num;
	is_neg = (num < 0 && base == 10) ? 1 : 0;
	num = (num < 0 && base == 10) ? -num : num;
	while (tmp >= 1)
	{
	    tmp = tmp / base;
		i++;
	}
	result = (char *)malloc(sizeof(char) * (is_neg + i + 1));
	result[i-- + is_neg] = '\0';
	while (i >= 0)
	{
		result[i + is_neg] = (num % base) + '0';
		num /= base;
		i--;
	}
    result[0] = (is_neg == 1) ? '-' : result[0];
	return (result);
}
