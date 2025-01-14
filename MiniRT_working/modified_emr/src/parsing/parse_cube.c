/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:38:04 by melshafi          #+#    #+#             */
/*   Updated: 2025/01/14 18:09:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "macros.h"
#include "libft.h"
#include "colors.h"

static void	material_init(t_material *material, const t_split *fields,
	t_minirt *minirt, int curr_line)
{
	//__m128	color_vec;

	//color_vec = material->color.v.simd;
	//material->xordc = (t_color){.v.simd = _mm_xor_ps(color_vec, color_vec)};
	material->xordc = (t_color){.v = vec4s_re(0.f, 0.f, 0.f, 0.f)};
	material->ambient = 0.1;
	material->diffuse = 0.9;
	material->specular = 0.9;
	material->sheen = 200;
	material->reflective = 0.0;
	material->transparency = 0.0;
	material->refractive_index = 1.0;
	if (fields->wordcount == 7 && parse_material(material, &fields->array[5],
			minirt, curr_line))
		return ;
}

bool	parse_cube(t_minirt *minirt, const t_split *fields, int curr_line)
{
	t_object	*cu;

	if (minirt->scene.num_shapes == SHAPES_MAX)
		return (str_arr_destroy(fields->array),
			parse_warn_msg(ERR_MAX_SHAPES, NULL, curr_line, true), true);
	cu = &minirt->scene.shapes[minirt->scene.num_shapes++];
	if (fields->wordcount < 5 || fields->wordcount > 7)
		return (parse_err_msg(ERR_OBJ_FORMAT, ERR_EXPECT_TYPE_CU ERR_ECU,
				curr_line), str_arr_destroy(fields->array), false);
	cu->type = CUBIC;
	if (!parse_vec4p(&cu->trans, fields->array[1], minirt, curr_line))
		return (str_arr_destroy(fields->array), false);
	if (!parse_vec4v(&cu->orientation, fields->array[2], minirt, curr_line))
		return (str_arr_destroy(fields->array), false);
	is_normalised(&cu->orientation, curr_line);
	cu->specs.side_length = ft_atof(fields->array[3], minirt);
	if (!parse_color(&cu->material.color, fields->array[4], curr_line))
		return (str_arr_destroy(fields->array), false);
	material_init(&cu->material, fields, minirt, curr_line);
	cu->scale = vec4s_re(1, 1, 1, 1);
	cu->rot = rt_extract_rot_vertical(cu->orientation);
	//cu->inv_transform = get_inv_tranform_mat4s(cu->rot,
	//		cu->scale.simd, cu->trans.simd);
	cu->inv_transform = get_inv_tranform_mat4s(cu->rot,
			cu->scale, cu->trans);
	return (str_arr_destroy(fields->array), true);
}
