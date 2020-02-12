/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:05:47 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:50:25 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	ft_write_header(int fd, t_data data)
{
	char	c;
	int		d;

	c = 'B';
	if (write(fd, &c, 1) != 1)
		return (-1);
	c = 'M';
	if (write(fd, &c, 1) != 1)
		return (-1);
	d = 26 + data.res.x * data.res.y * 3;
	if (write(fd, &d, 4) != 4)
		return (-1);
	d = 0;
	if (write(fd, &d, 4) != 4)
		return (-1);
	d = 26;
	if (write(fd, &d, 4) != 4)
		return (-1);
	return (0);
}

static int	ft_write_dib(int fd, t_data data)
{
	int				d;
	unsigned short	s;

	d = 12;
	if (write(fd, &d, 4) != 4)
		return (-1);
	s = data.res.x;
	if (write(fd, &s, 2) != 2)
		return (-1);
	s = data.res.y;
	if (write(fd, &s, 2) != 2)
		return (-1);
	s = 1;
	if (write(fd, &s, 2) != 2)
		return (-1);
	s = 24;
	if (write(fd, &s, 2) != 2)
		return (-1);
	return (0);
}

static int	ft_write_data(int fd, t_data data)
{
	int x;
	int y;
	int color;

	y = 0;
	while (y < data.res.y)
	{
		x = 0;
		while (x < data.res.x)
		{
			color = data.pix[x][data.res.y - y].color;
			if (write(fd, &color, 3) != 3)
				return (-1);
			++x;
		}
		++y;
	}
	return (0);
}

static char	*ft_find_name(char *name)
{
	char	*temp;
	int		i;
	int		j;

	i = ft_strlen(name);
	while ((j = -1) == -1 && i >= 0 && name[i] != '/')
		--i;
	if (i >= 0)
	{
		while (name[i + ++j + 1] != 0)
			name[j] = name[i + j + 1];
		name[j] = 0;
	}
	if ((name = ft_strjoin("saved_pictures/", name)) == NULL)
		return (NULL);
	if ((temp = ft_strjoin(name, "1")) == NULL)
	{
		free(name);
		return (NULL);
	}
	free(name);
	temp[ft_strlen(temp) - 3] = 'b';
	temp[ft_strlen(temp) - 2] = 'm';
	temp[ft_strlen(temp) - 1] = 'p';
	return (temp);
}

int			ft_save(t_data data, char *name)
{
	int	fd;

	if ((name = ft_find_name(name)) == NULL)
		return (-1);
	if ((fd = open(name, O_WRONLY | O_CREAT)) == -1)
	{
		ft_putstr_fd("Error\nIn open : the file must not already exist.\n", 0);
		free(name);
		return (-1);
	}
	if (ft_write_header(fd, data) == -1 || ft_write_dib(fd, data) == -1 ||
			ft_write_data(fd, data) == -1)
	{
		free(name);
		close(fd);
		return (-1);
	}
	close(fd);
	free(name);
	ft_putstr_fd("The file as been created.\nAdd permissions to see it.\n", 0);
	return (0);
}
