/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light_norm2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:40:29 by gkiss             #+#    #+#             */
/*   Updated: 2020/02/01 10:42:17 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

int		ft_same_side(t_data *data, t_vec2 coord, t_vec3 normale)
{
	t_vec3	cam;
	t_vec3	light;
	float	cos[2];

	cam = ft_vec3_sous(data->camera->coord, data->pix[coord.x][coord.y].inter);
	light = ft_vec3_sous(data->light->coord, data->pix[coord.x][coord.y].inter);
	cos[0] = ft_prod_scal(cam, normale) / (ft_vec3len(cam) *
			ft_vec3len(normale));
	cos[1] = ft_prod_scal(light, normale) / (ft_vec3len(light) *
			ft_vec3len(normale));
	if (cos[0] < 0 && cos[1] < 0)
		return (1);
	else if (cos[0] > 0 && cos[1] > 0)
		return (1);
	else if (cos[0] == 0 && cos[1] == 0)
		return (1);
	return (0);
}

float	ft_norm_tri(t_data *data, t_vec2 coord, t_vec3 *normale)
{
	t_vec3	vec[5];
	float	length[2];
	float	scal;
	float	cos;

	vec[0] = ft_find_v(data->camera->coord, data->pix[coord.x][coord.y].inter);
	vec[2] = ft_find_v(data->triangle->coord1, data->triangle->coord2);
	vec[3] = ft_find_v(data->triangle->coord1, data->triangle->coord3);
	vec[4] = ft_produit_vect(vec[2], vec[3]);
	*normale = vec[4];
	scal = ft_prod_scal(vec[0], *normale);
	length[0] = ft_vec3len(vec[0]);
	length[1] = ft_vec3len(*normale);
	cos = scal / (length[0] * length[1]);
	return (fabs(cos));
}

float	ft_norm_sqrt(t_data *data, t_vec2 coord, t_vec3 *normale)
{
	t_vec3	vec[2];
	float	length[2];
	float	scal;
	float	cos;

	vec[0] = ft_find_v(data->camera->coord, data->pix[coord.x][coord.y].inter);
	*normale = data->square->or;
	scal = ft_prod_scal(vec[0], *normale);
	length[0] = ft_vec3len(vec[0]);
	length[1] = ft_vec3len(*normale);
	cos = scal / (length[0] * length[1]);
	return (fabs(cos));
}

float	ft_norm_sphere(t_data *data, t_vec2 coord, t_vec3 *normale)
{
	t_vec3	vec[2];
	float	scal;
	float	length[2];
	float	cos;

	vec[0] = ft_find_v(data->light->coord, data->pix[coord.x][coord.y].inter);
	*normale = ft_find_v(data->sphere->coord,
			data->pix[coord.x][coord.y].inter);
	scal = ft_prod_scal(vec[0], *normale);
	length[0] = ft_vec3len(vec[0]);
	length[1] = ft_vec3len(*normale);
	cos = scal / (length[0] * length[1]);
	return (fabs(cos));
}

float	ft_norm_plane(t_data *data, t_vec2 coord, t_vec3 *normale)
{
	t_vec3	vec[2];
	float	length[2];
	float	scal;
	float	cos;

	vec[0] = ft_find_v(data->camera->coord, data->pix[coord.x][coord.y].inter);
	*normale = data->plane->or;
	scal = ft_prod_scal(vec[0], *normale);
	length[0] = ft_vec3len(vec[0]);
	length[1] = ft_vec3len(*normale);
	cos = scal / (length[0] * length[1]);
	return (fabs(cos));
}
