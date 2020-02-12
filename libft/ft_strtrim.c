/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:20:05 by cochapel          #+#    #+#             */
/*   Updated: 2019/10/30 21:52:35 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_nbr_chr_before(char const *s1, char const *set)
{
	int		flag;
	int		ok;
	int		i;
	int		j;
	int		nbr;

	i = -1;
	ok = 0;
	nbr = 0;
	flag = 1;
	while (s1[++i] && flag)
	{
		j = -1;
		ok = 0;
		while (set[++j])
		{
			if (set[j] == s1[i])
				ok = 1;
		}
		if (ok == 1)
			nbr++;
		else
			flag = 0;
	}
	return (nbr);
}

static int		ft_nbr_chr_after(char const *s1, char const *set)
{
	int		flag;
	int		ok;
	int		i;
	int		j;
	int		nbr;

	i = ft_strlen(s1);
	ok = 0;
	nbr = 0;
	flag = 1;
	while (--i >= 0 && flag)
	{
		j = -1;
		ok = 0;
		while (set[++j])
		{
			if (set[j] == s1[i])
				ok = 1;
		}
		if (ok == 1)
			nbr++;
		else
			flag = 0;
	}
	return (nbr);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		i;
	int		j;
	int		end;

	if (s1 == 0 || set == 0)
		return (0);
	j = 0;
	i = ft_nbr_chr_before(s1, set);
	end = ft_strlen(s1) - ft_nbr_chr_after(s1, set);
	if (end - i + 1 <= 0)
	{
		if (!(s = malloc((1) * sizeof(char))))
			return (0);
		s[0] = 0;
		return (s);
	}
	if (!(s = malloc((end - i + 1) * sizeof(char))))
		return (0);
	while (i < end)
		s[j++] = s1[i++];
	s[j] = 0;
	return (s);
}
