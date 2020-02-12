/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:03:26 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:49:07 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

float	ft_is_sq(t_data data, t_triangle triangle, t_vec3 inter)
{
	float	s[3];
	t_vec3	tab[6];

	tab[0] = ft_vec3_sous(triangle.coord1, inter);
	tab[1] = ft_vec3_sous(triangle.coord2, inter);
	tab[2] = ft_vec3_sous(triangle.coord3, inter);
	tab[3] = ft_produit_vect(tab[0], tab[1]);
	tab[4] = ft_produit_vect(tab[1], tab[2]);
	tab[5] = ft_produit_vect(tab[2], tab[0]);
	s[0] = ft_prod_scal(tab[3], tab[4]);
	s[1] = ft_prod_scal(tab[4], tab[5]);
	s[2] = ft_prod_scal(tab[5], tab[3]);
	if (s[0] >= 0 && s[1] >= 0 && s[2] >= 0)
	{
		return (ft_dist_pp(data.camera->coord, inter));
	}
	return (-1);
}

float	ft_is_sq2(t_data data, t_triangle triangle, t_vec3 inter)
{
	float	s[3];
	t_vec3	tab[6];

	tab[0] = ft_vec3_sous(triangle.coord1, inter);
	tab[1] = ft_vec3_sous(triangle.coord2, inter);
	tab[2] = ft_vec3_sous(triangle.coord3, inter);
	tab[3] = ft_produit_vect(tab[0], tab[1]);
	tab[4] = ft_produit_vect(tab[1], tab[2]);
	tab[5] = ft_produit_vect(tab[2], tab[0]);
	s[0] = ft_prod_scal(tab[3], tab[4]);
	s[1] = ft_prod_scal(tab[4], tab[5]);
	s[2] = ft_prod_scal(tab[5], tab[3]);
	if (s[0] >= 0 && s[1] >= 0 && s[2] >= 0)
	{
		return (ft_dist_pp(data.light->coord, inter));
	}
	return (-1);
}

float	ft_norm_sq(t_data data, t_vec3 i)
{
	float	length[2];
	float	scal;
	float	cos;

	scal = ft_prod_scal(data.square->or, ft_find_v(data.camera->coord, i));
	length[0] = ft_vec3len(data.square->or);
	length[1] = ft_vec3len(ft_find_v(data.camera->coord, i));
	cos = scal / (length[0] * length[1]);
	return (fabs(cos));
}

float	ft_affiche_sq(t_data data, t_vec3 i)
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
