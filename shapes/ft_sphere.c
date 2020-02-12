/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:49:13 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:48:34 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static float	ft_norm_s(t_data data, t_vec3 coord, t_vec4 i)
{
	t_vec3	vec[2];
	float	scal;
	float	length[2];
	float	cos;

	vec[0] = ft_find_v(data.camera->coord, coord);
	vec[1] = ft_find_v(data.sphere->coord, ft_v4_to_v3(i));
	scal = ft_prod_scal(vec[0], vec[1]);
	length[0] = ft_vec3len(vec[0]);
	length[1] = ft_vec3len(vec[1]);
	cos = scal / (length[0] * length[1]);
	return (fabs(cos));
}

static float	ft_check_sol(float s[2])
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

static t_vec4	ft_resolve2(t_data data, t_vec3 vect, float abcd[4])
{
	float	s[3];
	t_vec3	i;

	s[2] = -1;
	i = ft_create_v3(0, 0, 0);
	if (abcd[3] == 0)
	{
		s[0] = -abcd[1] / (2 * abcd[0]);
		if (s[0] >= 0)
		{
			i = ft_find_point(data.camera->coord, vect, s[0]);
			s[2] = ft_dist_pp(data.camera->coord, i);
		}
	}
	else if (abcd[3] > 0)
	{
		s[0] = (-abcd[1] + sqrt(abcd[3])) / (2 * abcd[0]);
		s[1] = (-abcd[1] - sqrt(abcd[3])) / (2 * abcd[0]);
		if ((s[0] = ft_check_sol(s)) != -1)
		{
			i = ft_find_point(data.camera->coord, vect, s[0]);
			s[2] = ft_dist_pp(data.camera->coord, i);
		}
	}
	return (ft_create_v4(i, s[2]));
}

static t_vec4	ft_resolve(t_data data, t_vec3 coord)
{
	float	abcd[4];
	t_vec3	temp;
	t_vec3	vect;

	vect = ft_find_v(data.camera->coord, coord);
	abcd[0] = ft_prod_scal(vect, vect);
	temp = ft_vec3_sous(data.camera->coord, data.sphere->coord);
	abcd[1] = 2 * (ft_prod_scal(temp, vect));
	abcd[2] = ft_prod_scal(temp, temp) - (pow(data.sphere->rayon, 2));
	abcd[3] = (abcd[1] * abcd[1]) - (4 * abcd[0] * abcd[2]);
	return (ft_resolve2(data, vect, abcd));
}

void			ft_sphere(t_data *data, t_vec3 pix, float dist_min[1],
		t_vec2 coord)
{
	int		color;
	t_vec4	i;

	i = ft_resolve(*data, pix);
	if (i.d != -1)
	{
		if (dist_min[0] == -1 || i.d <= dist_min[0])
		{
			color = ft_rgb_to_int(data->sphere->color);
			color = ft_color_int(color, ft_norm_s(*data, pix, i) / 3);
			data->pix[coord.x][coord.y].color = color;
			data->pix[coord.x][coord.y].inter = ft_v4_to_v3(i);
			data->pix[coord.x][coord.y].shape_number = data->shape_number;
			dist_min[0] = i.d;
		}
	}
}
