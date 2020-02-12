/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fcts3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:16:08 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:46:20 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ft_fresolution(char *scene, t_data *data)
{
	int	i;

	i = 0;
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
	{
		++i;
	}
	data->res.x = ft_atoi_s(&scene[i], &i);
	if (data->res.x > 3200)
		data->res.x = 3200;
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
	{
		++i;
	}
	data->res.y = ft_atoi_s(&scene[i], &i);
	if (data->res.y > 1800)
		data->res.y = 1800;
}

void	ft_fambiante(char *scene, t_data *data)
{
	int	i;

	i = 0;
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
	{
		++i;
	}
	data->ambiante_intensity = ft_fatoi_s(&scene[i], &i);
	while (ft_isdigit(scene[i]) == 0 && scene[i] != '-')
	{
		++i;
	}
	data->ambiante_color = ft_fcolor(&scene[i], &i);
}
