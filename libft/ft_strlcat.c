/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:59:50 by cochapel          #+#    #+#             */
/*   Updated: 2019/10/28 09:21:12 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(src);
	j = ft_strlen(dst);
	k = 0;
	if (size < j)
	{
		return (size + i);
	}
	dst += j;
	size -= j;
	while (src[k] && size > 1)
	{
		dst[k] = src[k];
		size--;
		k++;
	}
	dst[k] = 0;
	return (i + j);
}
