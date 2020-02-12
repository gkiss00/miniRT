/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fcts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 09:59:16 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:45:43 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec3			ft_fvec3(char *scene, int *n)
{
	t_vec3	vec3;
	int		i;

	i = 0;
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
	{
		++i;
	}
	vec3.x = ft_fatoi_s(&scene[i], &i);
	++i;
	vec3.y = ft_fatoi_s(&scene[i], &i);
	++i;
	vec3.z = ft_fatoi_s(&scene[i], &i);
	*n += i;
	return (vec3);
}

int				ft_fcameras(char *scene, t_data *data)
{
	int			i;
	t_camera	*new;

	if ((new = ft_add_camera(data)) == NULL)
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
	new->vision = ft_atoi_s(&scene[i], &i);
	return (1);
}

int				ft_flights(char *scene, t_data *data)
{
	int			i;
	t_light		*new;

	if ((new = ft_add_light(data)) == NULL)
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
	new->ntensity = ft_fatoi_s(&scene[i], &i);
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
	{
		++i;
	}
	new->color = ft_fcolor(&scene[i], &i);
	return (1);
}

int				ft_fspheres(char *scene, t_data *data)
{
	int			i;
	t_sphere	*new;

	if ((new = ft_add_sphere(data)) == NULL)
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
	new->rayon = ft_atoi_s(&scene[i], &i);
	new->rayon /= 2;
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
	{
		++i;
	}
	new->color = ft_fcolor(&scene[i], &i);
	return (1);
}

t_color			ft_fcolor(char *scene, int *n)
{
	t_color	color;
	int		i;

	i = 0;
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
	{
		++i;
	}
	color.r = ft_atoi_s(&scene[i], &i);
	++i;
	color.g = ft_atoi_s(&scene[i], &i);
	++i;
	color.b = ft_atoi_s(&scene[i], &i);
	if (color.r > 255)
		color.r = 255;
	if (color.g > 255)
		color.g = 255;
	if (color.b > 255)
		color.b = 255;
	*n += i;
	return (color);
}
