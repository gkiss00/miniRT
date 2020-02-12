/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:11:32 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:44:45 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_square	*ft_add_square(t_data *data)
{
	t_square	*new;
	t_square	*temp;

	if (!(new = malloc(sizeof(t_square))))
		return (NULL);
	if (data->square != NULL)
	{
		temp = data->square;
		while (data->square->next != NULL)
		{
			data->square = data->square->next;
		}
		data->square->next = new;
		data->square = temp;
	}
	else
	{
		data->square = new;
	}
	new->next = NULL;
	return (new);
}

t_cyl		*ft_add_cyl(t_data *data)
{
	t_cyl	*new;
	t_cyl	*temp;

	if (!(new = malloc(sizeof(t_cyl))))
		return (NULL);
	if (data->cyl != NULL)
	{
		temp = data->cyl;
		while (data->cyl->next != NULL)
		{
			data->cyl = data->cyl->next;
		}
		data->cyl->next = new;
		data->cyl = temp;
	}
	else
	{
		data->cyl = new;
	}
	new->next = NULL;
	return (new);
}

t_triangle	*ft_add_triangle(t_data *data)
{
	t_triangle	*new;
	t_triangle	*temp;

	if (!(new = malloc(sizeof(t_triangle))))
		return (NULL);
	if (data->triangle != NULL)
	{
		temp = data->triangle;
		while (data->triangle->next != NULL)
		{
			data->triangle = data->triangle->next;
		}
		data->triangle->next = new;
		data->triangle = temp;
	}
	else
	{
		data->triangle = new;
	}
	new->next = NULL;
	return (new);
}
