/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 08:41:23 by cochapel          #+#    #+#             */
/*   Updated: 2019/10/28 09:24:21 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*str;
	char	*str2;

	if (dst == 0 && src == 0)
	{
		return (0);
	}
	str = (char *)src;
	str2 = (char *)dst;
	i = 0;
	while (i < n)
	{
		str2[i] = str[i];
		i++;
	}
	return (dst);
}
