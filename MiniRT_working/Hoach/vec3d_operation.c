/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:45:12 by honguyen          #+#    #+#             */
/*   Updated: 2024/12/06 16:01:16 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

t_vec3d add_vec3d(t_vec3d a, t_vec3d b)
{
    return ((t_vec3d) {a.x + b.x, a.y + b.y, a.z + b.z});
}

t_vec3d sub_vec3d(t_vec3d a, t_vec3d b)
{
    return ((t_vec3d) {a.x - b.x, a.y - b.y, a.z - b.z});
}

t_vec3d scale_vec3d(t_vec3d v, float k)
{
    return ((t_vec3d) {v.x * k, v.y * k, v.z * k});
}

float vdot_vec3d(t_vec3d a, t_vec3d b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

t_vec3d cross_vec3d(t_vec3d a, t_vec3d b)
{
    return (t_vec3d)
    {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

float length_vec3d(t_vec3d v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

t_vec3d normalize_vec3d(t_vec3d v)
{
    float len = length_vec3d(v);
    return scale_vec3d(v, 1.0f / len);
}