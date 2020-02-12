/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_shapes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:31:08 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:48:18 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

static void	ft_set_shapes2(t_data *data, t_vec3 pix, t_vec2 coord,
		float dist_min[0])
{
	while (data->cyl != NULL)
	{
		ft_cyl(data, pix, dist_min, coord);
		++data->shape_number;
		data->cyl = data->cyl->next;
	}
	while (data->triangle != NULL)
	{
		ft_triangle(*data, pix, dist_min, coord);
		++data->shape_number;
		data->triangle = data->triangle->next;
	}
}

void		ft_set_shapes(t_data *data, t_vec3 pix, t_vec2 coord)
{
	float	dist_min[1];

	data->shape_number = 0;
	dist_min[0] = -1;
	ft_init_lst_shapes(data);
	while (data->sphere != NULL)
	{
		ft_sphere(data, pix, dist_min, coord);
		++data->shape_number;
		data->sphere = data->sphere->next;
	}
	while (data->plane != NULL)
	{
		ft_plane(data, pix, dist_min, coord);
		++data->shape_number;
		data->plane = data->plane->next;
	}
	while (data->square != NULL)
	{
		ft_square(*data, pix, dist_min, coord);
		++data->shape_number;
		data->square = data->square->next;
	}
	ft_set_shapes2(data, pix, coord, dist_min);
}
