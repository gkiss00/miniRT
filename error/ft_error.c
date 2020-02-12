/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <cochapel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:37:47 by gkiss             #+#    #+#             */
/*   Updated: 2020/02/01 11:06:33 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

static int	ft_check3(char *line, char *caract)
{
	if (ft_memcmp((void*)caract, (void*)"cy", 2) == 0)
	{
		free(caract);
		return (check_cy(line));
	}
	else if (ft_memcmp((void*)caract, (void*)"tr", 2) == 0)
	{
		free(caract);
		return (check_tr(line));
	}
	else
	{
		free(caract);
		return (-1);
	}
}

static int	ft_check2(char *line)
{
	char	*caract;

	if ((caract = ft_substr(line, 0, 2)) == NULL)
		return (-1);
	if (ft_memcmp((void*)caract, (void*)"sp", 2) == 0)
	{
		free(caract);
		return (check_sp(line));
	}
	else if (ft_memcmp((void*)caract, (void*)"pl", 2) == 0)
	{
		free(caract);
		return (check_pl(line));
	}
	else if (ft_memcmp((void*)caract, (void*)"sq", 2) == 0)
	{
		free(caract);
		return (check_sq(line));
	}
	else
		return (ft_check3(line, caract));
}

static int	ft_check1(char *line, int maj[])
{
	if (line[0] == 'R')
	{
		++maj[0];
		return (check_r(line));
	}
	else if (line[0] == 'A')
	{
		++maj[1];
		return (check_a(line));
	}
	else if (line[0] == 'c' && ft_strlen(line) > 1 && line[1] != 'y')
		return (check_c(line));
	else if (line[0] == 'l')
		return (check_l(line));
	else
		return (ft_check2(line));
}

static int	ft_return(int maj[], int flag)
{
	if (maj[0] != 1 || maj[1] != 1 || flag == -1)
	{
		ft_putstr_fd("Error\nIn the composition of the .rt file\n", 0);
		return (-1);
	}
	return (0);
}

int			ft_error(int fd)
{
	int		ret;
	int		flag;
	int		stop;
	int		maj[2];
	char	*line;

	ret = 0;
	flag = 0;
	stop = 0;
	maj[0] = 0;
	maj[1] = 0;
	line = "";
	while ((ret = get_next_line(fd, &line)) >= 0 && flag == 0 && stop == 0)
	{
		if (line[0] != '\0')
			flag = ft_check1(line, maj);
		free(line);
		if (ret == 0)
			stop = 1;
	}
	free(line);
	return (ft_return(maj, flag));
}
