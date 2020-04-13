/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_nonprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:34:13 by releanor          #+#    #+#             */
/*   Updated: 2020/03/06 12:33:06 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		recalc_len(char *s, int i)
{
	int new_len;

	new_len = 0;
	while (s[i])
	{
		if ((s[i] >= 1 && s[i] <= 32) || s[i] == 127)
			new_len += 2;
		else
			new_len++;
		i++;
	}
	return (new_len);
}

void	recreate_str(char *s, char *s_nonpr, int i, int j)
{
	while (s[i])
	{
		if ((s[i] >= 1 && s[i] <= 32) || s[i] == 127)
		{
			s_nonpr[j++] = '^';
			if (s[i] == 0)
				s_nonpr[j] = '@';
			else if (s[i] == 127)
				s_nonpr[j] = '?';
			else
				s_nonpr[j] = 64 + s[i];
		}
		else
			s_nonpr[j] = s[i];
		i++;
		j++;
	}
	s_nonpr[j] = '\0';
}

void	create_nonprint_str(va_list args, t_struct *params)
{
	char	*s;
	char	*s_nonpr;
	int		new_len;

	if (!(s = (char *)va_arg(args, char *)))
		s = "(null)";
	params->lenbefore = ft_strlen(s);
	new_len = recalc_len(s, 0);
	if (!(s_nonpr = (char *)malloc(sizeof(*s_nonpr) * \
	((new_len) + 1))))
		s_nonpr = "(null)";
	recreate_str(s, s_nonpr, 0, 0);
	params->lenbefore = new_len;
	str_print(params, s_nonpr);
	free(s_nonpr);
	bzerostruct(params, 0);
}
