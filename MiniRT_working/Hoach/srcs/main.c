/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:06:27 by honguyen          #+#    #+#             */
/*   Updated: 2024/12/02 15:13:46 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/miniRT.h"


void	close_minirt(t_minirt *minirt)
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

int KeyMove(int key, t_minirt *minirt)
{
	if (key == KEY_LEFT || key == KEY_A)
		minirt->camera.center.x -= 10;
	else if (key == KEY_RIGHT || key == KEY_D)
		minirt->camera.center.x += 10;
	else if (key == KEY_UP || key == KEY_W)
		minirt->camera.center.y += 10;
	else if (key == KEY_DOWN || key == KEY_S)
		minirt->camera.center.y -= 10;
    else if (key == KEY_C)
		minirt->camera.center.z -= 10;
	else if (key == KEY_V)
		minirt->camera.center.z += 10;
	else if (key == KEY_ESC || key == KEY_Q)
		CloseWindow(minirt, "Window Closed\n");
    raytrace(minirt);
	return (0);
}

int	CloseWindow(t_minirt *minirt, char *s)
{
	if (*s == 'c')
		s = "Window Closed\n";
	ft_printf("%s", s);
	mlx_clear_window(minirt->graph.mlx, minirt->graph.window);
	mlx_destroy_window(minirt->graph.mlx, minirt->graph.window);
	close_minirt(minirt);
	exit(OK);
    return OK;
}

int main(int agc, char **agv)
{
    t_minirt *minirt;

    if (agc != 2)
        return errors(ER_AGC, NULL);
   //check_rt(agv[1]);    
    //ft_memset(minirt, 0, sizeof(t_minirt));
    minirt = parse_rt(agv[1]);    
	// minirt->graph.mlx = mlx_init();
	// if (!minirt->graph.mlx)
	// 	error(E_MLX, minirt);
    ini_all(minirt);
    raytrace(minirt);
    
	mlx_key_hook(minirt->graph.window, KeyMove, minirt);
	mlx_hook(minirt->graph.window, DestroyNotify, StructureNotifyMask, CloseWindow, minirt);  //17, 0
    
	mlx_loop(minirt->graph.mlx);
    close_minirt(minirt);
    return (OK);
}