/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_oct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:36:52 by releanor          #+#    #+#             */
/*   Updated: 2020/03/12 00:34:36 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	oct_from_fmt(t_struct *params, uintmax_t num)
{
	char	*s;
	char	*s_with_zero;
	int		num_length;
	int		i;
	int		indent;

	i = 0;
	indent = 0;
	num_length = (params->hash == 1) ? (unsigned_num_len(num, 8) + 1) : unsigned_num_len(num, 8);
	s = itoa_base_unsigned(num, 8);

	if (params->hash == 1)
	{
		//num_length++;
		s_with_zero = (char *)malloc(sizeof(char) * (num_length + 1));
		s_with_zero[0] = '0';
		i++;
		while (i < num_length)
		{
			s_with_zero[i] = s[i - 1];
			i++;
		}
		s = s_with_zero;
	}

	if (params->plus)
		params-> plus = 0;
	if (params->space)
		params-> space = 0;
	// if (params->precision /* && !params->minus */)
	// {
	// 	params->zero = 1;
	// 	params->width = params->precision;
	// 	params->minus = 0;
	// 	params->hash = 1;
	// }


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

	// if (params->hash == 1)
	// {
	// 	params->nprinted += write(1, "0", 1);
	// 	num_length--;
	// }

	params->nprinted += write(1, s, num_length);

	if (params->width && params->minus)
		while(params->nprinted < params->width)
			params->nprinted += write(1, " ", 1);

	free(s);
	free(s_with_zero);
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
