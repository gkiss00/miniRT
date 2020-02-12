/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:22:40 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:44:28 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_camera	*ft_add_camera(t_data *data)
{
	t_camera	*new;
	t_camera	*temp;

	if (!(new = malloc(sizeof(t_camera))))
		return (NULL);
	if (data->camera != NULL)
	{
		temp = data->camera;
		while (data->camera->next != NULL)
		{
			data->camera = data->camera->next;
		}
		data->camera->next = new;
		data->camera = temp;
	}
	else
	{
		data->camera = new;
	}
	new->next = NULL;
	return (new);
}

t_light		*ft_add_light(t_data *data)
{
	t_light	*new;
	t_light	*temp;

	if (!(new = malloc(sizeof(t_light))))
		return (NULL);
	if (data->light != NULL)
	{
		temp = data->light;
		while (data->light->next != NULL)
		{
			data->light = data->light->next;
		}
		data->light->next = new;
		data->light = temp;
	}
	else
	{
		data->light = new;
	}
	new->next = NULL;
	return (new);
}

t_sphere	*ft_add_sphere(t_data *data)
{
	t_sphere	*new;
	t_sphere	*temp;

	if (!(new = malloc(sizeof(t_sphere))))
		return (NULL);
	if (data->sphere != NULL)
	{
		temp = data->sphere;
		while (data->sphere->next != NULL)
		{
			data->sphere = data->sphere->next;
		}
		data->sphere->next = new;
		data->sphere = temp;
	}
	else
	{
		data->sphere = new;
	}
	new->next = NULL;
	return (new);
}

t_plane		*ft_add_plane(t_data *data)
{
	t_plane	*new;
	t_plane	*temp;

	if (!(new = malloc(sizeof(t_plane))))
		return (NULL);
	if (data->plane != NULL)
	{
		temp = data->plane;
		while (data->plane->next != NULL)
		{
			data->plane = data->plane->next;
		}
		data->plane->next = new;
		data->plane = temp;
	}
	else
	{
		data->plane = new;
	}
	new->next = NULL;
	return (new);
}
