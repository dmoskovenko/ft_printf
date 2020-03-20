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

# define VALIDSYM		"cCsSpPdDiIoOuUxXfFhlL0123456789 .-+#%"
# define TYPESYM		"cCsSpPdDiIoOuUxXfF"
# define FLAGS			" .-+#0hlL"
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
	int			precisionzero;
	int			length;
	long double fdecimal;
	char		*fstr;
	long long	fbefore;
	long long	fafter;
	int			lenbefore;
	int			lenafter;
}				t_struct;

int				ft_printf(const char *fmt, ...);
int				format_parse(va_list args, const char *fmt, \
				t_struct *params, int pos);
int				conversions(va_list args, char spec, t_struct *params);
int				modifiers(va_list args, const char *fmt, t_struct *params);
int				retmsg(char *str);
void			bzerostruct(t_struct *params, int full);

void			length_field(const char *fmt, t_struct *params);
void			flags(const char *fmt, t_struct	*params);
void			width(const char *fmt, t_struct	*params);
void			precision(const char *fmt, t_struct	*params);

void			type_int(va_list args, t_struct *params);
void			int_from_fmt(t_struct *params, intmax_t num, int i);
void			int_print(t_struct *params, char *s, int num_length, int indent);
int				int_print2(t_struct *params, char *s, int num_length);
char			*int_with_prec(t_struct *params, char *s, int num_length, int i);

void			type_char(va_list args, t_struct *params);
void			char_print(t_struct *params, char c, int indent);

void			type_str(va_list args, t_struct *params);
void			str_print(t_struct *params, char *s, int str_len, int indent);

void			type_ptr(va_list args, t_struct *params);

void			type_u(va_list args, t_struct *params);
void			u_from_fmt(t_struct *params, uintmax_t num, int i);
char			*u_with_prec(t_struct *params, char *s, int num_length, int i);
void			u_print(t_struct *params, char *s, int num_length, int indent);
int				u_print2(t_struct *params, char *s, int num_length);

void			type_oct(va_list args, t_struct *params);
void			oct_from_fmt(t_struct *params, uintmax_t num, int i);
char			*oct_with_prec(t_struct *params, char *s, int num_length, int i);
char			*oct_hash(char *s, int num_length);
void			oct_hash_chk(t_struct *params, int num, int num_length);
void			oct_print(t_struct *params, char *s, int num_length, int indent);
int				oct_print2(t_struct *params, char *s, int num_length);

void			type_hex(va_list args, t_struct *params, char spec);
void			hex_from_fmt(t_struct *params, uintmax_t num, char spec, int i);
char			*hex_hash(char *s, int num_length, char spec);
char			*hex_with_prec(t_struct *params, char *s, int num_length, int i);
void			hex_hash_chk(t_struct *params, int num, int num_length);
void			hex_print(t_struct *params, char *s, int num_length, int indent);
int				hex_print2(t_struct *params, char *s, int num_length);

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

#endif
