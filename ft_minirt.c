/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minirt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:47:22 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:50:17 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			deal_key(int key, void *data)
{
	t_data	*temp;

	temp = (t_data *)data;
	if (key == 12)
		exit(0);
	else if (key == 53)
		exit(0);
	else if (key == 8)
	{
		if (temp->camera->next != NULL)
			temp->camera = temp->camera->next;
		else
			temp->camera = temp->camera_first;
		ft_data_to_screen(temp);
	}
	else if ((key >= 123 && key <= 126) || key == 69 || key == 78)
	{
		ft_move_camera(temp, key);
	}
	return (0);
}

int			deal_mouse(int button, int x, int y, void *data)
{
	t_data	*temp;

	temp = (t_data *)data;
	if (deal_mouse2(button, x, y, temp) == 0)
		return (0);
	if (button == 1)
	{
		ft_data_to_screen(temp);
	}
	return (0);
}

static int	ft_we_print(t_data *data, char *argv)
{
	int i;

	if ((data->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data->mlx_win = mlx_new_window(data->mlx_ptr, data->res.x,
					data->res.y, argv)) == NULL)
		return (EXIT_FAILURE);
	if (!(data->pix = malloc(data->res.x * sizeof(t_pix *))))
		return (-1);
	i = 0;
	while (i < data->res.x)
	{
		if (!(data->pix[i++] = malloc(data->res.y * sizeof(t_pix))))
		{
			ft_free_pix(data, i - 1);
			return (-1);
		}
	}
	ft_data_to_screen(data);
	mlx_key_hook(data->mlx_win, deal_key, data);
	mlx_mouse_hook(data->mlx_win, deal_mouse, data);
	mlx_hook(data->mlx_win, 17, 0, exit_hook, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

static int	ft_we_save(t_data *data, char *argv)
{
	int	i;

	i = 0;
	if (!(data->pix = malloc(data->res.x * sizeof(t_pix *))))
		return (-1);
	while (i < data->res.x)
	{
		if (!(data->pix[i++] = malloc(data->res.y * sizeof(t_pix))))
		{
			ft_free_pix(data, i - 1);
			return (-1);
		}
	}
	ft_data_to_screen(data);
	if (ft_save(*data, argv) == -1 && ft_putstr_fd("Error\nIn saving\n", 0))
	{
		ft_free_pix(data, data->res.x);
		return (-1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 && argc != 3 &&
			ft_putstr_fd("Error\nBad number of arguments\n", 0))
		return (EXIT_FAILURE);
	if ((data.save = 0) == 0 && argc == 3)
		if (ft_strncmp(argv[2], "-save", 6) == 0)
			data.save = 1;
	if (ft_check_and_read(argv[1], &data) == -1)
		return (EXIT_FAILURE);
	if (data.save == 0 && ft_we_print(&data, argv[1]) == -1)
	{
		ft_free(&data);
		return (EXIT_FAILURE);
	}
	else if (ft_we_save(&data, argv[1]) == -1)
	{
		ft_free(&data);
		return (EXIT_FAILURE);
	}
	ft_free(&data);
	ft_free_pix(&data, data.res.x);
	return (EXIT_SUCCESS);
}
