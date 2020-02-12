/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:40:00 by cochapel          #+#    #+#             */
/*   Updated: 2020/01/22 17:40:24 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "./../minirt.h"

int	ft_error(int fd);
int	check_r(char *line);
int	check_a(char *line);
int	check_c(char *line);
int	check_l(char *line);
int	check_sp(char *line);
int	check_pl(char *line);
int	check_sq(char *line);
int	check_cy(char *line);
int	check_tr(char *line);
int	check_float(char *line, int i);
int	check_float_pos(char *line, int i);
int	check_float_neg(char *line, int i);
int	check_int_pos(char *line, int i);
int	check_int(char *line, int i);

#endif
