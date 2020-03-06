/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_oct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:36:52 by releanor          #+#    #+#             */
/*   Updated: 2020/03/03 05:54:11 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	oct_from_fmt(t_struct *params, unsigned int num)
{
	char	*s;
	int		num_length;
	int		i;

	i = 0;
	num_length = num_len(num, 8);
	s = itoa_base_unsigned(num, 8);
	params->nprinted = write(1, s, num_length);
	free(s);
}

void	type_oct(va_list args, t_struct *params)
{
	// Length specifiers handling.
	unsigned long long num;
	
	num = 0;
	if (params->length == 0)
		num = va_arg(args, unsigned int);
	if (params->length == SHORTSHORT)
		num = (signed char)va_arg(args, unsigned int);
	if (params->length == SHORT)
		num = (short int)va_arg(args, unsigned int);
	if (params->length == LONG)
		num = (unsigned long)va_arg(args, unsigned long);
	if (params->length == LONGLONG)
		num = (unsigned long long)va_arg(args, unsigned long long);
	oct_from_fmt(params, num);
}
