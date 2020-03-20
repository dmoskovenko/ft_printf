/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:55:23 by releanor          #+#    #+#             */
/*   Updated: 2020/03/13 02:24:30 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		num_len(intmax_t num, int base)
{
	int		num_len;

	if (!num)
		return (1);
	num_len = 0;
	num = (num < 0) ? -num : num;
	while (num >= 1)
	{
		num /= base;
		num_len++;
	}
	return (num_len);
}

int		unsigned_num_len(uintmax_t num, int base)
{
	uintmax_t		num_len;

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

char	*itoa_base(t_struct *params, intmax_t num, int base)
{
	char	*out;
	int		i;

	i = num_len(num, base);
	params->negative = (num < 0 && base == 10) ? 1 : 0;
	num = (num < 0 && base == 10) ? -num : num;
	if (!(out = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
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

char	*itoa_base_unsigned(uintmax_t num, int base)
{
	char	*out;
	int		i;

	i = unsigned_num_len(num, base);
	if (!(out = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
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
	char	*out;
	int		i;

	i = unsigned_num_len(num, base);
	if (!(out = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
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
