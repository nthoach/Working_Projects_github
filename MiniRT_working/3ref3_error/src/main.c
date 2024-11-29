/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:22:20 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/17 11:34:14 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		key_press(int keycode, t_data *type)
{
	if (keycode == 0 || keycode == 2)
	{
		if (keycode == 0)
		{
			if (type->camera->previous != NULL)
				type->camera = type->camera->previous;
		}
		else if (keycode == 2)
		{
			if (type->camera->next != NULL)
				type->camera = type->camera->next;
		}
		minirt(type);
		mlx_put_image_to_window(type->mlx.mlx_ptr, type->mlx.win_ptr,\
		type->mlx.img_ptr, 0, 0);
	}
	if (keycode == 53)
		free_exit(type, 0);
	return (0);
}

int		ft_close(t_data *type)
{
	(void)type;
	return (free_exit(type, 0));
}

void	ft_mlx(t_data *type, int wich)
{
	int endian;

	if (wich == 1)
	{
		type->mlx.mlx_ptr = mlx_init();
		type->mlx.img_ptr = mlx_new_image(type->mlx.mlx_ptr,\
			type->rsl.width, type->rsl.height);
		type->mlx.img_data = (int *)mlx_get_data_addr(type->mlx.img_ptr,\
			&type->mlx.bpp, &type->mlx.size_line, &endian);
	}
	else if (wich == 2)
	{
		type->mlx.win_ptr = mlx_new_window(type->mlx.mlx_ptr,\
			type->rsl.width, type->rsl.height, "miniRT");
		mlx_put_image_to_window(type->mlx.mlx_ptr, type->mlx.win_ptr,\
			type->mlx.img_ptr, 0, 0);
		mlx_hook(type->mlx.win_ptr, 2, 0, key_press, type);
		mlx_hook(type->mlx.win_ptr, 17, 0, ft_close, type);
		mlx_loop(type->mlx.mlx_ptr);
	}
}

int		main(int ac, char **av)
{
	t_data type;

	ft_bzero(&type, sizeof(t_data));
	parcing(&type, av, ac);
	ft_mlx(&type, 1);
	minirt(&type);
	if (type.tool.bmp == 1)
		create_bmp(&type);
	else
		ft_mlx(&type, 2);
	return (0);
}
