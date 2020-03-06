/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_oct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:36:52 by releanor          #+#    #+#             */
/*   Updated: 2020/03/06 20:25:22 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	oct_from_fmt(t_struct *params, uintmax_t num)
{
	char	*s;
	int		num_length;
	int		i;

	i = 0;
	num_length = unsigned_num_len(num, 8);
	s = itoa_base_unsigned(num, 8);
	if (params->hash == 1)
		params->nprinted = write(1, "0", 1);
	params->nprinted = write(1, s, num_length);
	free(s);
}

void	type_oct(va_list args, t_struct *params)
{
	uintmax_t num;
	
	num = 0;
	if (params->length == 0)
		num = va_arg(args, unsigned int);
	if (params->length == SHORTSHORT)
		num = (unsigned char)va_arg(args, unsigned int);
	if (params->length == SHORT)
		num = (unsigned short)va_arg(args, unsigned int);
	if (params->length == LONG)
		num = (unsigned long)va_arg(args, unsigned long);
	if (params->length == LONGLONG)
		num = (unsigned long long)va_arg(args, unsigned long long);
	oct_from_fmt(params, num);
}
