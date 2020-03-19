/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_oct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:36:52 by releanor          #+#    #+#             */
/*   Updated: 2020/03/13 04:36:11 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		oct_print2(t_struct *params, char *s, int num_length)
{
	if ((!params->width && params->dot && params->zero_arg && params->precisionzero) \
	|| (!params->width && params->dot && !params->precision && !params->precisionzero && params->zero_arg))
	{
		if (params->hash_case)
		{
			params->nprinted += write(1, "0", 1);
			return (1);
		}
		return (0);
	}
	if (params->width && params->dot && params->zero_arg && !params->precision && !params->hash_case)
		params->nprinted += write(1, " ", 1);
	else   
		params->nprinted += write(1, s, num_length);
	if (params->width && params->minus)
		while (params->nprinted < params->width)
			params->nprinted += write(1, " ", 1);
	return (1);
}

void	oct_print(t_struct *params, char *s, int num_length, int indent)
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
	oct_print2(params, s, num_length);
}

char	*oct_with_prec(t_struct *params, char *s, int num_length, int i)
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

char	*oct_hash(char *s, int num_length)
{
	char	*s_hash;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s_hash = (char *)malloc(sizeof(char) * (num_length + 2))))
		s_hash = NULL;
	s_hash[i++] = '0';
	while (s[j])
	{
		s_hash[i] = s[j];
		i++;
		j++;
	}
	s_hash[i] = '\0';
	return (s_hash);
}

void	oct_hash_chk(t_struct *params, int num, int num_length)
{
	if ((num == 0) && (num_length == 1))
		params->zero_arg++;
	if (!params->width && params->hash && params->dot && params->zero_arg)
		params->hash_case++;
	if (params->hash && params->width && !params->precision && params->zero_arg)
		params->hash_case++;
	if (params->hash && params->dot && !params->precision && !params->precisionzero)
		params->hash = 0;
	if (params->zero_arg)
		params->hash = 0;
	if (params->hash && params->dot && params->precision > num_length)
		params->hash = 0;
}

void	oct_from_fmt(t_struct *params, uintmax_t num, int i)
{
	char	*s;
	int		num_length;
	int		indent;

	indent = 0;
	num_length = unsigned_num_len(num, 8);
	s = itoa_base_unsigned(num, 8);
	oct_hash_chk(params, num, num_length);
	if (params->hash)
		s = oct_hash(s, num_length);
	if (params->precision > num_length)
	{
		s = oct_with_prec(params, s, num_length, i);
//		free(s_prec);
	}
	num_length = ft_strlen(s);
	if (params->plus)
		params->plus = 0;
	if (params->space)
		params->space = 0;
	oct_print(params, s, num_length, indent);
	free(s);
	bzerostruct(params, 0);
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
	oct_from_fmt(params, num, 0);
}
