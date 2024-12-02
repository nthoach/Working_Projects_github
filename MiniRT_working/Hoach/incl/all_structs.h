/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:27:56 by honguyen          #+#    #+#             */
/*   Updated: 2024/12/02 15:11:57 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     ALL_STRUCTS_H
# define    ALL_STRUCTS_H

# include "define.h"

typedef struct s_vec3d
{
	double	x;
	double	y;
	double	z;
}	t_vec3d;

typedef struct s_vector
{
	uint32_t	size;
	int			(*cmp)(void *, void *);
	void		(*del)(void *);
	void		*(*cpy)(void *);
	void		(*print)(void *);
	void		**array;
}	t_vector;

typedef struct s_camera
{
	t_vec3d		center;
	t_vec3d		normal;
	double		fov;	
}	t_camera;


typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_ambient
{
	t_vec3d	center;
	t_color	color;	
	double	ratio;
}		t_ambient;

typedef struct s_graph
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*address;
	int		height;
	int		width;
	int		bpp;
	int		line_length;
	int		endian;
}	t_graph;

typedef struct s_minirt
{
	t_camera	camera;
	t_ambient	ambient;
	t_vector	*lights;
	t_vector	*shapes;
	t_graph		graph;
	t_vec3d		up;
	t_vec3d		right;
	int			counters[3];
	char		**map;
	double		hview;
	double		wview;
	
}	t_minirt;

#endif