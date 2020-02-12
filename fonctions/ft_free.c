/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 08:54:12 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:36:54 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void		ft_free_pix(t_data *data, int n)
{
	int	i;

	i = 0;
	while (i < data->res.x && i < n)
	{
		free(data->pix[i++]);
	}
	free(data->pix);
}

static void	ft_free4(t_data *data, void *temp)
{
	if (data->triangle != NULL)
	{
		while (data->triangle->next != NULL)
		{
			temp = data->triangle;
			data->triangle = data->triangle->next;
			free(temp);
		}
	}
}

static void	ft_free3(t_data *data, void *temp)
{
	if (data->square != NULL)
	{
		while (data->square->next != NULL)
		{
			temp = data->square;
			data->square = data->square->next;
			free(temp);
		}
	}
	if (data->cyl != NULL)
	{
		while (data->cyl->next != NULL)
		{
			temp = data->cyl;
			data->cyl = data->cyl->next;
			free(temp);
		}
	}
	ft_free4(data, temp);
}

static void	ft_free2(t_data *data, void *temp)
{
	if (data->sphere != NULL)
	{
		while (data->sphere->next != NULL)
		{
			temp = data->sphere;
			data->sphere = data->sphere->next;
			free(temp);
		}
	}
	if (data->plane != NULL)
	{
		while (data->plane->next != NULL)
		{
			temp = data->plane;
			data->plane = data->plane->next;
			free(temp);
		}
	}
	ft_free3(data, temp);
}

void		ft_free(t_data *data)
{
	void	*temp;

	if (data->camera != NULL)
	{
		while (data->camera->next != NULL)
		{
			temp = data->camera;
			data->camera = data->camera->next;
			free(temp);
		}
	}
	if (data->light != NULL)
	{
		while (data->light->next != NULL)
		{
			temp = data->light;
			data->light = data->light->next;
			free(temp);
		}
	}
	ft_free2(data, temp);
}
