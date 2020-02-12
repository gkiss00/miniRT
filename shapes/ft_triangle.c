/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triangle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:03:56 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:49:25 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

static float	ft_is_in(t_data data, t_vec3 *inter)
{
	float	s[3];
	t_vec3	tab[6];

	tab[0] = ft_vec3_sous(data.triangle->coord1, *inter);
	tab[1] = ft_vec3_sous(data.triangle->coord2, *inter);
	tab[2] = ft_vec3_sous(data.triangle->coord3, *inter);
	tab[3] = ft_produit_vect(tab[0], tab[1]);
	tab[4] = ft_produit_vect(tab[1], tab[2]);
	tab[5] = ft_produit_vect(tab[2], tab[0]);
	s[0] = ft_prod_scal(tab[3], tab[4]);
	s[1] = ft_prod_scal(tab[4], tab[5]);
	s[2] = ft_prod_scal(tab[5], tab[3]);
	if (s[0] >= 0 && s[1] >= 0 && s[2] >= 0)
		return (ft_dist_pp(data.camera->coord, *inter));
	return (-1);
}

static int		ft_is_in_plan(t_data data, t_vec4 plan, t_vec3 coord)
{
	float	s1;
	float	s2;

	s1 = plan.x * data.camera->coord.x + plan.y * data.camera->coord.y + plan.z
		* data.camera->coord.z + plan.d;
	s2 = plan.x * coord.x + plan.y * coord.y + plan.z * coord.z + plan.d;
	if (s1 == 0 && s2 == 0)
		return (1);
	return (0);
}

static float	ft_find_inter(t_data data, t_vec3 vecteur[2], t_vec3 coord,
		t_vec3 *inter)
{
	t_vec4	plan;
	float	abc[3];

	plan.x = vecteur[1].x;
	plan.y = vecteur[1].y;
	plan.z = vecteur[1].z;
	plan.d = -(ft_prod_scal(vecteur[1], data.triangle->coord1));
	if (ft_prod_scal(vecteur[1], vecteur[0]) != 0 || (ft_prod_scal(vecteur[1],
					vecteur[0]) == 0 && ft_is_in_plan(data, plan, coord) == 1))
	{
		abc[0] = plan.x * data.camera->coord.x + plan.y * data.camera->coord.y
			+ plan.z * data.camera->coord.z + plan.d;
		abc[1] = plan.x * vecteur[0].x + plan.y * vecteur[0].y + plan.z *
			vecteur[0].z;
		abc[2] = -abc[0] / abc[1];
		*inter = ft_find_point(data.camera->coord, vecteur[0], abc[2]);
		return (ft_is_in(data, inter));
	}
	return (-1);
}

static int		ft_is_point_in(t_data data, t_vec3 vecteur[2], t_vec3 coord,
		t_vec3 *inter)
{
	t_vec3	ab;
	t_vec3	bc;
	t_vec3	ca;

	ab = ft_vec3_sous(data.triangle->coord2, data.triangle->coord1);
	bc = ft_vec3_sous(data.triangle->coord3, data.triangle->coord2);
	ca = ft_vec3_sous(data.triangle->coord1, data.triangle->coord3);
	vecteur[1] = ft_produit_vect(ab, bc);
	return (ft_find_inter(data, vecteur, coord, inter));
}

void			ft_triangle(t_data data, t_vec3 pix, float dist_min[0],
		t_vec2 coord)
{
	t_vec3	vecteur[2];
	float	dist;
	int		color_tri;
	t_vec3	inter;

	color_tri = ft_rgb_to_int(data.triangle->color);
	vecteur[0] = ft_vec3_sous(pix, data.camera->coord);
	dist = ft_is_point_in(data, vecteur, pix, &inter);
	if (ft_affiche(data, inter) >= 0)
	{
		if (dist != -1 && (dist < dist_min[0] || dist_min[0] == -1))
		{
			color_tri = ft_color_int(color_tri, ft_norm(data, pix));
			data.pix[coord.x][coord.y].color = color_tri;
			data.pix[coord.x][coord.y].inter = inter;
			data.pix[coord.x][coord.y].shape_number = data.shape_number;
			dist_min[0] = dist;
		}
	}
}
