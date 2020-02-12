/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:46:58 by cochapel          #+#    #+#             */
/*   Updated: 2019/11/07 20:13:32 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_of_words(char const *s, char c)
{
	int		nbr_words;
	int		i;
	char	c_bef;

	nbr_words = 0;
	c_bef = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && c_bef != c && c_bef != 0)
		{
			nbr_words++;
		}
		c_bef = s[i];
		i++;
	}
	if (c_bef != c && c_bef != 0)
	{
		nbr_words++;
	}
	return (nbr_words);
}

static void	init_tab(int *a, int *b, int *c, int *x)
{
	*a = 0;
	*b = -1;
	*c = -1;
	*x = 0;
}

static int	alloc_words(char **tab, char const *s, char c)
{
	int		tab2[4];

	init_tab(&tab2[2], &tab2[0], &tab2[1], &tab2[3]);
	while (s[++tab2[0]])
	{
		if (s[tab2[0]] != c)
			tab2[2]++;
		else
		{
			if (tab2[3] != (int)c && tab2[3] != 0)
			{
				if (!(tab[++tab2[1]] = malloc((tab2[2] + 1) * sizeof(char))))
					return (0);
				tab[tab2[1]][tab2[2]] = 0;
				tab2[2] = 0;
			}
		}
		tab2[3] = s[tab2[0]];
	}
	if (tab2[3] != (int)c && tab2[3] != 0)
		if (!(tab[++tab2[1]] = malloc(((tab2[2] + 1) * sizeof(char)))))
			return (0);
	if (tab2[3] != (int)c && tab2[3] != 0)
		tab[tab2[1]][tab2[2]] = 0;
	return (1);
}

static void	fill_words(char **tab, char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	char_bef;

	char_bef = 0;
	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[k][j] = s[i];
			j++;
		}
		if (s[i] == c && char_bef != c && char_bef != 0)
		{
			j = 0;
			k++;
		}
		char_bef = s[i];
		i++;
	}
}

char		**ft_split(char const *s, char c)
{
	char	**tab;
	int		nbr_words;
	int		i;

	if (s == 0)
		return (0);
	nbr_words = nbr_of_words(s, c);
	if (!(tab = malloc((nbr_words + 1) * sizeof(char *))))
		return (0);
	i = 0;
	while (i < nbr_words + 1)
		tab[i++] = 0;
	if (!alloc_words(tab, s, c))
	{
		i = 0;
		while (tab[i])
			free(tab[i++]);
		free(tab);
		return (0);
	}
	fill_words(tab, s, c);
	return (tab);
}
