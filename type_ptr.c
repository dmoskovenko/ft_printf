/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:45:48 by releanor          #+#    #+#             */
/*   Updated: 2020/03/06 14:58:36 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_ptr(va_list args, t_struct *params)
{
	uintmax_t	ptr;
	int			ptr_len;
	char		*s;

	ptr = (uintmax_t)va_arg(args, void *);
	s = itoa_base_unsigned(ptr, 16);
	ptr_len = unsigned_num_len(ptr, 16);
	params->nprinted = write(1, "0x", 2);
	params->nprinted = write(1, s, ptr_len);
}