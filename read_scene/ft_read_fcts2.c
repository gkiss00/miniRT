/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fcts2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:12:40 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:46:01 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int				ft_fplanes(char *scene, t_data *data)
{
	int		i;
	t_plane	*new;

	if ((new = ft_add_plane(data)) == NULL)
		return (-1);
	i = 0;
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
	{
		++i;
	}
	new->coord = ft_fvec3(&scene[i], &i);
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
	{
		++i;
	}
	new->or = ft_fvec3(&scene[i], &i);
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
	{
		++i;
	}
	new->color = ft_fcolor(&scene[i], &i);
	return (1);
}

int				ft_fsquares(char *scene, t_data *data)
{
	int			i;
	t_square	*new;

	if ((new = ft_add_square(data)) == NULL)
		return (-1);
	i = 0;
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
		++i;
	new->coord = ft_fvec3(&scene[i], &i);
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
		++i;
	new->or = ft_fvec3(&scene[i], &i);
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
		++i;
	new->hight = ft_fatoi_s(&scene[i], &i);
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
		++i;
	new->color = ft_fcolor(&scene[i], &i);
	return (1);
}

int				ft_fcyls(char *scene, t_data *data)
{
	int		i;
	t_cyl	*new;

	if ((new = ft_add_cyl(data)) == NULL)
		return (-1);
	i = 0;
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
		++i;
	new->coord = ft_fvec3(&scene[i], &i);
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
		++i;
	new->or = ft_fvec3(&scene[i], &i);
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
		++i;
	new->rayon = ft_fatoi_s(&scene[i], &i);
	new->rayon /= 2;
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
		++i;
	new->hight = ft_fatoi_s(&scene[i], &i);
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
		++i;
	new->color = ft_fcolor(&scene[i], &i);
	return (1);
}

int				ft_ftriangles(char *scene, t_data *data)
{
	int			i;
	t_triangle	*new;

	if ((new = ft_add_triangle(data)) == NULL)
		return (-1);
	i = 0;
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
		++i;
	new->coord1 = ft_fvec3(&scene[i], &i);
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
		++i;
	new->coord2 = ft_fvec3(&scene[i], &i);
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
		++i;
	new->coord3 = ft_fvec3(&scene[i], &i);
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
		++i;
	new->color = ft_fcolor(&scene[i], &i);
	return (1);
}
