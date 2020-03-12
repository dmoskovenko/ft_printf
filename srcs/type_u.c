/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:43:43 by releanor          #+#    #+#             */
/*   Updated: 2020/03/11 23:57:32 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_print(t_struct *params, char *s, int num_length, int indent)
{
	if (params->width > num_length)
		indent = params->width - num_length;
	if (params->negative || params->plus || params->space)
		indent--;
	if (params->width > num_length && !params->minus)
	{
		while(indent--)
		{
			params->nprinted += (params->zero) ? write(1, "0", 1) : \
			write(1, " ", 1);
		}
	}
	if (params->negative)
		params->nprinted += write(1, "-", 1);
	if (params->space && !params->negative)
		params->nprinted += write(1, " ", 1);
	params->nprinted += write(1, s, num_length);
	if (params->width && params->minus)
		while(params->nprinted < params->width)
			params->nprinted += write(1, " ", 1);
}

void	u_from_fmt(t_struct *params, uintmax_t num)
{
	char	*s;
	int		num_length;
	int		i;
	int		indent;

	i = 0;
	indent = 0;
	num_length = unsigned_num_len(num, 10);
	s = itoa_base_unsigned(num, 10);
	if (params->plus)
		params-> plus = 0;
	if (params->hash)
		params-> hash = 0;
	if (params->space)
		params-> space = 0;
	if (params->precision /* && !params->minus */)
	{
		params->zero = 1;
		params->width = params->precision;
		params->minus = 0;
	}
	u_print(params, s, num_length, indent);
	free(s);
}

void	type_u(va_list args, t_struct *params)
{
	intmax_t num;
	
	num = 0;
	if (params->length == 0)
		num = (unsigned int)va_arg(args, int);
	if (params->length == SHORTSHORT)
		num = (unsigned char)va_arg(args, int);
	if (params->length == SHORT)
		num = (unsigned short)va_arg(args, int);
	if (params->length == LONG)
		num = (unsigned long)va_arg(args, unsigned long);
	if (params->length == LONGLONG)
		num = (unsigned long long)va_arg(args, unsigned long long);
	u_from_fmt(params, num);
}