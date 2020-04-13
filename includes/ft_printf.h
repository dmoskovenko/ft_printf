/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:15:37 by releanor          #+#    #+#             */
/*   Updated: 2020/03/13 03:22:24 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include "../libft/includes/libft.h"

# define VALIDSYM		"cCsSpPdDiIoOuUxXfFrhlLjz0123456789 .-+#%rb"
# define TYPESYM		"cCsSpPdDiIoOuUxXfF%rb"
# define FLAGS			" .-+#0hlLjz6"
# define SHORT			1
# define SHORTSHORT		2
# define LONG			3
# define LONGLONG		4
# define LONGDOUBLE		7
# define SIZET			8
# define INTUINTMAX		9

typedef struct	s_struct
{
	char		*fmt;
	int			nprinted;
	int			nprinted_here;
	int			i;
	int			negative;
	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			zero_arg;
	int			hash;
	int			hash_case;
	int			hash_case_zero;
	int			small_hex;
	int			dot;
	int			width;
	int			precision;
	int			precision_was;
	int			precisionzero;
	int			indent;
	int			indent_was;
	int			length;
	int			after_percent;
	long double fdecimal;
	char		*fstr;
	long long	fbefore;
	long long	fafter;
	int			lenbefore;
	int			lenafter;
}				t_struct;

int				ft_printf(const char *fmt, ...);
int				format_parse(va_list args, const char *fmt, \
				t_struct *prms);
int				parse_normal(va_list args, t_struct *prms, const char *fmt);
int				parse_text_after_percent(t_struct *prms, const char *fmt);
int				conversions(va_list args, char spec, t_struct *params);
int				conversions2(va_list args, char spec, t_struct *params);
int				modifiers(va_list args, const char *fmt, t_struct *params);
int				retmsg(char *str);
void			bzerostruct(t_struct *params, int full);

void			length_field(const char *fmt, t_struct *params);
void			flags(const char *fmt, t_struct	*params);
void			width(const char *fmt, t_struct	*params);
void			precision(const char *fmt, t_struct	*params);

void			type_int(va_list args, t_struct *params);
void			int_from_fmt(t_struct *params, intmax_t num, int i);
void			int_print(t_struct *params, char *s, int indent);
int				int_print2(t_struct *params, char *s);
char			*int_with_prec(t_struct *params, char *s, int i);
void			int_chk(t_struct *params);
char			*int_overflow_chk(intmax_t num, char *s);

void			type_char(va_list args, t_struct *prms);
void			char_print(t_struct *params, char c, int indent);

void			type_str(va_list args, t_struct *params);
void			str_print(t_struct *params, char *s);
void			str_print2(t_struct *params);

void			type_ptr(va_list args, t_struct *params);
void			ptr_print(t_struct *prms, char *s);
void			ptr_print2(t_struct *prms, char*s);
void			ptr_print3(t_struct *prms, char*s);
void			ptr_print4(t_struct *prms, char*s);
void			ptr_chk(t_struct *prms);

void			type_u(va_list args, t_struct *prms, char spec);
void			u_from_fmt(t_struct *prms, uintmax_t num, int i);
char			*u_with_prec(t_struct *prms, char *s, int i);
void			u_print(t_struct *prms, char *s, int indent);
int				u_print2(t_struct *prms, char *s);

void			type_oct(va_list args, t_struct *prms);
void			oct_from_fmt(t_struct *prms, uintmax_t num, int i);
char			*oct_with_prec(t_struct *prms, char *s, int i);
char			*oct_hash(t_struct *prms, char *s);
void			oct_hash_chk(t_struct *prms, int num);
void			oct_print(t_struct *prms, char *s, int indent);
int				oct_print2(t_struct *prms, char *s);

void			type_hex(va_list args, t_struct *prms, char spec);
void			hex_from_fmt(t_struct *params, uintmax_t num, int i);
void			hex_from_fmt2(t_struct *params, char *s, int indent);
char			*hex_hash(t_struct *params, char *s);
char			*hex_with_prec(t_struct *params, char *s, int i);
void			hex_hash_chk(t_struct *params, int num);
void			hex_print(t_struct *prms, char *s, int indent);
int				hex_print2(t_struct *params, char *s);

void			type_float(va_list args, t_struct *params);
int				is_infnan(t_struct *params, long double num);
void			float_math(long double num, t_struct *params);
void			float_print(t_struct *params);
void			float_print2(t_struct *params);

void			writezeros(int n);
void			writeblanks(int n);

int				num_len(intmax_t num, int base);
int				unsigned_num_len(uintmax_t num, int base);
char			*itoa_base(t_struct *params, intmax_t num, int base);
char			*itoa_base_unsigned(uintmax_t num, int base);
char			*itoa_base_upp(uintmax_t num, int base);

long double		power(long long n, int i);
void			percent(t_struct *params);

void			create_nonprint_str(va_list args, t_struct *params);
int				recalc_len(char *s, int i);
void			recreate_str(char *s, char *s_nonpr, int i, int j);

void			type_b(va_list args, t_struct *prms);
void			b_from_fmt(t_struct *prms, uintmax_t num, int i);

#endif
