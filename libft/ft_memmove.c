/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 09:23:32 by cochapel          #+#    #+#             */
/*   Updated: 2019/10/28 11:54:23 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*t_dst;
	unsigned char	*t_src;

	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	if (src < dst && dst < src + len)
	{
		while (len)
		{
			t_dst[len - 1] = t_src[len - 1];
			len--;
		}
	}
	else
	{
		dst = ft_memcpy(dst, src, len);
	}
	return (dst);
}
