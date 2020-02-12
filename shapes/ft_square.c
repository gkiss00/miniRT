/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 08:58:04 by gkiss             #+#    #+#             */
/*   Updated: 2020/02/01 10:48:51 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

void			ft_4point(t_data data, t_vec3 p[4])
{
	t_vec3	axe[4];
	t_vec3	pose;
	float	t;

	pose = ft_create_v3(0, 1, 0);
	if (data.square->or.x == 0 && data.square->or.y != 0 &&
			data.square->or.z == 0)
		pose = ft_create_v3(1, 0, 0);
	axe[0] = data.square->or;
	axe[1] = ft_produit_vect(axe[0], pose);
	axe[2] = ft_produit_vect(axe[0], axe[1]);
	axe[3] = ft_addition_vect(axe[1], axe[2]);
	p[0] = data.square->coord;
	t = data.square->hight / (sqrt(ft_prod_scal(axe[1], axe[1])));
	p[1] = ft_find_point(p[0], axe[1], -t);
	t = data.square->hight / (sqrt(ft_prod_scal(axe[2], axe[2])));
	p[2] = ft_find_point(p[0], axe[2], t);
	t = data.square->hight / (sqrt(ft_prod_scal(axe[1], axe[1])));
	p[3] = ft_find_point(p[2], axe[1], -t);
}

static float	ft_dist(float dist[2])
{
	if (dist[0] == -1 && dist[1] == -1)
		return (-1);
	if (dist[0] == -1 && dist[1] != -1)
		return (dist[1]);
	if (dist[1] == -1 && dist[0] != -1)
		return (dist[0]);
	if (dist[1] < dist[0])
		return (dist[1]);
	return (dist[0]);
}

static t_vec4	ft_find_i(t_data data, t_vec3 vect, t_vec4 plan)
{
	float		abt[3];
	float		dist[2];
	t_vec3		p[4];
	t_vec3		i;
	t_triangle	tr[2];

	abt[0] = ft_prod_scal(data.square->or, vect);
	abt[1] = ft_prod_scal(data.square->or, data.camera->coord) + plan.d;
	abt[2] = -abt[1] / abt[0];
	i = ft_find_point(data.camera->coord, vect, abt[2]);
	ft_4point(data, p);
	tr[0].coord1 = p[0];
	tr[0].coord2 = p[1];
	tr[0].coord3 = p[2];
	tr[1].coord1 = p[1];
	tr[1].coord2 = p[2];
	tr[1].coord3 = p[3];
	dist[0] = ft_is_sq(data, tr[0], i);
	dist[1] = ft_is_sq(data, tr[1], i);
	return (ft_create_v4(i, ft_dist(dist)));
}

static t_vec4	ft_follow(t_data data, t_vec3 coord)
{
	t_vec3	vecteur;
	t_vec4	plan;
	t_vec4	i;

	i.d = -1;
	vecteur = ft_find_v(data.camera->coord, coord);
	plan.d = -ft_prod_scal(data.square->coord, data.square->or);
	plan = ft_create_v4(data.square->or, plan.d);
	if (ft_prod_scal(vecteur, data.square->or) != 0)
	{
		i = ft_find_i(data, vecteur, plan);
	}
	return (i);
}

void			ft_square(t_data data, t_vec3 pix, float dist_min[1],
		t_vec2 coord)
{
	t_vec4	i;
	int		color_sq;

	i = ft_follow(data, pix);
	color_sq = ft_rgb_to_int(data.square->color);
	if (ft_affiche_sq(data, ft_v4_to_v3(i)) >= 0)
	{
		if (i.d != -1 && (i.d < dist_min[0] || dist_min[0] == -1))
		{
			color_sq = ft_color_int(color_sq, ft_norm_sq(data, ft_v4_to_v3(i)));
			data.pix[coord.x][coord.y].color = color_sq;
			data.pix[coord.x][coord.y].inter = ft_v4_to_v3(i);
			data.pix[coord.x][coord.y].shape_number = data.shape_number;
			dist_min[0] = i.d;
		}
	}
}
