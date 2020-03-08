/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:55:06 by releanor          #+#    #+#             */
/*   Updated: 2020/03/06 20:00:16 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_from_fmt(t_struct *params, uintmax_t num, char spec)
{
	char	*s;
	int		num_length;
	int		i;

	i = 0;
	num_length = unsigned_num_len(num, 16);
	s = (spec == 'x') ? itoa_base_unsigned(num, 16) : itoa_base_upp(num, 16);
	if (params->hash == 1 && spec == 'x' && num)
		params->nprinted = write(1, "0x", 2);
	else if (params->hash == 1 && spec == 'X' && num)
		params->nprinted = write(1, "0X", 2);
	params->nprinted = write(1, s, num_length);
	free(s);
}

void	type_hex(va_list args, t_struct *params, char spec)
{
	uintmax_t num;
	
	num = 0;
	if (!params->length)
		num = va_arg(args, unsigned int);
	if (params->length == SHORTSHORT)
		num = (unsigned char)va_arg(args, unsigned int);
	if (params->length == SHORT)
		num = (unsigned short)va_arg(args, unsigned int);
	if (params->length == LONG)
		num = (unsigned long)va_arg(args, unsigned long);
	if (params->length == LONGLONG)
		num = (unsigned long long)va_arg(args, unsigned long long);
	hex_from_fmt(params, num, spec);
}