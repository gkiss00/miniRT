/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:37:41 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:37:16 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void		ft_init_lst_shapes(t_data *data)
{
	data->sphere = data->sphere_first;
	data->plane = data->plane_first;
	data->square = data->square_first;
	data->cyl = data->cyl_first;
	data->triangle = data->triangle_first;
}

static void	ft_check_values(t_vec3 *coord)
{
	if (coord->x > 1.0)
		coord->x = 1.0;
	if (coord->x < -1.0)
		coord->x = -1.0;
	if (coord->y > 1.0)
		coord->y = 1.0;
	if (coord->y < -1.0)
		coord->y = -1.0;
	if (coord->z > 1.0)
		coord->z = 1.0;
	if (coord->z < -1.0)
		coord->z = -1.0;
}

void		ft_move_camera(t_data *data, int key)
{
	if (key == 123)
		data->camera->or.x += 0.1;
	else if (key == 124)
		data->camera->or.x -= 0.1;
	else if (key == 125)
		data->camera->or.y += 0.1;
	else if (key == 126)
		data->camera->or.y -= 0.1;
	else if (key == 69)
		data->camera->or.z += 0.1;
	else if (key == 78)
		data->camera->or.z -= 0.1;
	ft_check_values(&data->camera->or);
	ft_data_to_screen(data);
}

static int	deal_mouse3(int button, int x, int y, t_data *temp)
{
	if (button == 1 && x < (temp->res.x / 3) && y < (temp->res.x / 3))
	{
		temp->camera->coord.y -= temp->res.y / 10;
		temp->camera->coord.x += temp->res.x / 10;
	}
	else if (button == 1 && x > 2 * (temp->res.x / 3) && y < (temp->res.x / 3))
	{
		temp->camera->coord.y -= temp->res.y / 10;
		temp->camera->coord.x -= temp->res.x / 10;
	}
	else if (button == 1 && x < (temp->res.x / 3) && y > 2 * (temp->res.x / 3))
	{
		temp->camera->coord.y += temp->res.y / 10;
		temp->camera->coord.x += temp->res.x / 10;
	}
	else if (button == 1 && x > 2 * (temp->res.x / 3) && y > 2 *
			(temp->res.x / 3))
	{
		temp->camera->coord.y += temp->res.y / 10;
		temp->camera->coord.x -= temp->res.x / 10;
	}
	else
		return (0);
	return (1);
}

int			deal_mouse2(int button, int x, int y, t_data *temp)
{
	if (deal_mouse3(button, x, y, temp) == 1)
		return (1);
	else if (button == 1 && x < (temp->res.x / 3))
		temp->camera->coord.x += temp->res.x / 10;
	else if (button == 1 && x > 2 * (temp->res.x / 3))
		temp->camera->coord.x -= temp->res.x / 10;
	else if (button == 1 && y < (temp->res.x / 3))
		temp->camera->coord.y -= temp->res.y / 10;
	else if (button == 1 && y > 2 * (temp->res.x / 3))
		temp->camera->coord.y += temp->res.y / 10;
	else
		return (0);
	return (1);
}
