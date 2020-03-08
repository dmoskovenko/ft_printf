/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:34:13 by releanor          #+#    #+#             */
/*   Updated: 2020/03/06 12:33:06 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_from_fmt(t_struct *params, intmax_t num)
{
	char	*s;
	int		num_length;
	int		i;

	i = 0;
	num_length = num_len(num, 10);
	s = itoa_base(num, 10);
	if (s[0] == '-')
		num_length++;
	params->nprinted = write(1, s, num_length);
	free(s);
}

void	type_int(va_list args, t_struct *params)
{
	intmax_t num;
	
	num = 0;
	if (params->length == 0)
		num = (int)va_arg(args, int);
	if (params->length == SHORTSHORT)
		num = (signed char)va_arg(args, int);
	if (params->length == SHORT)
		num = (short int)va_arg(args, int);
	if (params->length == LONG)
		num = (long int)va_arg(args, long int);
	if (params->length == LONGLONG)
		num = (long long int)va_arg(args, long long int);
	int_from_fmt(params, num);
}
