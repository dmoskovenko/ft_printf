/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_oct2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 13:36:52 by releanor          #+#    #+#             */
/*   Updated: 2020/03/20 04:36:11 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*oct_with_prec(t_struct *prms, char *s, int i)
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

char	*oct_hash(t_struct *prms, char *s)
{
	char	*s_hash;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s_hash = (char *)malloc(sizeof(char) \
	* (prms->lenbefore + 2))))
		s_hash = NULL;
	s_hash[i++] = '0';
	while (s[j])
	{
		s_hash[i] = s[j];
		i++;
		j++;
	}
	s_hash[i] = '\0';
	free (s);
	return (s_hash);
}
