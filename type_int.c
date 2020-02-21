/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:34:13 by releanor          #+#    #+#             */
/*   Updated: 2020/02/21 15:22:47 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pos_num_len(int num, int base)
{
	int		num_len;

	num_len = 0;
	num = (num < 0) ? -num : num;
	while (num >= 1)
	{
		num /= base;
		num_len++;
	}
	return (num_len);
}

char	*itoa_base(int num, int base)  //китаец юзает intmax_t, интересно, ёк-макарёк, почему?
{
	char 	*out;
	int 	i;
	int		is_neg;

	i = pos_num_len(num, base);
	is_neg = (num < 0 && base == 10) ? 1 : 0;
	num = (num < 0 && base == 10) ? -num : num;
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

void	int_from_fmt(t_struct params, int num)
{
	char	*s;
	int		num_len;
	int		i;

	i = 0;
	if (params.length == 666)
		write(1, "$", 1);
	num_len = pos_num_len(num, 10);
	s = itoa_base(num, 10);
	if (s[0] == '-')
		num_len++;
	write(1, s, num_len);
}

void	type_int(va_list args, t_struct params)
{
	// Length specifiers for this type: h, hh, l, ll.
	// Length specifiers handling.
	int num;
	
	num = 0;
	if (params.length == 0)
		num = (int)va_arg(args, int);
	int_from_fmt(params, num);
}

