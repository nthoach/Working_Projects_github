/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:12:50 by honguyen          #+#    #+#             */
/*   Updated: 2024/12/02 11:47:24 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

int	errors(int err_code, t_minirt *minirt)
{
	close_minirt(minrt);
	if (err_code == AGC)
		ft_putstr_fd("Usages, ./miniRT scenes/subject/cylinder.rt\n", 2);
	else if (err_code == ER_MLX)
		ft_putstr_fd("Error in MLX initialization \n", 2);
	else if (err_code == ER_MOR)
		ft_putstr_fd("Error in MORE \n", 2);
	else
		ft_putstr_fd("Other Errors \n", 2);
	return (err_code);
}

void	clsoe_minirt(t_minirt *minirt)
{
	int	i;

	i = 0;
	if (!(minirt->map))
		return ;
	while (minirt->map[i])
	{
		free(minirt->map[i]);
		minirt->map[i] = NULL;
		i++;
	}
	free(minirt->map);
	minirt->map = NULL;
}

int	user_move(int key, t_minirt *minirt)
{
	if (key == KEY_LEFT || key == KEY_A)
		move_step(minirt, 0, -1);
	else if (key == KEY_RIGHT || key == KEY_D)
		move_step(minirt, 0, 1);
	else if (key == KEY_UP || key == KEY_W)
		move_step(minirt, -1, 0);
	else if (key == KEY_DOWN || key == KEY_S)
		move_step(minirt, 1, 0);
	else if (key == KEY_ESC || key == KEY_Q)
		close_window(minirt, "Window Closed\n");
	return (0);
}

int	close_window(t_minirt *minirt, char *s)
{
	if (*s == 'c')
		s = "Window Closed\n";
	ft_printf("%s", s);
	mlx_clear_window(minirt->mlx, minirt->mlx_win);
	mlx_destroy_window(minirt->mlx, minirt->mlx_win);
	free_minirt(minirt);
	exit(0);
}