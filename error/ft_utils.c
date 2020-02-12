/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:34:08 by gkiss             #+#    #+#             */
/*   Updated: 2020/01/25 15:34:09 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

int			check_float_pos(char *str, int i)
{
	int save;

	save = i;
	while (ft_isdigit(str[i]) == 1)
		++i;
	if (save == i)
		return (-1);
	if (str[i] == '.')
		++i;
	while (ft_isdigit(str[i]) == 1)
		++i;
	if (str[i] != ' ' && str[i] != ',' && str[i] != '\0')
		return (-1);
	if (str[i] == ',')
		++i;
	return (i);
}

int			check_float_neg(char *str, int i)
{
	int save;

	save = i;
	if (str[i] == '-')
		++i;
	if (!(save < i))
		return (-1);
	save = i;
	while (ft_isdigit(str[i]) == 1)
		++i;
	if (!(save < i))
		return (-1);
	if (str[i] == '.')
		++i;
	while (ft_isdigit(str[i]) == 1)
		++i;
	if (str[i] != ' ' && str[i] != ',' && str[i] != '\0')
		return (-1);
	if (str[i] == ',')
		++i;
	return (i);
}

int			check_float(char *str, int i)
{
	int save;

	save = i;
	if (str[i] == '-')
		++i;
	while (ft_isdigit(str[i]) == 1)
		++i;
	if (!(save < i))
		return (-1);
	if (str[i] == '.')
		++i;
	while (ft_isdigit(str[i]) == 1)
		++i;
	if (str[i] != ' ' && str[i] != ',' && str[i] != '\0')
		return (-1);
	if (str[i] == ',')
		++i;
	return (i);
}

int			check_int_pos(char *str, int i)
{
	int save;

	save = i;
	while (ft_isdigit(str[i]) == 1)
		++i;
	if (save == i)
		return (-1);
	if (str[i] != ' ' && str[i] != ',' && str[i] != '\0')
		return (-1);
	if (str[i] == ',')
		++i;
	return (i);
}

int			check_int(char *str, int i)
{
	int save;

	save = i;
	if (str[i] == '-')
		++i;
	save = i;
	while (ft_isdigit(str[i]) == 1)
		++i;
	if (save == i)
		return (-1);
	ft_putstr_fd("check int\n", 0);
	if (str[i] != ' ' && str[i] != ',' && str[i] != '\0')
		return (-1);
	ft_putstr_fd("check int\n", 0);
	if (str[i] == ',')
		++i;
	return (i);
}
