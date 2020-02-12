/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:43:32 by cochapel          #+#    #+#             */
/*   Updated: 2019/11/20 18:22:13 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strndup(const char *s1, int n)
{
	int		i;
	char	*s2;

	if (s1 == 0)
		return (0);
	if (!(s2 = malloc((ft_strlen(s1) + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

char		*ft_strnjoin(char const *s1, char const *s2, int n)
{
	char	*s;
	int		s_len;
	int		i;
	int		j;

	if (s1 == 0 && s2 == 0)
		return (0);
	if (s1 == 0)
		return (ft_strndup(s2, n));
	if (s2 == 0)
		return (ft_strndup(s1, n));
	i = -1;
	s_len = ft_strlen(s1);
	s_len += ft_strlen(s2);
	if (!(s = malloc((s_len + 1) * sizeof(char))))
		return (0);
	while (s1[++i])
		s[i] = s1[i];
	j = -1;
	while (s2[++j] && j < n)
		s[i + j] = s2[j];
	s[j + i] = 0;
	free((void *)s1);
	return (s);
}
