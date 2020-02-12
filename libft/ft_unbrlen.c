/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <cochapel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:03:32 by cochapel          #+#    #+#             */
/*   Updated: 2020/01/13 18:17:15 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unbrlen(size_t n, int base)
{
	int	len;

	len = 1;
	while (n >= (size_t)base)
	{
		n = n / base;
		++len;
	}
	return (len);
}
