/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cyl2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 08:50:19 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:47:39 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int		ft_good_side(t_vec3 vec1, t_vec3 vec2)
{
	float	cos;

	cos = ft_prod_scal(vec1, vec2) / (ft_vec3len(vec1) * ft_vec3len(vec2));
	if (cos <= 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*
** Essayer avec coord[0]
*/

float	ft_norm_cyl(t_data data, t_vec3 coord)
{
	float	cos;
	float	t;
	t_vec3	a;
	t_vec3	vec[2];

	t = pow(ft_dist_pp(data.cyl->coord, coord), 2) - pow(data.cyl->rayon, 2);
	t /= ft_prod_scal(data.cyl->or, data.cyl->or);
	t = sqrt(t);
	a = ft_find_point(data.cyl->coord, data.cyl->or, t);
	vec[0] = ft_vec3_sous(a, coord);
	vec[1] = ft_vec3_sous(data.camera->coord, coord);
	cos = ft_prod_scal(vec[0], vec[1]) /
		(ft_vec3len(vec[0]) * ft_vec3len(vec[1]));
	return (fabs(cos));
}
