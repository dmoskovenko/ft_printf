/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:34:13 by releanor          #+#    #+#             */
/*   Updated: 2020/03/02 12:56:08 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_from_fmt(t_struct params, int num)
{
	char	*s;
	int		num_len;
	int		i;

	i = 0;
	// if (params.length == 666)
	// 	write(1, "$", 1);
	num_len = pos_num_len(num, 10);
	s = itoa_base(num, 10);
	if (s[0] == '-')
		num_len++;
	params.nprinted = write(1, s, num_len);
	free(s);
}

void	type_int(va_list args, t_struct params)
{
	// Length specifiers handling.
	int num;
	
	num = 0;
	if (params.length == SHORTSHORT)
		num = (signed char)va_arg(args, int);
	if (params.length == SHORT)
		num = (short int)va_arg(args, int);
	if (params.length == LONG)
		num = (long int)va_arg(args, int);
	if (params.length == LONGLONG)
		num = (long long int)va_arg(args, int);
	if (params.length == 0)
		num = (int)va_arg(args, int);
	int_from_fmt(params, num);
}
