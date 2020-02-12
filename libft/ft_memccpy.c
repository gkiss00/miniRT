/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 09:06:38 by cochapel          #+#    #+#             */
/*   Updated: 2019/10/28 15:30:15 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	int				flag;
	unsigned char	*t_dst;
	unsigned char	*t_src;

	if (dst == 0 && src == 0)
		return (dst);
	i = 0;
	flag = 1;
	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	while (i < n && flag)
	{
		if (t_src[i] == (unsigned char)c)
		{
			flag = 0;
		}
		t_dst[i] = t_src[i];
		i++;
	}
	if (flag == 0)
	{
		return (&dst[i]);
	}
	return (0);
}
