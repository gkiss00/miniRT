/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:43:55 by gkiss             #+#    #+#             */
/*   Updated: 2020/02/01 10:41:52 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static float	ft_norm_cyl_light(t_data *data, t_vec2 coord, t_vec3 *normale)
{
	float	cos;
	float	t;
	float	tmp;
	t_vec3	a;
	t_vec3	v[2];

	tmp = ft_dist_pp(data->cyl->coord, data->pix[coord.x][coord.y].inter);
	t = pow(tmp, 2) - pow(data->cyl->rayon, 2);
	t /= ft_prod_scal(data->cyl->or, data->cyl->or);
	t = sqrt(t);
	a = ft_find_point(data->cyl->coord, data->cyl->or, t);
	*normale = ft_vec3_sous(a, data->pix[coord.x][coord.y].inter);
	v[1] = ft_vec3_sous(data->camera->coord, data->pix[coord.x][coord.y].inter);
	cos = ft_prod_scal(*normale, v[1]) / (ft_vec3len(*normale) *
			ft_vec3len(v[1]));
	return (fabs(cos));
}

static float	ft_norm_dist(float norm, t_data *data, t_vec2 coord)
{
	float	dist;

	dist = ft_dist_pp(data->pix[coord.x][coord.y].inter, data->light->coord);
	dist = (LIMIT_LIGHT - dist) / LIMIT_LIGHT;
	if (dist < 0)
		dist = 0;
	norm *= dist;
	return (norm);
}

static float	ft_follow2(t_data *data, t_vec2 coord, float norm, int nb)
{
	t_vec3	normale;
	int		flag;

	flag = 0;
	while (data->triangle != NULL)
	{
		if (nb == 0 && (flag = 1) == 1)
			norm = ft_norm_tri(data, coord, &normale);
		--nb;
		data->triangle = data->triangle->next;
	}
	if (flag == 1 && ft_same_side(data, coord, normale) == 0)
		return (-1);
	return (ft_norm_dist(norm, data, coord));
}

static float	ft_follow(t_data *data, t_vec2 coord, float norm, int nb)
{
	t_vec3	normale;
	int		flag;

	flag = 0;
	while (data->square != NULL)
	{
		if (nb == 0 && (flag = 1) == 1)
			norm = ft_norm_sqrt(data, coord, &normale);
		--nb;
		data->square = data->square->next;
	}
	while (data->cyl != NULL)
	{
		if (nb == 0 && (flag = 1) == 1)
			norm = ft_norm_cyl_light(data, coord, &normale);
		--nb;
		data->cyl = data->cyl->next;
	}
	if (flag == 1 && ft_same_side(data, coord, normale) == 0)
		return (-1);
	return (ft_follow2(data, coord, norm, nb));
}

float			ft_norm_light(t_data *data, t_vec2 coord)
{
	float	norm;
	int		shape_number;
	t_vec3	normale;
	int		flag;

	shape_number = data->pix[coord.x][coord.y].shape_number;
	ft_init_lst_shapes(data);
	flag = 0;
	while (data->sphere != NULL)
	{
		if (shape_number == 0 && (flag = 1) == 1)
			norm = ft_norm_sphere(data, coord, &normale);
		--shape_number;
		data->sphere = data->sphere->next;
	}
	while (data->plane != NULL)
	{
		if (shape_number == 0 && (flag = 1) == 1)
			norm = ft_norm_plane(data, coord, &normale);
		--shape_number;
		data->plane = data->plane->next;
	}
	if (flag == 1 && ft_same_side(data, coord, normale) == 0)
		return (-1);
	return (ft_follow(data, coord, norm, shape_number));
}
