/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:37:48 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:50:02 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minirt.h"

static t_vec3	ft_follow2(t_data data, t_vec3 axe[3], t_vec3 i, t_vec2 coord)
{
	float	t[2];
	t_vec3	corner;

	t[0] = (data.res.x / 2 - coord.x);
	t[0] /= sqrt(pow(axe[1].x, 2) + pow(axe[1].y, 2) + pow(axe[1].z, 2));
	corner = ft_find_point(i, axe[1], -t[0]);
	t[1] = (data.res.y / 2 - coord.y);
	t[1] /= sqrt(pow(axe[2].x, 2) + pow(axe[2].y, 2) + pow(axe[2].z, 2));
	corner = ft_find_point(corner, axe[2], -t[1]);
	return (corner);
}

static t_vec3	ft_follow1(t_data data, t_vec3 i, t_vec2 coord)
{
	t_vec3	pose;
	t_vec3	axe[3];

	pose.x = 0;
	pose.y = 1;
	pose.z = 0;
	axe[0] = data.camera->or;
	axe[1] = ft_produit_vect(axe[0], pose);
	axe[2] = ft_produit_vect(axe[0], axe[1]);
	return (ft_follow2(data, axe, i, coord));
}

static t_vec3	ftpecial_case(t_data data, t_vec3 i, t_vec2 coord)
{
	t_vec3	pose;
	t_vec3	axe[4];

	pose.x = 0;
	pose.y = 0;
	pose.z = 1;
	axe[0] = data.camera->or;
	axe[1] = ft_produit_vect(axe[0], pose);
	axe[2] = ft_produit_vect(axe[0], axe[1]);
	return (ft_follow2(data, axe, i, coord));
}

t_vec3			ft_find_pix(t_data data, t_vec2 coord)
{
	float	dist;
	float	t;
	t_vec3	i;

	dist = (data.res.x / 2) / (fabs(tanf((data.camera->vision / 2) *
					(2 * M_PI / 360))));
	t = sqrt(dist * dist / (pow(data.camera->or.x, 2) +
				pow(data.camera->or.y, 2) + pow(data.camera->or.z, 2)));
	i = ft_find_point(data.camera->coord, data.camera->or, t);
	if (data.camera->or.x == 0 && data.camera->or.y != 0 &&
			data.camera->or.z == 0)
		return (ftpecial_case(data, i, coord));
	return (ft_follow1(data, i, coord));
}
