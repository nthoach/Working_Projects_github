/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:34:49 by melshafi          #+#    #+#             */
/*   Updated: 2025/01/14 17:49:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "macros.h"
#include "libft.h"
#include "colors.h"
#include <assert.h>

static void	material_init(t_material *material, const t_split *fields,
	t_minirt *minirt, int curr_line)
{
	__m128	color_vec;

	color_vec = material->color.v.simd;
	material->xordc = \
		(t_color){.v.simd = _mm_xor_ps(color_vec, \
			_mm_set_ps(1.f, 1.f, 1.f, (OS_MACOS == 0)))};
	material->ambient = 0.1;
	material->diffuse = 0.9;
	material->specular = 0.9;
	material->sheen = 200;
	material->reflective = 0.0;
	material->transparency = 0.0;
	material->refractive_index = 1.0;
	if (fields->wordcount == 8 && parse_material(material, &fields->array[6],
			minirt, curr_line))
		return ;
}

bool	get_cone_extras(t_object *co, t_minirt *minirt,
		const t_split *fields, int curr_line)
{
	float	height;

	co->radius = ft_atof(fields->array[3], minirt) / 2.0f;
	if (minirt->error_code == 2)
		return (parse_err_msg(ERR_OBJ_VALUE, ERR_EXPECT_FLOAT, curr_line),
			str_arr_destroy(fields->array), false);
	height = ft_atof(fields->array[4], minirt);
	if (minirt->error_code == 2)
		return (parse_err_msg(ERR_OBJ_VALUE, ERR_EXPECT_FLOAT, curr_line),
			str_arr_destroy(fields->array), false);
	co->specs.min = -height / 2.0f;
	co->specs.max = height / 2.0f;
	co->specs.closed = false;
	if (!parse_color(&co->material.color, fields->array[5], curr_line))
		return (str_arr_destroy(fields->array), false);
	material_init(&co->material, fields, minirt, curr_line);
	co->scale = vec4s_re(co->radius, height, co->radius, 1);
	co->rot = rt_extract_rot_vertical(co->orientation);
	co->inv_transform = get_inv_tranform_mat4s(co->rot,
			co->scale, co->trans);
	//co->inv_transform = get_inv_tranform_mat4s(co->rot,
	//		co->scale.simd, co->trans.simd);
	return (true);
}

bool	parse_cone(t_minirt *minirt, const t_split *fields, int curr_line)
{
	t_object	*co;

	if (minirt->scene.num_shapes == SHAPES_MAX)
		return (str_arr_destroy(fields->array),
			parse_warn_msg(ERR_MAX_SHAPES, NULL, curr_line, true), true);
	co = &minirt->scene.shapes[minirt->scene.num_shapes++];
	if (fields->wordcount < 6 || fields->wordcount > 8)
		return (parse_err_msg(ERR_OBJ_FORMAT, ERR_EXPECT_TYPE_CO ERR_ECO,
				curr_line), str_arr_destroy(fields->array), false);
	co->type = CONE;
	if (!parse_vec4p(&co->trans, fields->array[1], minirt, curr_line))
		return (str_arr_destroy(fields->array), false);
	if (!parse_vec4v(&co->orientation, fields->array[2], minirt, curr_line))
		return (str_arr_destroy(fields->array), false);
	is_normalised(&co->orientation, curr_line);
	if (!get_cone_extras(co, minirt, fields, curr_line))
		return (false);
	return (str_arr_destroy(fields->array), true);
}
