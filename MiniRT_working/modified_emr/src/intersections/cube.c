/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nth <nth@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:57:02 by nth          #+#    #+#             */
/*   Updated: 2024/11/20 13:19:13 by nth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "macros.h"

static void	check_axis(float origin, float direction, float side_length, t_vec4s *t)
{
	float	half_side;
	float	tmin_numerator;
	float	tmax_numerator;
	float	temp;

	half_side = side_length / 2.0;
	tmin_numerator = (-half_side - origin);
	tmax_numerator = (half_side - origin);
	if (fabsf(direction) >= EPSILON)
	{
		t->x = tmin_numerator / direction;
		t->y = tmax_numerator / direction;
	}
	else
	{
		t->x = tmin_numerator * INFINITY;
		t->y = tmax_numerator * INFINITY;
	}
	if (t->x > t->y)
	{
		temp = t->x;
		t->x = t->y;
		t->y = temp;
	}
}

static inline void	_check_axes(t_ray *transformed_ray, t_object *cube,
						t_mat4s *xyz_t)
{
	check_axis(transformed_ray->origin.x, transformed_ray->direction.x,
		cube->specs.side_length, &xyz_t->r1);
	check_axis(transformed_ray->origin.y, transformed_ray->direction.y,
		cube->specs.side_length, &xyz_t->r2);
	check_axis(transformed_ray->origin.z, transformed_ray->direction.z,
		cube->specs.side_length, &xyz_t->r3);
}

bool	intersect_cube(t_ray *ray, t_object *cube, t_itx_grp *xs)
{
	t_ray	transformed_ray;
	t_mat4s	xyz_t;
	t_vec4s	t;

	transformed_ray = *ray;
	ray_transform(&transformed_ray, &(cube->inv_transform));
	_check_axes(&transformed_ray, cube, &xyz_t);
	t.x = fmax(fmax(xyz_t.r1.x, xyz_t.r2.x), xyz_t.r3.x);
	t.y = fmin(fmin(xyz_t.r1.y, xyz_t.r2.y), xyz_t.r3.y);
	if (t.x > t.y)
		return (false);
	xs->arr[xs->count].object = cube;
	xs->arr[xs->count++].t = t.x;
	xs->arr[xs->count].object = cube;
	xs->arr[xs->count++].t = t.y;
	return (true);
}

t_vec4s	cube_normal_at(t_object *cube, t_vec4s *world_point)
{
	t_vec4s		object_n_p[2];
	t_vec4s		world_normal;
	t_vec4s		abslocal_n;
	float		maxc;

	cross_mat4s_vec4s(&cube->inv_transform, world_point, &object_n_p[1]);
	abslocal_n.x = fmaxf(fabsf(object_n_p[1].x), EPSILON);
	abslocal_n.y = fmaxf(fabsf(object_n_p[1].y), EPSILON);
	abslocal_n.z = fmaxf(fabsf(object_n_p[1].z), EPSILON);
	maxc = fmax(fmax(abslocal_n.x, abslocal_n.y), abslocal_n.z);
	if (fabsf(maxc - fabsf(object_n_p[1].x)) < EPSILON)
		vec4sv_ini(&world_normal, object_n_p[1].x, 0, 0);
	else if (fabsf(maxc - fabsf(object_n_p[1].y)) < EPSILON)
		vec4sv_ini(&world_normal, 0, object_n_p[1].y, 0);
	else
		vec4sv_ini(&world_normal, 0, 0, object_n_p[1].z);
	cross_mat4s_vec4s(&cube->transposed_inverse, &world_normal, \
		&world_normal);
	normalize_vec4s(&world_normal);
	world_normal.w = 0.f;
	return (world_normal);
}
