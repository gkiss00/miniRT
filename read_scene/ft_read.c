/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 09:16:09 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:45:23 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static int	ft_hub2(char *scene, t_data *data)
{
	if (scene[0] == 's' && scene[1] == 'q')
	{
		if (ft_fsquares(scene, data) == -1)
			return (-1);
	}
	else if (scene[0] == 'c' && scene[1] == 'y')
	{
		if (ft_fcyls(scene, data) == -1)
			return (-1);
	}
	else if (scene[0] == 't' && scene[1] == 'r')
	{
		if (ft_ftriangles(scene, data) == -1)
			return (-1);
	}
	return (1);
}

static int	ft_hub(char *scene, t_data *data)
{
	if (scene[0] == 'R')
		ft_fresolution(scene, data);
	else if (scene[0] == 'A')
		ft_fambiante(scene, data);
	else if (scene[0] == 'c' && scene[1] != 'y')
	{
		if (ft_fcameras(scene, data) == -1)
			return (-1);
	}
	else if (scene[0] == 'l')
	{
		if (ft_flights(scene, data) == -1)
			return (-1);
	}
	else if (scene[0] == 's' && scene[1] == 'p')
	{
		if (ft_fspheres(scene, data) == -1)
			return (-1);
	}
	else if (scene[0] == 'p' && scene[1] == 'l')
	{
		if (ft_fplanes(scene, data) == -1)
			return (-1);
	}
	return (ft_hub2(scene, data));
}

static int	ft_scene_to_data(char *scene, t_data *data)
{
	int	i;

	i = 0;
	while (scene[i] != 0)
	{
		if (ft_isalpha(scene[i]) == 1)
		{
			if (ft_hub(&scene[i], data) == -1)
				return (-1);
			while (ft_isalpha(scene[i]) == 1)
				++i;
		}
		++i;
	}
	return (1);
}

static void	ft_init(t_data *data, int n)
{
	if (n == 1)
	{
		data->camera = NULL;
		data->light = NULL;
		data->sphere = NULL;
		data->plane = NULL;
		data->square = NULL;
		data->cyl = NULL;
		data->triangle = NULL;
		return ;
	}
	data->camera_first = data->camera;
	data->sphere_first = data->sphere;
	data->light_first = data->light;
	data->plane_first = data->plane;
	data->square_first = data->square;
	data->cyl_first = data->cyl;
	data->triangle_first = data->triangle;
}

int			ft_read(int fd, t_data *data)
{
	char	*scene;
	char	buf[256];
	int		ret;

	if ((scene = ft_strdup("")) == NULL)
		return (-1);
	ft_init(data, 1);
	while ((ret = read(fd, buf, 255)) > 0)
	{
		buf[ret] = 0;
		if ((scene = ft_strnjoin_free(scene, buf, ret)) == NULL)
			return (-1);
	}
	if (ft_scene_to_data(scene, data) == -1)
	{
		free(scene);
		return (-1);
	}
	free(scene);
	ft_init(data, 2);
	return (1);
}
