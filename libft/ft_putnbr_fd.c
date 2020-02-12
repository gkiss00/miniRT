/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 09:35:15 by cochapel          #+#    #+#             */
/*   Updated: 2019/11/26 14:16:30 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	str[50];

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		i = 0;
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * -1;
		}
		while (n >= 10)
		{
			str[i] = (n % 10) + '0';
			n = n / 10;
			i++;
		}
		str[i] = (n % 10) + '0';
		i += 1;
		while (--i >= 0)
			ft_putchar_fd(str[i], fd);
	}
}
