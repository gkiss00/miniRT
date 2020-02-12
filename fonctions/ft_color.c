/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:01:37 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:36:31 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int		ft_rgb_to_int(t_color rgb)
{
	int color;

	color = rgb.r * pow(16, 4);
	color += rgb.g * pow(16, 2);
	color += rgb.b;
	return (color);
}

t_color	ft_int_to_rgb(int color)
{
	t_color	rgb;

	rgb.b = color % 256;
	color /= 256;
	rgb.g = color % 256;
	color /= 256;
	rgb.r = color % 256;
	return (rgb);
}

t_color	ft_rgb_intensity(t_color rgb, float intensity)
{
	rgb.r *= intensity;
	rgb.g *= intensity;
	rgb.b *= intensity;
	return (rgb);
}

int		ft_color_int(int color, float intensity)
{
	t_color	rgb;

	rgb = ft_int_to_rgb(color);
	rgb = ft_rgb_intensity(rgb, intensity);
	color = ft_rgb_to_int(rgb);
	return (color);
}

int		ft_color_plus_color(int color, int ambiante)
{
	t_color rgb1;
	t_color rgb2;
	t_color	ret;

	rgb1 = ft_int_to_rgb(color);
	rgb2 = ft_int_to_rgb(ambiante);
	ret.r = rgb1.r + rgb2.r;
	ret.g = rgb1.g + rgb2.g;
	ret.b = rgb1.b + rgb2.b;
	if (ret.r > 255)
		ret.r = 255;
	if (ret.g > 255)
		ret.g = 255;
	if (ret.b > 255)
		ret.b = 255;
	color = ft_rgb_to_int(ret);
	return (color);
}

/*
** ret.r += ((rgb1.r / 255) * rgb2.r) / 2;
*/
