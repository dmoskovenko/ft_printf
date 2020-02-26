/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:15:37 by releanor          #+#    #+#             */
/*   Updated: 2020/02/21 17:51:13 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/includes/libft.h"

# define VALIDSYM		"cspdiouxXfhl0123456789 %#-+."
# define LENGHTFLAGS	"hlL"
# define SHORT			1
# define SHORTSHORT		2
# define LONG			3
# define LONGLONG		4
# define LONGDOUBLE		7

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

int		ft_printf(const char *fmt, ...);
int		format_parse(va_list args, const char *fmt, t_struct params, int pos);
int		conversions(va_list args, char spec, t_struct params);
int		modifiers(va_list args, const char *fmt, t_struct params);
void	length_field(const char *fmt, t_struct params);

void	type_char(va_list args, t_struct params);

int		pos_num_len(int num, int base);
char	*itoa_base(int num, int base);

void	type_int(va_list args, t_struct params);
void	int_from_fmt(t_struct params, int num);

void	writezeros(int n);
void	writeblanks(int n);

t_struct	bzerostruct(t_struct params, int full);

#endif
