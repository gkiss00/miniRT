/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:47:55 by cochapel          #+#    #+#             */
/*   Updated: 2019/11/05 08:30:24 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last_occurence;

	if (s == 0)
		return (0);
	last_occurence = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			last_occurence = (char *)&s[i];
		}
		i++;
	}
	if (c == 0)
	{
		last_occurence = (char *)&s[i];
	}
	return (last_occurence);
}
