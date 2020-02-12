/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 09:47:50 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:45:02 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

float	ft_fatoi_s(const char *str, int *n)
{
	int		i;
	int		j;
	float	nbr;
	int		signe;

	i = 0;
	nbr = 0;
	signe = 1;
	if (str[0] == '-')
	{
		signe = -1;
		++i;
	}
	while (ft_isdigit(str[i]) == 1)
		nbr = (nbr * 10) + str[i++] - '0';
	if (str[i] == '.')
	{
		++i;
		j = 1;
		while (ft_isdigit(str[i]) == 1)
			nbr += (str[i++] - '0') / pow(10, j++);
	}
	*n += i;
	return (nbr * signe);
}

int		ft_atoi_s(const char *str, int *n)
{
	int					i;
	unsigned long long	nbr;
	int					sign;

	if (str == 0)
		return (0);
	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
				str[i] == '\r' || str[i] == '\f' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i++] - 48;
	}
	*n += i;
	if (nbr > 9223372036854775807 && sign == 1)
		return (-1);
	if (nbr > 9223372036854775807 && sign == -1)
		return (0);
	return (sign * nbr);
}
