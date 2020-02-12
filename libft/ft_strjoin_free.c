/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:14:56 by cochapel          #+#    #+#             */
/*   Updated: 2020/01/13 18:16:59 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin_free(char *s1, char *s2, int x)
{
	char	*s;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = -1;
	if (!(s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (0);
	while (s1[++i])
		s[i] = s1[i];
	j = i;
	i = 0;
	while (s2[i])
	{
		s[j + i] = s2[i];
		i++;
	}
	s[j + i] = 0;
	if (x > 0)
		free(s1);
	return (s);
}
