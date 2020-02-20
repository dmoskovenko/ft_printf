/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:15:37 by releanor          #+#    #+#             */
/*   Updated: 2020/02/20 22:06:45 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define VALIDSYM		"cspdiouxXfhl0123456789 %#-+."
# include <stdarg.h>
# include <unistd.h>
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

int			ft_printf(const char *fmt, ...);
int			format_parse(va_list args, const char *fmt, t_struct params, int pos);
int			conversions(va_list args, char fmt, t_struct params);
void		type_char(va_list args, t_struct params);
void		writezeros(int n);
void		writeblanks(int n);
t_struct	bzerostruct(t_struct params, int full);

#endif
