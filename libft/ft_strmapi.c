/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 08:35:50 by cochapel          #+#    #+#             */
/*   Updated: 2019/11/05 08:33:13 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*modif;

	if (s == 0 || f == 0)
		return (0);
	if (!(modif = malloc((ft_strlen(s) + 1) * sizeof(char))))
	{
		return (0);
	}
	i = 0;
	while (s[i])
	{
		modif[i] = (*f)(i, s[i]);
		i++;
	}
	modif[i] = 0;
	return (modif);
}
