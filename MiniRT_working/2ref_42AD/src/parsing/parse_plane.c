/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:08:31 by melshafi          #+#    #+#             */
/*   Updated: 2024/11/20 13:48:56 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "macros.h"
#include "libft.h"
#include "colors.h"

static void	material_init(t_material *material, const t_split *fields,
	t_program *context, int curr_line)
{
	__m128	color_vec;

	color_vec = material->color.v.simd;
	material->xordc = \
		(t_color){.v.simd = _mm_xor_ps(color_vec, color_vec)};
	material->ambient = 0.1;
	material->diffuse = 0.9;
	material->specular = 0.9;
	material->sheen = 200;
	material->reflective = 0.0;
	material->transparency = 0.0;
	material->refractive_index = 1.0;
	if (fields->wordcount == 6 && parse_material(material, &fields->array[4],
			context, curr_line))
		return ;
}

bool	parse_plane_checker(t_material *obj_mat, t_program *context,
		char *is_checker)
{
	if (ft_strncmp(is_checker, "yes", ft_strlen(is_checker))
		&& ft_strncmp(is_checker, "no", ft_strlen(is_checker)))
		return (context->runtime_error = 4, false);
	if (!ft_strncmp(is_checker, "yes", ft_strlen(is_checker)))
		obj_mat->checkered = true;
	else
		obj_mat->checkered = false;
	context->runtime_error = 0;
	context->flt_operations = 1;
	return (true);
}

bool	parse_plane(t_program *context, const t_split *fields, int curr_line)
{
	t_obj	*pl;

	if (context->world.num_shapes == _RT_MAX_SHAPES_)
		return (str_arr_destroy(fields->array),
			parse_warn_msg(ERR_MAX_SHAPES, NULL, curr_line, true), true);
	pl = &context->world.shapes[context->world.num_shapes++];
	if (fields->wordcount < 4 || fields->wordcount > 6)
		return (parse_err_msg(ERR_OBJ_FORMAT, ERR_E_T_PL,
				curr_line), str_arr_destroy(fields->array), false);
	pl->type = PLANE;
	if (!parse_vec4p(&pl->trans, fields->array[1], context, curr_line))
		return (str_arr_destroy(fields->array), false);
	if (!parse_vec4v(&pl->orientation, fields->array[2], context, curr_line))
		return (str_arr_destroy(fields->array), false);
	is_normalised(&pl->orientation, curr_line);
	if (!parse_color(&pl->material.color, fields->array[3], curr_line))
		return (str_arr_destroy(fields->array), false);
	material_init(&pl->material, fields, context, curr_line);
	pl->scale = lag_vec4s_ret(1, 1, 1, 1);
	pl->rot = rt_extract_rot_vertical(pl->orientation);
	pl->inv_transform = lag_mat4s_get_transform_inverse(pl->rot,
			pl->scale.simd, pl->trans.simd);
	lag_mat4s_transpose(&pl->inv_transform, &pl->transposed_inverse);
	return (pl->center.w = 1.f, str_arr_destroy(fields->array), true);
}
