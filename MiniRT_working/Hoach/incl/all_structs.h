/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:27:56 by honguyen          #+#    #+#             */
/*   Updated: 2024/12/02 12:32:46 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     ALL_STRUCTS_H
# define    DALL_STRUCTS_H

typedef struct s_minirt
{
	t_camera	camera;
	t_light		ambient;
	t_vector	*lights;
	t_vector	*shapes;
	int			counters[3];
	t_graphics	disp;
	t_vec3		up;
	t_vec3		right;
	char		**map;
	double		hview;
	double		wview;
    
    void	*mlx;
	void	*mlx_win;
	void	*mlx_text;
}	t_minirt;

#endif