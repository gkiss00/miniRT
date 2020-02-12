/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:43:32 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:37:40 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

t_vec3	ft_vec3_sous(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	sous;

	sous.x = vec1.x - vec2.x;
	sous.y = vec1.y - vec2.y;
	sous.z = vec1.z - vec2.z;
	return (sous);
}

t_vec3	ft_produit_vect(t_vec3 ab, t_vec3 bc)
{
	t_vec3	n;

	n.x = ab.y * bc.z - ab.z * bc.y;
	n.y = ab.z * bc.x - ab.x * bc.z;
	n.z = ab.x * bc.y - ab.y * bc.x;
	return (n);
}

float	ft_prod_scal(t_vec3 vec1, t_vec3 vec2)
{
	float	prod;

	prod = vec1.x * vec2.x;
	prod += vec1.y * vec2.y;
	prod += vec1.z * vec2.z;
	return (prod);
}

float	ft_dist_pp(t_vec3 vec1, t_vec3 vec2)
{
	float	dist;

	dist = pow(vec1.x - vec2.x, 2);
	dist += pow(vec1.y - vec2.y, 2);
	dist += pow(vec1.z - vec2.z, 2);
	dist = sqrt(dist);
	return (dist);
}

float	ft_vec3len(t_vec3 vec)
{
	float	dist;

	dist = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
	dist = sqrt(dist);
	return (dist);
}
