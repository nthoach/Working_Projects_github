/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:35:24 by honguyen          #+#    #+#             */
/*   Updated: 2024/12/06 16:07:59 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_vec3d
{
    float x;
    float y;
    float z;
}               t_vec3d;

typedef struct s_ray
{
    t_vec3d origin;
    t_vec3d direction;
}               t_ray;

typedef struct s_plane
{
    t_vec3d point;
    t_vec3d normal;
}               t_plane;

typedef struct s_light
{
    t_vec3d position;
    float   brightness;
    t_vec3d color;
}               t_light;

typedef struct s_sphere
{
    t_vec3d center;
    float   radius;
    t_vec3d color;
}               t_sphere;

typedef struct s_camera
{
    t_vec3d orgin;
    t_vec3d direction;
    float   fov;
}               t_camera;

typedef struct s_scene
{
    t_camera    camera;
    t_light     light;
    t_plane     plane;
    t_sphere    sphere;
}               t_scene;



t_vec3d add_vec3d(t_vec3d a, t_vec3d b);

t_vec3d sub_vec3d(t_vec3d a, t_vec3d b);

t_vec3d scale_vec3d(t_vec3d v, float k);

float vdot_vec3d(t_vec3d a, t_vec3d b);

t_vec3d cross_vec3d(t_vec3d a, t_vec3d b);

float length_vec3d(t_vec3d v);

t_vec3d normalize_vec3d(t_vec3d v);
