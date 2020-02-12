/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:36:40 by gkiss             #+#    #+#             */
/*   Updated: 2020/02/01 10:38:06 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

t_vec3	ft_addition_vect(t_vec3 s1, t_vec3 s2)
{
	t_vec3	new;

	new.x = s1.x + s2.x;
	new.y = s1.y + s2.y;
	new.z = s1.z + s2.z;
	return (new);
}

t_vec3	ft_find_point(t_vec3 or, t_vec3 dir, float t)
{
	t_vec3	new;

	new.x = or.x + dir.x * t;
	new.y = or.y + dir.y * t;
	new.z = or.z + dir.z * t;
	return (new);
}

t_vec3	ft_find_v(t_vec3 p1, t_vec3 p2)
{
	t_vec3	new;

	new.x = p2.x - p1.x;
	new.y = p2.y - p1.y;
	new.z = p2.z - p1.z;
	return (new);
}

t_vec4	ft_v3_to_v4(t_vec3 v3)
{
	t_vec4	new;

	new.x = v3.x;
	new.y = v3.y;
	new.z = v3.z;
	new.d = 0;
	return (new);
}

t_vec3	ft_v4_to_v3(t_vec4 v4)
{
	t_vec3	new;

	new.x = v4.x;
	new.y = v4.y;
	new.z = v4.z;
	return (new);
}
