/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:36:46 by gkiss             #+#    #+#             */
/*   Updated: 2020/02/01 10:38:40 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

t_vec4		ft_create_v4(t_vec3 v, float dist)
{
	t_vec4	new;

	new.x = v.x;
	new.y = v.y;
	new.z = v.z;
	new.d = dist;
	return (new);
}

t_vec3		ft_create_v3(float x, float y, float z)
{
	t_vec3	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_triangle	ft_create_tr(t_vec3 p1, t_vec3 p2, t_vec3 p3)
{
	t_triangle new;

	new.coord1 = p1;
	new.coord2 = p2;
	new.coord3 = p3;
	return (new);
}

t_vec4		ft_find_p(t_vec3 p1, t_vec3 p2, t_vec3 p3)
{
	t_vec3	tab[3];
	float	d;

	tab[0] = ft_find_v(p1, p2);
	tab[1] = ft_find_v(p1, p3);
	tab[2] = ft_produit_vect(tab[0], tab[1]);
	d = -ft_prod_scal(tab[2], p1);
	return (ft_create_v4(tab[2], d));
}
