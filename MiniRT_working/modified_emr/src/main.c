/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nth <nth@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:35:32 by nth          #+#    #+#             */
/*   Updated: 2024/10/07 06:14:48 by nth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macros.h"
#include "miniRT.h"
#include "mlx.h"
#include "keys.h"

void	ini_mlx(t_minirt *minirt)
{
	minirt->mlx = mlx_init();
	if (!minirt->mlx)
	{
		write(2, "FATAL: error initialising minilibx.", 36);
		exit(2);
	}
	minirt->win = mlx_new_window(\
		minirt->mlx, \
		FRAME_W, \
		FRAME_H, \
		"miniRT" \
	);
	if (!create_canvas(minirt, FRAME_W, FRAME_H))
	{
		mlx_destroy_window(minirt->mlx, minirt->win);
		free(minirt->mlx);
		exit(2);
	}
}

void	start_rt(t_minirt *minirt)
{
	minirt->selected = (struct s_select){.is_cam = true, .object = NULL};
	mlx_hook(minirt->win, ON_KEYDOWN, 1L, &check_key_presses, minirt);
	mlx_hook(minirt->win, ON_KEYUP, 1L << 1, &check_key_releases, minirt);
	mlx_hook(minirt->win, ON_DESTROY, 1L >> 2, &destroy_minirt, minirt);
	mlx_mouse_hook(minirt->win, &check_mouse_clicks, minirt);
	mlx_loop_hook(minirt->mlx, &check_state, minirt);
	mlx_loop(minirt->mlx);
}

bool	ini_objs(t_minirt *minirt)
{
	minirt->scene.lights = ft_calloc(LIGHTS_MAX, sizeof(t_light));
	if (!minirt->scene.lights)
		return (false);
	minirt->scene.shapes = ft_calloc(SHAPES_MAX, sizeof(t_object));
	if (!minirt->scene.shapes)
	{
		free(minirt->scene.lights);
		free(minirt->scene.shapes);
		return (false);
	}
	minirt->textures = NULL;
	return (true);
}


void	errors(int err_code, char* err_ms, void *ptr)
{
	t_minirt *minirt;
	
	minirt = (t_minirt *)ptr;
	if (minirt)
		destroy_minirt(minirt);
	ft_putstr_fd(err_ms, 2);
	exit(err_code);
}


int	main(int ac, char *av[])
{
	t_minirt	minirt;

	if (ac != 2)
		errors(CER_AGC, ER_AGC, NULL);
	//if (argc != 2)
	//{
	//	write(2, "Usage:\n\t./miniRT <filename>.rt\n", 32);
	//	return (2);
	//}
	minirt = (t_minirt){0};
	//ini_minirt(&minirt);
	ini_mlx(&minirt);
	if (!ini_objs(&minirt))
	{
		ft_putendl_fd("FATAL: Couldn't allocate for necessary objects.", 2);
		return (destroy_scene(&minirt), 2);
	}
	//parse_file(av[1], &minirt);
	if (!parse_file(av[1], &minirt))
		return (destroy_scene(&minirt), destroy_textures(&minirt), 2);
	//ini_core(&minirt)
	if (!ini_core(&minirt))
	{
		destroy_scene(&minirt);
		destroy_mlx(&minirt);
		ft_putendl_fd("FATAL: Couldn't allocate for threads.", 2);
		return (destroy_textures(&minirt), 2);
	}
	start_rt(&minirt);
	return (0);
}

