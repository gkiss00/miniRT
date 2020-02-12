/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <cochapel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:06:52 by cochapel          #+#    #+#             */
/*   Updated: 2020/01/13 18:14:29 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	hex_letters(int n, int x_case)
{
	char c;

	c = 0;
	if (n == 10)
		c = 'a' - (x_case * ('a' - 'A'));
	else if (n == 11)
		c = 'b' - (x_case * ('a' - 'A'));
	else if (n == 12)
		c = 'c' - (x_case * ('a' - 'A'));
	else if (n == 13)
		c = 'd' - (x_case * ('a' - 'A'));
	else if (n == 14)
		c = 'e' - (x_case * ('a' - 'A'));
	else if (n == 15)
		c = 'f' - (x_case * ('a' - 'A'));
	else if (n >= 0 && n <= 9)
		c = n + '0';
	return (c);
}

int			ft_puthex_fd(unsigned int n, int fd, int x_case)
{
	int		i;
	int		retour;
	char	str[50];

	retour = 0;
	i = 0;
	while (n >= 16)
	{
		str[i] = hex_letters((n % 16), x_case);
		n = n / 16;
		i++;
	}
	str[i] = hex_letters((n % 16), x_case);
	i += 1;
	while (--i >= 0)
		retour += ft_putchar_fd(str[i], fd);
	return (retour);
}
