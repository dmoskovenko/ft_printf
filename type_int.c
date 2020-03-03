/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:34:13 by releanor          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/03/03 04:56:57 by coclayto         ###   ########.fr       */
=======
/*   Updated: 2020/03/02 22:39:45 by releanor         ###   ########.fr       */
>>>>>>> 616f79774c1c2ee394a6f3f5db8bb21131611cec
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

<<<<<<< HEAD
int		pos_num_len(int num, int base)
{
	int		num_len;

	num_len = 0;
	num = (num < 0) ? -num : num;
	while (num >= 1)
	{
		num /= base;
		num_len++;
	}
	return (num_len);
}

char	*itoa_base(int num, int base)  //китаец юзает intmax_t, интересно, ёк-макарёк, почему?
{
	char 	*out;
	int 	i;
	int		is_neg;

	i = pos_num_len(num, base);
	is_neg = (num < 0 && base == 10) ? 1 : 0;
	num = (num < 0 && base == 10) ? -num : num;
	out = (char *)malloc(sizeof(char) * (is_neg + i + 1));
	out[i-- + is_neg] = '\0';
	while (i >= 0)
	{
		out[i + is_neg] = (num % base < 10) ? (num % base) + '0' : \
		(num % base + 'A' - 10);
		num /= base;
		i--;
	}
    out[0] = (is_neg == 1) ? '-' : out[0];
	return (out);
}

void	int_from_fmt(t_struct *params, int num)
=======
void	int_from_fmt(t_struct params, int num)
>>>>>>> 616f79774c1c2ee394a6f3f5db8bb21131611cec
{
	char	*s;
	int		num_length;
	int		i;

	i = 0;
	// if (params->length == 666)
	// 	write(1, "$", 1);
	num_length = num_len(num, 10);
	s = itoa_base(num, 10);
	if (s[0] == '-')
<<<<<<< HEAD
		num_len++;
	params->nprinted = write(1, s, num_len);
=======
		num_length++;
	params.nprinted = write(1, s, num_length);
>>>>>>> 616f79774c1c2ee394a6f3f5db8bb21131611cec
	free(s);
}

void	type_int(va_list args, t_struct *params)
{
	// Length specifiers handling.
	int num;
	
	num = 0;
<<<<<<< HEAD
	if (params->length == SHORTSHORT)
=======
	if (params.length == 0)
		num = (int)va_arg(args, int);
	if (params.length == SHORTSHORT)
>>>>>>> 616f79774c1c2ee394a6f3f5db8bb21131611cec
		num = (signed char)va_arg(args, int);
	if (params->length == SHORT)
		num = (short int)va_arg(args, int);
	if (params->length == LONG)
		num = (long int)va_arg(args, int);
	if (params->length == LONGLONG)
		num = (long long int)va_arg(args, int);
<<<<<<< HEAD
	if (params->length == 0)
		num = (int)va_arg(args, int);
=======
>>>>>>> 616f79774c1c2ee394a6f3f5db8bb21131611cec
	int_from_fmt(params, num);
}
