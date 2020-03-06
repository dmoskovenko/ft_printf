/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 21:51:34 by coclayto          #+#    #+#             */
/*   Updated: 2019/12/26 21:58:41 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		join_string(char **arr, char *buf, int fd)
{
	char	*tmp;

	tmp = ft_strjoin(arr[fd], buf);
	free(arr[fd]);
	arr[fd] = tmp;
}

static size_t	len_to_symb(const char *str, int symb)
{
	size_t			len;
	unsigned char	c;

	len = 0;
	c = (unsigned char)symb;
	while (!(str[len] == c) && str[len] != '\0')
		len++;
	return (len);
}

static int		new_line(char **arr, char **line, int fd)
{
	char	*tmp;
	size_t	len;

	if (ft_strchr(arr[fd], '\n'))
	{
		len = len_to_symb(arr[fd], '\n');
		*line = ft_strsub(arr[fd], 0, len);
		tmp = ft_strdup(arr[fd] + len + 1);
		free(arr[fd]);
		arr[fd] = tmp;
		if (arr[fd][0] == '\0')
			ft_strdel(&arr[fd]);
	}
	else
	{
		*line = ft_strdup(arr[fd]);
		ft_strdel(&arr[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*arr[FD_MAX];
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (BUFF_SIZE < 1 || fd < 0 || line == NULL || fd > FD_MAX)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!arr[fd])
			arr[fd] = ft_strnew(0);
		join_string(arr, buf, fd);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && !arr[fd])
		return (0);
	return (new_line(arr, line, fd));
}
