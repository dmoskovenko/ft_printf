/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ptr2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:45:48 by releanor          #+#    #+#             */
/*   Updated: 2020/06/16 22:47:47 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ptr_chk(t_struct *prms)
{
	if (prms->zero && prms->dot)
		prms->zero = 0;
	if (prms->width > prms->precision)
	{
		prms->precision = 0;
		prms->precision_was = 1;
	}
	if (prms->precision > prms->width)
		prms->width = 0;
	if (prms->width > prms->lenbefore)
	{
		prms->indent = prms->width - prms->precision \
		- prms->lenbefore - prms->plus - 2;
	}
}
