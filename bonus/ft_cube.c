/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:07:12 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:35:41 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

static void		ft_12tr(t_vec3 p[9], t_triangle tr[12])
{
	tr[0] = ft_create_tr(p[0], p[1], p[2]);
	tr[1] = ft_create_tr(p[0], p[2], p[3]);
	tr[2] = ft_create_tr(p[0], p[1], p[5]);
	tr[3] = ft_create_tr(p[0], p[4], p[5]);
	tr[4] = ft_create_tr(p[0], p[2], p[6]);
	tr[5] = ft_create_tr(p[0], p[4], p[6]);
	tr[6] = ft_create_tr(p[4], p[5], p[7]);
	tr[7] = ft_create_tr(p[4], p[6], p[7]);
	tr[8] = ft_create_tr(p[5], p[1], p[3]);
	tr[9] = ft_create_tr(p[5], p[7], p[3]);
	tr[10] = ft_create_tr(p[2], p[6], p[7]);
	tr[11] = ft_create_tr(p[2], p[3], p[7]);
}

static void		ft_8points(t_data data, t_vec3 coord, t_vec3 p[9])
{
	t_vec3	axe[4];
	float	t[3];

	axe[0] = data.cube->or;
	axe[4] = ft_create_v3(0, 1, 0);
	if (data.cube->or.x == 0 && data.cube->or.y != 0 && data.cube->or.z == 0)
		axe[4] = ft_create_v3(1, 0, 0);
	axe[1] = ft_produit_vect(axe[0], axe[4]);
	axe[2] = ft_produit_vect(axe[0], axe[1]);
	p[0] = data.cube->coord;
	t[0] = data.cube->hight / (sqrt(ft_prod_scal(axe[1], axe[1])));
	p[1] = ft_find_point(p[0], axe[1], t[0]);
	t[1] = data.cube->hight / (sqrt(ft_prod_scal(axe[2], axe[2])));
	p[2] = ft_find_point(p[0], axe[2], t[1]);
	p[3] = ft_find_point(p[2], axe[1], t[0]);
	t[2] = data.cube->hight / (sqrt(ft_prod_scal(axe[0], axe[0])));
	p[4] = ft_find_point(p[0], axe[0], t[2]);
	p[5] = ft_find_point(p[4], axe[1], t[0]);
	p[6] = ft_find_point(p[4], axe[2], t[1]);
	p[7] = ft_find_point(p[6], axe[1], t[0]);
}

static float	ft_short_dist(float dist[15])
{
	int k;
	int min;
	int nb;

	k = 0;
	min = -1;
	nb = -1;
	while (k < 12)
	{
		if (min == -1 && dist[k] != -1)
		{
			min = dist[k];
			nb = k;
		}
		if (dist[k] != -1 && dist[k] < min)
		{
			min = dist[k];
			nb = k;
		}
	}
	return (nb);
}

static t_vec4	ft_follow(t_data data, t_vec3 coord)
{
	t_vec3		p[10];
	t_triangle	tr[12];
	float		dist[15];
	int			k;
	t_vec4		pl;

	k = -1;
	ft_8points(data, coord, p);
	ft_12tr(p, tr);
	p[9] = ft_find_v(data.light->coord, coord);
	while (++k < 12)
	{
		pl = ft_find_p(tr[k].coord1, tr[k].coord2, tr[k].coord3);
		dist[12] = ft_prod_scal(ft_v4_to_v3(pl), p[9]);
		dist[13] = ft_prod_scal(ft_v4_to_v3(pl), data.light->coord) + pl.d;
		dist[14] = -dist[13] / dist[12];
		p[8] = ft_find_point(data.light->coord, p[9], dist[14]);
		dist[k] = ft_is_sq(data, tr[k], p[8]);
	}
	dist[14] = ft_short_dist(dist);
	return (ft_create_v4(p[8], dist[14]));
}

void			ft_cube(t_data *data, t_vec3 pix, float dm[1], t_vec2 coord)
{
	t_vec4	i;
	int		color;

	i = ft_follow(*data, pix);
	color = ft_rgb_to_int(data->cube->color);
	if ((i.d != -1 && i.d < dm[0]) || (i.d != 0 && dm[0] == -1))
	{
		data->pix[coord.x][coord.y].color = color;
		data->pix[coord.x][coord.y].inter = ft_v4_to_v3(i);
		data->pix[coord.x][coord.y].shape_number = data->shape_number;
		dm[0] = i.d;
	}
}

/*
** color = ft_color_int(color, ft_norm_cu(*data, ft_v4_to_v3(i)));
*/
