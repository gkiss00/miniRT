/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:32:19 by gkiss             #+#    #+#             */
/*   Updated: 2020/01/25 15:32:20 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

static int	check_coord(char *line, int i)
{
	int	x;

	x = 0;
	while (x < 3)
	{
		if ((i = check_int_pos(line, i)) == -1)
			return (-1);
		++x;
	}
	return (i);
}

static int	ft_follow(char *line, int i)
{
	if (line[i] == 'A')
		++i;
	while (line[i] == ' ')
		++i;
	if ((i = check_float_pos(line, i)) == -1)
		return (-1);
	while (line[i] == ' ')
		++i;
	if ((i = check_coord(line, i)) == -1)
		return (-1);
	while (line[i] == ' ')
		++i;
	if (line[i] != '\n' && line[i] != '\0')
		return (-1);
	return (i);
}

int			check_a(char *line)
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
