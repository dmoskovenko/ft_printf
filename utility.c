/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:55:23 by releanor          #+#    #+#             */
/*   Updated: 2020/03/02 22:40:23 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		num_len(int num, int base)
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

int		unsigned_num_len(unsigned int num, int base)
{
	int		num_len;

	num_len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= base;
		num_len++;
	}
	return (num_len);
}

char	*itoa_base(intmax_t num, int base)
{
	char 	*out;
	int 	i;
	int		is_neg;

	i = num_len(num, base);
	is_neg = (num < 0 && base == 10) ? 1 : 0;
	num = (num < 0 && base == 10) ? -num : num;
	out = (char *)malloc(sizeof(char) * (is_neg + i + 1));
	out[i-- + is_neg] = '\0';
	while (i >= 0)
	{
		out[i + is_neg] = (num % base < 10) ? (num % base) + '0' : \
		(num % base + 'a' - 10);
		num /= base;
		i--;
	}
    out[0] = (is_neg == 1) ? '-' : out[0];
	return (out);
}

char	*itoa_base_unsigned(uintmax_t num, int base)
{
	char 	*out;
	int 	i;

	i = unsigned_num_len(num, base);
	out = (char *)malloc(sizeof(char) * (i + 1));
	out[i--] = '\0';
	while (i >= 0)
	{
		out[i] = (num % base < 10) ? (num % base) + '0' : \
		(num % base + 'a' - 10);
		num /= base;
		i--;
	}
	return (out);
}

char	*itoa_base_upp(uintmax_t num, int base)
{
	char 	*out;
	int 	i;

	i = unsigned_num_len(num, base);
	out = (char *)malloc(sizeof(char) * (i + 1));
	out[i--] = '\0';
	while (i >= 0)
	{
		out[i] = (num % base < 10) ? (num % base) + '0' : \
		(num % base + 'A' - 10);
		num /= base;
		i--;
	}
	return (out);
}