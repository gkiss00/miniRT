/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error8.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:33:09 by gkiss             #+#    #+#             */
/*   Updated: 2020/01/25 15:33:10 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

static int	check_high(char *line, int i)
{
	if ((i = check_float_pos(line, i)) == -1)
		return (-1);
	while (line[i] == ' ')
		++i;
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
	i += 2;
	while (line[i] == ' ')
		++i;
	if ((i = check_coord(line, i)) == -1)
		return (-1);
	while (line[i] == ' ')
		++i;
	if ((i = check_coord(line, i)) == -1)
		return (-1);
	while (line[i] == ' ')
		++i;
	if ((i = check_high(line, i)) == -1)
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

int			check_cy(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((i = ft_follow(line, i)) == -1)
			return (-1);
	}
	return (0);
}
