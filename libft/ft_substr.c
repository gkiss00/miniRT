/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:56:26 by cochapel          #+#    #+#             */
/*   Updated: 2019/10/30 21:51:47 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;

	if (s == 0)
		return (0);
	if (start > ft_strlen(s))
	{
		if (!(s2 = malloc(1 * sizeof(char))))
			return (0);
		s2[0] = 0;
		return (s2);
	}
	i = 0;
	while (i < len && s[i])
		i++;
	if (!(s2 = malloc((i + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (i < len && s[i])
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
