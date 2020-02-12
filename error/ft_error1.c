/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:32:07 by gkiss             #+#    #+#             */
/*   Updated: 2020/01/25 15:32:12 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

/*
** CHECK[0] = NB DE FOIS QUE LA LETTRE APPARAIT
** CHECK[1] = NB DE NOMBRES POUR LA RESOLUTION
** CHECK[2] = SERT A REGARDER SI ON PASSE A UN NOMBRE SUIVANT
** CHECK[3] = VAUT 1 SI UNE ERREUR EST SURVENUE
*/

static int	follow(char *line, int i)
{
	if (line[i] == 'R')
		++i;
	while (line[i] == ' ')
		++i;
	if ((i = check_int_pos(line, i)) == -1)
		return (-1);
	while (line[i] == ' ')
		++i;
	if ((i = check_int_pos(line, i)) == -1)
		return (-1);
	while (line[i] == ' ')
		++i;
	if (line[i] != '\0' && line[i] != '\n')
		return (-1);
	return (i);
}

int			check_r(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((i = follow(line, i)) == -1)
			return (-1);
	}
	return (0);
}
