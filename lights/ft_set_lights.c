/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:35:14 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:43:08 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static void	ft_follow(t_data *data, t_vec2 coord, int color)
{
	float	norm;

	while (data->cyl != NULL)
	{
		if (ft_is_cyl_closer(data, coord) == 1)
			return ;
		data->cyl = data->cyl->next;
	}
	while (data->triangle != NULL)
	{
		if (ft_is_triangle_closer(data, coord) == 1)
			return ;
		data->triangle = data->triangle->next;
	}
	color = ft_rgb_to_int(data->light->color);
	color = ft_color_int(color, data->light->ntensity);
	norm = ft_norm_light(data, coord);
	if (norm == -1)
		return ;
	color = ft_color_int(color, norm);
	color = ft_color_plus_color(color, data->pix[coord.x][coord.y].color);
	data->pix[coord.x][coord.y].color = color;
}

static void	ft_light(t_data *data, t_vec2 coord)
{
	int	color;

	color = 0;
	ft_init_lst_shapes(data);
	while (data->sphere != NULL)
	{
		if (ft_is_sphere_closer(data, coord) == 1)
			return ;
		data->sphere = data->sphere->next;
	}
	while (data->plane != NULL)
	{
		if (ft_is_plane_closer(data, coord) == 1)
			return ;
		data->plane = data->plane->next;
	}
	while (data->square != NULL)
	{
		if (ft_is_square_closer(data, coord) == 1)
			return ;
		data->square = data->square->next;
	}
	ft_follow(data, coord, color);
}

void		ft_set_light(t_data *data, t_vec2 coord)
{
	int	color;

	if (data->pix[coord.x][coord.y].shape_number != -1)
	{
		data->light = data->light_first;
		while (data->light != NULL)
		{
			ft_light(data, coord);
			data->light = data->light->next;
		}
	}
	color = ft_rgb_to_int(data->ambiante_color);
	color = ft_color_int(color, data->ambiante_intensity);
	color = ft_color_plus_color(color, data->pix[coord.x][coord.y].color);
	data->pix[coord.x][coord.y].color = color;
}
