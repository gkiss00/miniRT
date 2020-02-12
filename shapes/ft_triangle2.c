/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triangle2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:03:41 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:49:46 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

float	ft_norm(t_data data, t_vec3 i)
{
	t_vec3	vec[2];
	t_vec3	dir[2];
	float	length[2];
	float	scal;
	float	cos;

	dir[0] = ft_find_v(data.triangle->coord1, data.triangle->coord2);
	dir[1] = ft_find_v(data.triangle->coord1, data.triangle->coord3);
	vec[0] = ft_find_v(data.camera->coord, i);
	vec[1] = ft_produit_vect(dir[0], dir[1]);
	scal = ft_prod_scal(vec[0], vec[1]);
	length[0] = ft_vec3len(vec[0]);
	length[1] = ft_vec3len(vec[1]);
	cos = scal / (length[0] * length[1]);
	return (fabs(cos));
}

float	ft_affiche(t_data data, t_vec3 i)
{
	float	cos;
	float	scal;
	float	length[2];
	t_vec3	vec[2];

	vec[0] = data.camera->or;
	vec[1] = ft_find_v(data.camera->coord, i);
	scal = ft_prod_scal(vec[0], vec[1]);
	length[0] = ft_vec3len(vec[0]);
	length[1] = ft_vec3len(vec[1]);
	cos = scal / (length[0] * length[1]);
	return (cos);
}
