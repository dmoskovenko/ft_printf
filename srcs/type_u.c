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

int		u_print2(t_struct *prms, char *s)
{
	if (!prms->width && prms->dot && s[0] == '0' \
	&& prms->lenbefore == 1)
		return (0);
	else if (prms->dot && s[0] == '0' && prms->lenbefore == 1)
		prms->nprinted_here += write(1, " ", prms->lenbefore);
	else
		prms->nprinted_here += write(1, s, prms->lenbefore);
	if (prms->width && prms->minus)
		while (prms->nprinted_here < prms->width)
			prms->nprinted_here += write(1, " ", 1);
	return (1);
}

void	u_print(t_struct *prms, char *s, int indent)
{
	if (prms->width > prms->lenbefore)
		indent = prms->width - prms->lenbefore;
	if (prms->negative || prms->plus || prms->space)
		indent--;
	if (prms->width > prms->lenbefore && !prms->minus)
	{
		while (indent--)
		{
			prms->nprinted_here += (prms->zero && \
			!prms->precision) ? write(1, "0", 1) : \
			write(1, " ", 1);
		}
	}
	if (prms->negative)
		prms->nprinted_here += write(1, "-", 1);
	if (prms->space && !prms->negative)
		prms->nprinted_here += write(1, " ", 1);
	u_print2(prms, s);
}

char	*u_with_prec(t_struct *prms, char *s, int i)
{
	char	*s_prec;
	int		j;

	j = 0;
	if (!(s_prec = (char *)malloc(sizeof(char) * \
	(prms->precision + 1))))
		s_prec = NULL;
	while (i < (prms->precision - prms->lenbefore))
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

void	u_from_fmt(t_struct *prms, uintmax_t num, int i)
{
	char	*s;

	prms->lenbefore = unsigned_num_len(num, 10);
	s = itoa_base_unsigned(num, 10);
	if (prms->precision && prms->precision > prms->lenbefore)
	{
		s = u_with_prec(prms, s, i);
		prms->lenbefore = ft_strlen(s);
	}
	if (prms->plus)
		prms->plus = 0;
	if (prms->hash)
		prms->hash = 0;
	if (prms->space)
		prms->space = 0;
	u_print(prms, s, 0);
	prms->nprinted += prms->nprinted_here;
	free(s);
	bzerostruct(prms, 0);
}

void	type_u(va_list args, t_struct *prms, char spec)
{
	uintmax_t num;

	num = 0;
	if (prms->length == 0 && spec == 'u')
		num = (unsigned int)va_arg(args, int);
	else if (prms->length == SHORTSHORT && spec == 'u')
		num = (unsigned char)va_arg(args, int);
	else if (prms->length == SHORT && spec == 'u')
		num = (unsigned short)va_arg(args, int);
	else if (prms->length == LONG || spec == 'U')
		num = (unsigned long)va_arg(args, unsigned long);
	else if (prms->length == LONGLONG)
		num = (unsigned long long)va_arg(args, \
		unsigned long long);
	if (prms->length == SIZET)
		num = (size_t)va_arg(args, size_t);
	if (prms->length == INTUINTMAX)
		num = (uintmax_t)va_arg(args, uintmax_t);
	u_from_fmt(prms, num, 0);
}
