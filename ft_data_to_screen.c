/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_to_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:54:54 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:50:12 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			ft_check_and_read(char *file_rt, t_data *data)
{
	int		fd;

	if (ft_strnstr(file_rt, ".rt", ft_strlen(file_rt)) == NULL)
	{
		ft_putstr_fd("Error\nNot a .rt file\n", 0);
		return (-1);
	}
	fd = open(file_rt, O_RDONLY);
	if (ft_error(fd) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	fd = open(file_rt, O_RDONLY);
	if (ft_read(fd, data) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}

int			exit_hook(void)
{
	exit(0);
}

static void	ft_init_screen(t_data *data)
{
	t_vec2	coord;

	coord.y = 0;
	while (coord.y < data->res.y)
	{
		coord.x = 0;
		while (coord.x < data->res.x)
		{
			data->pix[coord.x][coord.y].color = 0;
			data->pix[coord.x][coord.y].inter.x = 0;
			data->pix[coord.x][coord.y].inter.y = 0;
			data->pix[coord.x][coord.y].inter.z = 0;
			data->pix[coord.x][coord.y].shape_number = -1;
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, coord.x, coord.y, 0x00);
			++coord.x;
		}
		++coord.y;
	}
}

void		ft_data_to_screen(t_data *data)
{
	t_vec2	coord;
	t_vec3	pix;

	if (data->save == 0)
		ft_init_screen(data);
	coord.y = 0;
	while (coord.y < data->res.y)
	{
		coord.x = 0;
		while (coord.x < data->res.x)
		{
			data->pix[coord.x][coord.y].shape_number = -1;
			pix = ft_find_pix(*data, coord);
			ft_set_shapes(data, pix, coord);
			ft_set_light(data, coord);
			if (data->save == 0)
				mlx_pixel_put(data->mlx_ptr, data->mlx_win, coord.x, coord.y,
						data->pix[coord.x][coord.y].color);
			++coord.x;
		}
		++coord.y;
	}
}
