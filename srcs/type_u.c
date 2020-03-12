/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:43:43 by releanor          #+#    #+#             */
/*   Updated: 2020/03/13 02:18:27 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		u_print2(t_struct *params, char *s, int num_length)
{
	if (!params->width && params->dot && s[0] == '0' && num_length == 1)
		return (0);
	else if (params->dot && s[0] == '0' && num_length == 1)
		params->nprinted += write(1, " ", num_length);
	else
		params->nprinted += write(1, s, num_length);
	if (params->width && params->minus)
		while (params->nprinted < params->width)
			params->nprinted += write(1, " ", 1);
	return (1);
}

void	u_print(t_struct *params, char *s, int num_length, int indent)
{
	if (params->width > num_length)
		indent = params->width - num_length;
	if (params->negative || params->plus || params->space)
		indent--;
	if (params->width > num_length && !params->minus)
	{
		while (indent--)
		{
			params->nprinted += (params->zero && !params->precision) \
			? write(1, "0", 1) : \
			write(1, " ", 1);
		}
	}
	if (params->negative)
		params->nprinted += write(1, "-", 1);
	if (params->space && !params->negative)
		params->nprinted += write(1, " ", 1);
	u_print2(params, s, num_length);
}

char	*u_with_prec(t_struct *params, char *s, int num_length, int i)
{
	char	*s_prec;
	int		j;

	j = 0;
	if (!(s_prec = (char *)malloc(sizeof(char) * (params->precision + 1))))
		s_prec = NULL;
	while (i < (params->precision - num_length))
	{
		s_prec[i] = '0';
		i++;
	}
	while (s[j])
	{
		s_prec[i] = s[j];
		i++;
		j++;
	}
	s_prec[i] = '\0';
	return (s_prec);
}

void	u_from_fmt(t_struct *params, uintmax_t num, int i)
{
	char	*s;
	int		num_length;
	int		indent;

	indent = 0;
	num_length = unsigned_num_len(num, 10);
	s = itoa_base_unsigned(num, 10);
	if (params->precision && params->precision > num_length)
	{
		s = u_with_prec(params, s, num_length, i);
//		free(s_prec);
		num_length = ft_strlen(s);
	}
	if (params->plus)
		params->plus = 0;
	if (params->hash)
		params->hash = 0;
	if (params->space)
		params->space = 0;
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
	u_from_fmt(params, num, 0);
}
