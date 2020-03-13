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
	if (!params->width && params->dot && /*params->hash && */ s[0] == '0' && num_length == 1)
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

void	oct_from_fmt(t_struct *params, uintmax_t num, int i)
{
	char	*s;
	int		num_length;
	int		indent;

	indent = 0;
	num_length = unsigned_num_len(num, 8);
	s = itoa_base_unsigned(num, 8);
	// if (params->hash && num == 0 && params->dot) // || (params->hash && params->dot))
	// 	params->hash = 0;
	if (params->hash)
		s = oct_hash(s, num_length);
	if (params->precision && params->precision > num_length && !params->hash)
	{
		s = oct_with_prec(params, s, num_length, i);
//		free(s_prec);
	}
	else if (params->precision && params->precision > num_length && params->hash)
	{
		s = oct_with_prec(params, s, num_length + 1, i);
//		free(s_prec);
	}
	num_length = ft_strlen(s);
	if (params->plus)
		params->plus = 0;
	if (params->hash)
		params->hash = 0;
	if (params->space)
		params->space = 0;
	oct_print(params, s, num_length, indent);
	free(s);
}







// void	oct_from_fmt(t_struct *params, uintmax_t num)
// {
// 	char	*s;
// 	char	*s_with_zero;
// 	int		num_length;
// 	int		i;
// 	int		indent;

// 	i = 0;
// 	indent = 0;
// 	num_length = (params->hash == 1) ? (unsigned_num_len(num, 8) + 1) : unsigned_num_len(num, 8);
// 	s = itoa_base_unsigned(num, 8);

// 	if (params->hash == 1)
// 	{
// 		//num_length++;
// 		s_with_zero = (char *)malloc(sizeof(char) * (num_length + 1));
// 		s_with_zero[0] = '0';
// 		i++;
// 		while (i < num_length)
// 		{
// 			s_with_zero[i] = s[i - 1];
// 			i++;
// 		}
// 		s = s_with_zero;
// 	}

// 	if (params->plus)
// 		params-> plus = 0;
// 	if (params->space)
// 		params-> space = 0;
// 	// if (params->precision /* && !params->minus */)
// 	// {
// 	// 	params->zero = 1;
// 	// 	params->width = params->precision;
// 	// 	params->minus = 0;
// 	// 	params->hash = 1;
// 	// }


// 	if (params->width > num_length)
// 		indent = params->width - num_length;
// 	if (params->negative || params->plus || params->space)
// 		indent--;
// 	if (params->width > num_length && !params->minus)
// 	{
// 		while(indent--)
// 		{
// 			params->nprinted += (params->zero) ? write(1, "0", 1) : \
// 			write(1, " ", 1);
// 		}
// 	}
// 	if (params->negative)
// 		params->nprinted += write(1, "-", 1);
// 	if (params->space && !params->negative)
// 		params->nprinted += write(1, " ", 1);

// 	// if (params->hash == 1)
// 	// {
// 	// 	params->nprinted += write(1, "0", 1);
// 	// 	num_length--;
// 	// }

// 	params->nprinted += write(1, s, num_length);

// 	if (params->width && params->minus)
// 		while(params->nprinted < params->width)
// 			params->nprinted += write(1, " ", 1);

// 	free(s);
// 	free(s_with_zero);
// }

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
