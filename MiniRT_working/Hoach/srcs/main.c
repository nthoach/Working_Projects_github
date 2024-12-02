/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:06:27 by honguyen          #+#    #+#             */
/*   Updated: 2024/12/02 12:11:16 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/miniRT.h"

int main(int agc, char **agv)
{
    t_minirt *minrt;

    if (agc != 2)
        return errors(E_AGC, NULL);
    check_rt(agv[1]);    
    //ft_memset(minirt, 0, sizeof(t_minirt));
    minirt = parse_rt(agv[1]);    
	minirt->mlx = mlx_init();
	if (!minirt->mlx)
		error(E_MLX, minirt);
    ini_all(minirt);
    raytrace(minirt);
	mlx_key_hook(minirt->mlx_win, user_move, minirt);
	mlx_hook(minirt->mlx_win, 17, 0, close_window, minirt);
	mlx_loop(minirt->mlx);
    close_minirt(minirt);
    return (OK);
}