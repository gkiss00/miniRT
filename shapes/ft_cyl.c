/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cyl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:53:01 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:47:20 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static float	ft_checkol(float s[2])
{
	if (s[0] >= 0 && s[1] >= 0)
	{
		if (s[0] > s[1])
			return (s[1]);
		return (s[0]);
	}
	else if (s[0] < 0 && s[1] >= 0)
		return (s[1]);
	else if (s[0] >= 0 && s[1] < 0)
	{
		return (s[0]);
	}
	else
		return (-1);
}

static void		ft_init(float *dist, t_vec3 *i)
{
	*dist = -1;
	i->x = 0;
	i->y = 0;
	i->z = 0;
}

static t_vec4	ft_resolve2(t_data data, t_vec3 vect, float abcd[4])
{
	float	s[2];
	float	dist;
	t_vec3	i;

	ft_init(&dist, &i);
	if (abcd[3] == 0)
	{
		s[0] = -abcd[1] / (2 * abcd[0]);
		if (s[0] >= 0)
		{
			i = ft_find_point(data.camera->coord, vect, s[0]);
			dist = ft_dist_pp(data.camera->coord, i);
		}
	}
	else if (abcd[3] > 0)
	{
		s[0] = (-abcd[1] + sqrt(abcd[3])) / (2 * abcd[0]);
		s[1] = (-abcd[1] - sqrt(abcd[3])) / (2 * abcd[0]);
		if ((s[0] = ft_checkol(s)) != -1)
		{
			i = ft_find_point(data.camera->coord, vect, s[0]);
			dist = ft_dist_pp(data.camera->coord, i);
		}
	}
	return (ft_create_v4(i, dist));
}

static t_vec4	ft_resolve(t_data data, t_vec3 coord)
{
	float	abcd[4];
	t_vec3	temp;
	t_vec3	vect;

	vect = ft_find_v(data.camera->coord, coord);
	abcd[0] = ft_prod_scal(vect, vect) -
		pow(ft_prod_scal(vect, data.cyl->or), 2);
	temp = ft_vec3_sous(data.camera->coord, data.cyl->coord);
	abcd[1] = 2 * (ft_prod_scal(temp, vect) -
			(ft_prod_scal(vect, data.cyl->or) *
			ft_prod_scal(temp, data.cyl->or)));
	abcd[2] = ft_prod_scal(temp, temp) -
		pow(ft_prod_scal(temp, data.cyl->or), 2) -
		(pow(data.cyl->rayon, 2));
	abcd[3] = (abcd[1] * abcd[1]) - (4 * abcd[0] * abcd[2]);
	return (ft_resolve2(data, vect, abcd));
}

void			ft_cyl(t_data *data, t_vec3 pix, float dist_min[1],
		t_vec2 coord)
{
	int		color;
	float	dist_max;
	t_vec4	i;
	t_vec3	temp;

	i = ft_resolve(*data, pix);
	dist_max = sqrt(pow(data->cyl->hight, 2) + pow(data->cyl->rayon, 2));
	temp = ft_vec3_sous(data->cyl->coord, ft_v4_to_v3(i));
	if (i.d != -1 && ft_dist_pp(ft_v4_to_v3(i), data->cyl->coord) <= dist_max &&
			ft_good_side(temp, data->cyl->or))
	{
		if (dist_min[0] == -1 || i.d <= dist_min[0])
		{
			color = ft_rgb_to_int(data->cyl->color);
			color = ft_color_int(color, ft_norm_cyl(*data, pix) / 3);
			data->pix[coord.x][coord.y].color = color;
			data->pix[coord.x][coord.y].inter = ft_v4_to_v3(i);
			data->pix[coord.x][coord.y].shape_number = data->shape_number;
			dist_min[0] = i.d;
		}
	}
}
