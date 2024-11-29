/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 05:05:39 by ebinjama          #+#    #+#             */
/*   Updated: 2024/11/19 16:45:03 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec4s	reflect(t_vec4s *in, t_vec4s *normal)
{
	t_vec4s	op;
	t_vec4s	reflect;
	float	dot;

	lag_vec4s_dot(&dot, in, normal);
	op = lag_vec4s_scaleby_ret(*normal, 2.f * dot);
	lag_vec4s_sub(&reflect, in, &op);
	lag_vec4s_normalize(&reflect);
	return (reflect);
}

void	ray_create(t_ray *ray, t_vec4s *origin, t_vec4s *direction)
{
	ray->origin = *origin;
	ray->dir = *direction;
}

void	ray_position(t_vec4s *result, const t_ray *ray, float t)
{
	const t_vec4s	scaled_dir = lag_vec4s_scaleby_ret(ray->dir, t);
	const t_vec4s	sum = lag_vec4s_add_ret(ray->origin, scaled_dir);

	*result = lag_vec4s_ret(sum.x, sum.y, sum.z, 1.f);
}

void	ray_transform(t_ray *ray, const t_mat4s *matrix)
{
	const t_vec4s	origin = ray->origin;
	const t_vec4s	dir = ray->dir;

	lag_mat4s_cross_vec4s(matrix, &origin, &ray->origin);
	lag_mat4s_cross_vec4s(matrix, &dir, &ray->dir);
}
