/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:06:27 by honguyen          #+#    #+#             */
/*   Updated: 2024/12/05 16:48:53 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/miniRT.h"


int key_move(int key, t_minirt *minirt)
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
		close_window(minirt, "Window Closed\n");
    ray_trace(minirt);
	return (0);
}


int	close_window(t_minirt *minirt, char *s)
{
	if (*s == 'c')
		s = "Window Closed\n";
	ft_printf("%s", s);
	free_minirt(minirt);
	exit(OK);
}

void	free_minirt(t_minirt *minirt) //*lights, *shape, **map, graph.image, graph.mlx, graph.window
{
	if (!minirt)
		return ;
	free_array(minirt->shapes);
	free_array(minirt->lights);
	free_matrix(minirt->map);
	if (minirt->graph.image)
		mlx_destroy_image(minirt->graph.mlx, minirt->graph.image);
	if (minirt->graph.window)
		mlx_destroy_window(minirt->graph.mlx, minirt->graph.window);
	#ifdef __APPLE__
	#else
		if (minirt->graph.mlx)
			mlx_destroy_display(minirt->graph.mlx);
	#endif
	if (!minirt->graph.mlx)
		free(minirt->graph.mlx);
	free(minirt);
	minirt = NULL;
}

void errors(int err_code, t_minirt *minirt)
{
	free_minirt(minirt);
	if (err_code == ER_AGC)
		ft_putstr_fd(ER_AGC_MES, 2);
	else if (err_code == ER_FILE)
		ft_putstr_fd(ER_FILE_MES, 2);
	else if (err_code == ER_ALLOC)
		ft_putstr_fd(ER_ALLOC_MES, 2);
	else
		ft_putstr_fd(ER_OTHER_MES, 2);
	exit (NOK) ;
}


int main(int agc, char **agv)
{
    t_minirt *minirt;

    if (agc != 2)
        errors(ER_AGC, NULL);
   	check_file(agv[1]);  // check valid of file *.rt  
    minirt = read_file(agv[1]);    //write file *.rt to minirt structs
    ini_all(minirt); //viewport and graphic struct
    ray_trace(minirt); //rendering images
    
	mlx_key_hook(minirt->graph.window, key_move, minirt); //detect key press and move accordingly
	mlx_hook(minirt->graph.window, DestroyNotify, StructureNotifyMask, close_window, minirt);  //detect q or control c
    mlx_loop(minirt->graph.mlx); //loop
    free_minirt(minirt);
    return (OK);
}