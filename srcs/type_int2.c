/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:34:13 by releanor          #+#    #+#             */
/*   Updated: 2020/03/06 12:33:06 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*int_with_prec(t_struct *params, char *s, int i)
{
	char	*s_prec;
	int		j;

	j = 0;
	if (!(s_prec = (char *)malloc(sizeof(char) \
	* (params->precision + 1))))
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

char	*int_overflow_chk(intmax_t num, char *s)
{
	if (num == LLONG_MIN)
	{
		free(s);
		s = "9223372036854775808";
	}
	else if (num == LLONG_MAX)
	{
		free(s);
		s = "9223372036854775807";
	}
	return (s);
}
