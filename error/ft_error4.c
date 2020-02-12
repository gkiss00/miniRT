/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:32:38 by gkiss             #+#    #+#             */
/*   Updated: 2020/01/25 15:32:39 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

static int	check_lum(char *line, int i)
{
	if ((i = check_float_pos(line, i)) == -1)
		return (-1);
	return (i);
}

static int	check_color(char *line, int i)
{
	int x;

	x = 0;
	while (x < 3)
	{
		if ((i = check_int_pos(line, i)) == -1)
			return (-1);
		++x;
	}
	return (i);
}

static int	check_coord(char *line, int i)
{
	int x;

	x = 0;
	while (x < 3)
	{
		if ((i = check_float(line, i)) == -1)
			return (-1);
		++x;
	}
	return (i);
}

static int	ft_follow(char *line, int i)
{
	if (line[i] == 'l')
		++i;
	while (line[i] == ' ')
		++i;
	if ((i = check_coord(line, i)) == -1)
		return (-1);
	while (line[i] == ' ')
		++i;
	if ((i = check_lum(line, i)) == -1)
		return (-1);
	while (line[i] == ' ')
		++i;
	if ((i = check_color(line, i)) == -1)
		return (-1);
	while (line[i] == ' ')
		++i;
	if (line[i] != '\0' && line[i] != '\n')
		return (-1);
	return (i);
}

int			check_l(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		i = ft_follow(line, i);
		if (i == -1)
			return (-1);
	}
	return (0);
}
