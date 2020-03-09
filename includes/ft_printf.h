/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:15:37 by releanor          #+#    #+#             */
/*   Updated: 2020/03/09 08:31:01 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "../libft/includes/libft.h"

# define VALIDSYM		"cCsSpPdDiIoOuUxXfFhlL0123456789 %#-+."
# define TYPESYM		"cCsSpPdDiIoOuUxXfF"
# define FLAGS			" -+#0hlL"
# define SHORT			1
# define SHORTSHORT		2
# define LONG			3
# define LONGLONG		4
# define LONGDOUBLE		7
# define COUT			100

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
	long double fdecimal;
	long long	fafter;
	long long	fbefore;
	char		*fstr;
	int			nan;
	int			inf;
}				t_struct;

int				ft_printf(const char *fmt, ...);
int				format_parse(va_list args, const char *fmt, t_struct *params, int pos);
int				conversions(va_list args, char spec, t_struct *params);
int				modifiers(va_list args, const char *fmt, t_struct *params);
void			length_field(const char *fmt, t_struct *params);
void			print_modifiers(va_list args, const char *fmt, t_struct *params);

void			flags(const char *fmt, t_struct	*params);
void			width(const char *fmt, t_struct	*params);
void			precision(const char *fmt, t_struct	*params, va_list args, int p);
void			bzerostruct(t_struct *params, int full);
int				retmsg(char *str);

void			type_int(va_list args, t_struct *params);
void			int_from_fmt(t_struct *params, intmax_t num);

void			type_char(va_list args, t_struct *params);
void			type_str(va_list args, t_struct *params);

void			type_ptr(va_list args, t_struct *params);

void			type_u(va_list args, t_struct *params);
void			u_from_fmt(t_struct *params, uintmax_t num);

t_struct		*type_float(va_list args, t_struct *params);
void			float_math(long double num, t_struct *params);
void			float_print(int negative, t_struct *params);

void			type_oct(va_list args, t_struct *params);
void			oct_from_fmt(t_struct *params, uintmax_t num);

void			type_hex(va_list args, t_struct *params, char spec);
void			hex_from_fmt(t_struct *params, uintmax_t num, char spec);

void			writezeros(int n);
void			writeblanks(int n);

void			bzerostruct(t_struct *params, int full);

int				num_len(intmax_t num, int base);
int				unsigned_num_len(uintmax_t num, int base);
char			*itoa_base(intmax_t num, int base);
char			*itoa_base_unsigned(uintmax_t num, int base);
char			*itoa_base_upp(uintmax_t num, int base);

long double		power(long long n, int i);
int				is_nan(long double nb);
int				is_inf(long double nb);

#endif
