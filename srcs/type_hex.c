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

int		hex_print2(t_struct *params, char *s, int num_length)
{
	if ((!params->width && params->dot && params->zero_arg && params->precisionzero) \
	|| (!params->width && params->dot && !params->precision && !params->precisionzero && params->zero_arg)) 
		return (0);
	if (params->width && params->dot && params->zero_arg && !params->precision)
		params->nprinted += write(1, " ", 1);
	else   
		params->nprinted += write(1, s, num_length);
	if (params->width && params->minus)
		while (params->nprinted < params->width)
			params->nprinted += write(1, " ", 1);
	return (1);
}

void	hex_print(t_struct *params, char *s, int num_length, int indent)
{
	if (params->width > num_length)
		indent = params->width - num_length;
	if (params->negative || params->plus || params->space)
		indent--;
	if (params->hash_case_zero)
	{
		if (params->small_hex == 1)
		{
			params->nprinted = write(1, "0x", 2);
			indent -= 2;
		}
		else
		{
			params->nprinted = write(1, "0X", 2);
			indent -= 2;
		}
	}
	if (params->width > num_length && !params->minus)
	{
		while (indent--)
		{
			params->nprinted += (params->zero && !params->precision) \
			? write(1, "0", 1) : \
			write(1, " ", 1);
				
		}
	}
	if (params->space && !params->negative)
		params->nprinted += write(1, " ", 1);
	hex_print2(params, s, num_length);
}

char	*hex_with_prec(t_struct *params, char *s, int num_length, int i)
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
	free (s);
	return (s_prec);
}


char	*hex_hash(char *s, int num_length, char spec)
{
	char	*s_hash;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s_hash = (char *)malloc(sizeof(char) * (num_length + 3))))
		s_hash = NULL;
	s_hash[i++] = '0';
	if (spec == 'x')
		s_hash[i++] = 'x';
	else
		s_hash[i++] = 'X';
	while (s[j])
	{
		s_hash[i] = s[j];
		i++;
		j++;
	}
	s_hash[i] = '\0';
	free(s);
	return (s_hash);
}

void	hex_hash_chk(t_struct *params, int num, int num_length)
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
}

void	hex_from_fmt(t_struct *params, uintmax_t num, char spec, int i)
{
	char	*s;
	int		num_length;
	int 	indent;

	indent = 0;
	num_length = unsigned_num_len(num, 16);
	params->small_hex = (spec == 'x') ? 1 : 0;
	s = (params->small_hex == 1) ? itoa_base_unsigned(num, 16) : itoa_base_upp(num, 16);
	hex_hash_chk(params, num, num_length);
	if (params->precision > num_length)
		s = hex_with_prec(params, s, num_length, i);
	if (params->hash && params->zero && params->width && !params->precision)
	{
		params->hash_case_zero++;
		params->hash = 0;
	}
	if (params->hash)
	{
		s = hex_hash(s, num_length, spec);
		params->hash = 0;
	}
	num_length = ft_strlen(s);
	if (params->plus)
		params->plus = 0;
	if (params->space)
		params->space = 0;
	hex_print(params, s, num_length, indent);
	free(s);
	bzerostruct(params, 0);
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
	hex_from_fmt(params, num, spec, 0);
}
