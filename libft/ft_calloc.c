/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:09:32 by cochapel          #+#    #+#             */
/*   Updated: 2019/10/25 09:00:15 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;

	if (!(mem = malloc(count * size)))
	{
		errno = ENOMEM;
		return (0);
	}
	i = 0;
	while (i < (size * count))
	{
		mem[i] = 0;
		i++;
	}
	return ((void *)mem);
}
