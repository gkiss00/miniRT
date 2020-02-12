/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:18:29 by cochapel          #+#    #+#             */
/*   Updated: 2020/01/13 18:18:39 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./../libft.h"

int		get_next_line(int fd, char **line);
char	*ft_strndup(const char *s1, int n);
char	*ft_strnjoin(char const *s1, char const *s2, int n);

#endif
