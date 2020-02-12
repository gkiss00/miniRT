/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 09:39:18 by cochapel          #+#    #+#             */
/*   Updated: 2019/11/05 08:28:35 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	int				flag;
	unsigned char	*t_s;

	if (s == 0)
		return (0);
	t_s = (unsigned char *)s;
	i = 0;
	flag = 1;
	while (i < n && flag)
	{
		if (t_s[i] == (unsigned char)c)
		{
			flag = 0;
		}
		i++;
	}
	if (flag == 0)
	{
		return (&t_s[i - 1]);
	}
	return (0);
}
