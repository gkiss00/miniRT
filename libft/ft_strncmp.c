/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:01:34 by cochapel          #+#    #+#             */
/*   Updated: 2019/11/05 14:57:18 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		retour;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	retour = 0;
	if (n > 0)
	{
		while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		{
			i++;
		}
		retour = (unsigned char)s1[i] - (unsigned char)s2[i];
	}
	return (retour);
}
