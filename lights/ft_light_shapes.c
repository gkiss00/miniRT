/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light_shapes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:59:24 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:42:49 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int		ft_is_sphere_closer(t_data *data, t_vec2 coord)
{
	float	abcd[4];
	t_vec3	dir;
	t_vec3	temp;
	float	t[2];

	dir = ft_vec3_sous(data->light->coord, data->pix[coord.x][coord.y].inter);
	temp = ft_vec3_sous(data->light->coord, data->sphere->coord);
	abcd[0] = ft_prod_scal(dir, dir);
	abcd[1] = 2 * ft_prod_scal(dir, temp);
	abcd[2] = ft_prod_scal(temp, temp) - pow(data->sphere->rayon, 2);
	abcd[3] = pow(abcd[1], 2) - (4 * abcd[0] * abcd[2]);
	if (abcd[3] >= 0)
	{
		t[0] = (-abcd[1] + sqrt(abcd[3])) / (2 * abcd[0]);
		t[1] = (-abcd[1] - sqrt(abcd[3])) / (2 * abcd[0]);
		if (t[0] > -1 + EPSILON && t[0] < 0)
			return (1);
		else if (t[1] > -1 + EPSILON && t[1] < 0)
			return (1);
	}
	return (0);
}

int		ft_is_plane_closer(t_data *data, t_vec2 coord)
{
	float	d;
	float	t;
	t_vec3	dir;

	dir = ft_vec3_sous(data->pix[coord.x][coord.y].inter, data->light->coord);
	d = ft_prod_scal(data->plane->or, data->plane->coord);
	if ((ft_prod_scal(data->plane->or, data->light->coord) - d) == 0)
	{
		t = ft_prod_scal(data->plane->or, data->light->coord) * -1;
		t /= ft_prod_scal(data->plane->or, dir);
		if (t > -1 + EPSILON && t < 0)
			return (1);
	}
	return (0);
}

int		ft_is_cyl_closer(t_data *data, t_vec2 coord)
{
	float	e[6];
	t_vec3	dir;
	t_vec3	temp;
	float	t[2];

	dir = ft_vec3_sous(data->light->coord, data->pix[coord.x][coord.y].inter);
	temp = ft_vec3_sous(data->light->coord, data->cyl->coord);
	e[0] = ft_prod_scal(dir, dir) - pow(ft_prod_scal(dir, data->cyl->or), 2);
	e[4] = ft_prod_scal(dir, data->cyl->or) * ft_prod_scal(temp, data->cyl->or);
	e[1] = 2 * (ft_prod_scal(dir, temp) - e[4]);
	e[5] = pow(ft_prod_scal(temp, data->cyl->or), 2) + pow(data->cyl->rayon, 2);
	e[2] = ft_prod_scal(temp, temp) - e[5];
	e[3] = pow(e[1], 2) - (4 * e[0] * e[2]);
	if (e[3] >= 0)
	{
		t[0] = (-e[1] + sqrt(e[3])) / (2 * e[0]);
		t[1] = (-e[1] - sqrt(e[3])) / (2 * e[0]);
		if (t[0] > -1 + EPSILON && t[0] < 0)
			return (1);
		else if (t[1] > -1 + EPSILON && t[1] < 0)
			return (1);
	}
	return (0);
}

int		ft_is_triangle_closer(t_data *data, t_vec2 coord)
{
	float	abcd[6];
	t_vec3	dir;
	t_vec3	i;
	t_vec3	tmp[3];
	t_vec4	plan;

	dir = ft_find_v(data->light->coord, data->pix[coord.x][coord.y].inter);
	abcd[4] = ft_vec3len(dir);
	tmp[0] = ft_find_v(data->triangle->coord1, data->triangle->coord2);
	tmp[1] = ft_find_v(data->triangle->coord1, data->triangle->coord3);
	tmp[2] = ft_produit_vect(tmp[0], tmp[1]);
	plan.d = -ft_prod_scal(tmp[2], data->triangle->coord1);
	if (ft_prod_scal(dir, tmp[2]) != 0)
	{
		abcd[0] = ft_prod_scal(tmp[2], dir);
		abcd[1] = ft_prod_scal(tmp[2], data->light->coord) + plan.d;
		abcd[2] = -abcd[1] / abcd[0];
		i = ft_find_point(data->light->coord, dir, abcd[2]);
		abcd[5] = ft_is_sq2(*data, *data->triangle, i);
		abcd[5] = abcd[5] / ft_vec3len(dir);
		if (abcd[5] < (1 - EPSILON) && abcd[5] > 0)
			return (1);
	}
	return (0);
}

int		ft_is_square_closer(t_data *data, t_vec2 coord)
{
	t_vec3		dir;
	t_vec3		i;
	t_vec3		p[4];
	t_triangle	tr[2];
	float		a[9];

	dir = ft_find_v(data->light->coord, data->pix[coord.x][coord.y].inter);
	a[5] = -ft_prod_scal(data->square->or, data->square->coord);
	if (ft_prod_scal(data->square->or, dir) != 0)
	{
		a[0] = ft_prod_scal(data->square->or, dir);
		a[1] = ft_prod_scal(data->square->or, data->light->coord) + a[5];
		a[2] = -a[1] / a[0];
		i = ft_find_point(data->light->coord, dir, a[2]);
		ft_4point(*data, p);
		tr[0] = ft_create_tr(p[0], p[1], p[2]);
		tr[1] = ft_create_tr(p[1], p[2], p[3]);
		a[3] = ft_is_sq2(*data, tr[0], i);
		a[4] = ft_is_sq2(*data, tr[1], i);
		a[7] = a[3] / ft_vec3len(dir);
		a[8] = a[4] / ft_vec3len(dir);
		if ((a[8] < 1 - EPSILON && a[8] > 0) || (a[7] < 1 - 0.01 && a[7] > 0))
			return (1);
	}
	return (0);
}
