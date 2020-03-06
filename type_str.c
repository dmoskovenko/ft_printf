/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:38:17 by releanor          #+#    #+#             */
/*   Updated: 2020/03/06 14:34:54 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_str(va_list args, t_struct *params)
{
	char	*s;
	int		str_len;

	s = (char *)va_arg(args, char *);
	str_len = ft_strlen(s);
	params->nprinted = write(1, s, str_len);
}