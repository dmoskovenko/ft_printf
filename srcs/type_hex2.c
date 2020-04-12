/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hex2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 11:55:06 by releanor          #+#    #+#             */
/*   Updated: 2020/03/20 20:00:16 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hex_with_prec(t_struct *params, char *s, int i)
{
	char	*s_prec;
	int		j;

	j = 0;
	if (!(s_prec = (char *)malloc(sizeof(char) * \
	(params->precision + 1))))
		s_prec = NULL;
	while (i < (params->precision - params->lenbefore))
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
	free(s);
	return (s_prec);
}

char	*hex_hash(t_struct *params, char *s)
{
	char	*s_hash;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s_hash = (char *)malloc(sizeof(char) \
	* (params->lenbefore + 3))))
		s_hash = NULL;
	s_hash[i++] = '0';
	if (params->small_hex)
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

void	hex_hash_chk(t_struct *params, int num)
{
	if ((num == 0) && (params->lenbefore == 1))
		params->zero_arg++;
	if (!params->width && params->hash && \
	params->dot && params->zero_arg)
		params->hash_case++;
	if (params->hash && params->width && \
	!params->precision && params->zero_arg)
		params->hash_case++;
	if (params->hash && params->dot && \
	!params->precision && !params->precisionzero)
		params->hash = 0;
	if (params->zero_arg)
		params->hash = 0;
}
