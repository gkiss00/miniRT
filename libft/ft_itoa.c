/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:32:37 by cochapel          #+#    #+#             */
/*   Updated: 2019/10/30 21:48:01 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_chfr(int n)
{
	int	somme;

	somme = 1;
	while (n >= 10)
	{
		somme++;
		n = n / 10;
	}
	return (somme);
}

static char	*nbr_min(void)
{
	char	*str;

	if (!(str = malloc(12 * sizeof(char))))
	{
		return (0);
	}
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

static void	neg_init(int *n, int *tab)
{
	*n = *n * -1;
	tab[0] = 1;
	tab[2] = 1;
}

char		*ft_itoa(int n)
{
	char	*str;
	int		tab[3];

	if (n == -2147483648)
		return (nbr_min());
	tab[0] = 0;
	tab[2] = 0;
	if (n < 0)
		neg_init(&n, tab);
	tab[0] += nbr_chfr(n);
	if (!(str = malloc((tab[0] + 1) * sizeof(char))))
		return (0);
	tab[1] = tab[2] - 1;
	if (tab[2])
		str[0] = '-';
	while (++tab[1] < tab[0])
	{
		str[tab[0] - tab[1] - 1 + tab[2]] = n % 10 + '0';
		n = n / 10;
	}
	str[tab[0]] = 0;
	return (str);
}
