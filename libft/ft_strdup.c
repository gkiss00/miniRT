/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 09:56:28 by cochapel          #+#    #+#             */
/*   Updated: 2019/11/05 08:32:29 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	if (s1 == 0)
		return (0);
	i = 0;
	while (s1[i] != 0)
	{
		i++;
	}
	if (!(s2 = malloc((i + 1) * sizeof(char))))
	{
		return (0);
	}
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
