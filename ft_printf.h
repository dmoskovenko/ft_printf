/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:15:37 by releanor          #+#    #+#             */
/*   Updated: 2020/02/19 00:39:48 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define VALIDSYM		"cspdiouxXfhl0123456789 %#-+."
# include <stdarg.h>
# include <stdio.h>
# include "libft/includes/libft.h"

typedef struct	s_struct
{
	char		*fmt;
	int			nprinted;
	int			i;
	int			len;
	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			hash;
	int			width;
	int			precisiontf;
	int			precision;
	int			length;
}				t_struct;

#endif
