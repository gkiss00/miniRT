/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:11:47 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:47:56 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

static float	ft_affiche_p(t_data data, t_vec3 i)
{
	float	cos;
	float	scal;
	float	length[2];
	t_vec3	vec[2];

	vec[0] = data.camera->or;
	vec[1] = ft_find_v(data.camera->coord, i);
	scal = ft_prod_scal(vec[0], vec[1]);
	length[0] = ft_vec3len(vec[0]);
	length[1] = ft_vec3len(vec[1]);
	cos = scal / (length[0] * length[1]);
	return (cos);
}

static float	ft_norm_p(t_data data, t_vec3 i)
{
	t_vec3	vec[2];
	float	length[2];
	float	scal;
	float	cos;

	vec[0] = ft_find_v(data.camera->coord, i);
	vec[1] = data.plane->or;
	scal = ft_prod_scal(vec[0], vec[1]);
	length[0] = ft_vec3len(vec[0]);
	length[1] = ft_vec3len(vec[1]);
	cos = scal / (length[0] * length[1]);
	return (fabs(cos));
}

static t_vec3	ft_d_inter(t_data *data, t_vec3 pix, float d)
{
	t_vec3	inter;
	t_vec3	dir;
	float	tab[3];

	dir = ft_vec3_sous(pix, data->camera->coord);
	tab[0] = ft_prod_scal(data->plane->or, data->camera->coord) + d;
	tab[1] = ft_prod_scal(data->plane->or, dir);
	tab[2] = -tab[0] / tab[1];
	inter = ft_find_point(data->camera->coord, dir, tab[2]);
	return (inter);
}

void			ft_plane(t_data *dt, t_vec3 pix, float dm[1], t_vec2 c)
{
	float	d;
	int		color_plane;
	t_vec3	i;
	float	ok;

	color_plane = ft_rgb_to_int(dt->plane->color);
	d = ft_prod_scal(dt->plane->or, dt->plane->coord) * -1;
	ok = ft_prod_scal(dt->plane->or, ft_vec3_sous(pix, dt->camera->coord));
	if (ok != 0 || (ok == 0 &&
				ft_prod_scal(dt->plane->or, dt->camera->coord) == -d))
	{
		i = ft_d_inter(dt, pix, d);
		d = ft_dist_pp(i, dt->camera->coord);
		if (ft_affiche_p(*dt, i) >= 0)
		{
			if (d < dm[0] || dm[0] == -1)
			{
				color_plane = ft_color_int(color_plane, ft_norm_p(*dt, i) / 3);
				dt->pix[c.x][c.y].color = color_plane;
				dt->pix[c.x][c.y].inter = i;
				dt->pix[c.x][c.y].shape_number = dt->shape_number;
				dm[0] = d;
			}
		}
	}
}
