/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:43:01 by cochapel          #+#    #+#             */
/*   Updated: 2019/11/20 18:21:59 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	is_line_break(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

static int	line_in_tab(char **line, char tab[2], int i)
{
	line[0] = ft_strnjoin(line[0], tab, i);
	if (line[0] == 0)
		return (-1);
	ft_memcpy(tab, &tab[i + 1], 1 - i - 1);
	ft_bzero(&tab[1 - i - 1], i + 1);
	return (1);
}

static int	boucle(int *i, char buffer[2], char **line,
		char tab[2])
{
	int flag;

	flag = 1;
	if ((*i = is_line_break(buffer)) != -1)
	{
		line[0] = ft_strnjoin(line[0], buffer, *i);
		if (line[0] == 0)
			return (-1);
		ft_bzero(tab, 2);
		ft_memcpy(tab, &buffer[*i + 1], ft_strlen(&buffer[*i + 1]));
		flag = 0;
	}
	else
	{
		line[0] = ft_strnjoin(line[0], buffer, 1);
	}
	ft_bzero(buffer, 2);
	return (flag);
}

int			get_next_line(int fd, char **line)
{
	char		buffer[2];
	int			i;
	int			flag;
	static char	tab[OPEN_MAX][2] = {{0}, {0}};

	if (line == 0 || read(fd, buffer, 0) < 0 ||
			fd > OPEN_MAX)
		return (-1);
	line[0] = ft_strndup("", 1);
	ft_bzero(buffer, 2);
	flag = 1;
	if ((i = is_line_break(tab[fd])) != -1)
		return (line_in_tab(line, tab[fd], i));
	if ((line[0] = ft_strnjoin(line[0], tab[fd], ft_strlen(tab[fd]))) == 0)
		return (-1);
	while (flag == 1 && read(fd, buffer, 1) > 0)
	{
		flag = boucle(&i, buffer, line, tab[fd]);
		if (flag == -1)
			return (-1);
	}
	if (flag == 0)
		return (1);
	ft_bzero(tab[fd], 2);
	return (0);
}
