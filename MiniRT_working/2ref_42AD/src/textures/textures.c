/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:09:35 by ebinjama          #+#    #+#             */
/*   Updated: 2024/11/18 17:05:50 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "macros.h"

t_color	rt_sample_texture(const t_canvas *tex, const t_vec2s *uv)
{
	int			tex_x;
	int			tex_y;
	char		*src;
	uint32_t	color_value;
	t_color		retval;

	tex_x = floorf((int)(uv->x * tex->tex_width) % tex->tex_width);
	tex_y = floorf((int)(uv->y * tex->tex_height) % tex->tex_height);
	src = tex->addr + (tex_y * tex->line_length + tex_x * tex->bpp_8);
	color_value = *(uint32_t *)src;
	retval.r = (color_value >> 16) & 0xFF;
	retval.g = (color_value >> 8) & 0xFF;
	retval.b = color_value & 0xFF;
	lag_vec4s_scaleby(&retval.v, retval.v, 1.f / 255.999f);
	retval.a = (_RT_OS_MACOS_ == 0);
	return (retval);
}

static inline t_vec4s	_from_sample_to_tangent_normal(const t_color *sample)
{
	t_vec4s	tangent_normal;

	lag_vec4sp_init(&tangent_normal, sample->r, sample->g, sample->b);
	lag_vec4s_scaleby(&tangent_normal, tangent_normal, 2.f);
	tangent_normal.simd = _mm_sub_ps(tangent_normal.simd, _mm_set1_ps(1.f));
	tangent_normal.w = 0.f;
	return (tangent_normal);
}

static inline t_mat4s	_construct_tbn_matrix(const t_vec4s *local_normal,
							const t_vec4s *tangent, const t_vec4s *bitangent)
{
	t_mat4s	retval;

	retval.r1 = lag_vec4sv_ret(tangent->x, bitangent->x, local_normal->x);
	retval.r2 = lag_vec4sv_ret(tangent->y, bitangent->y, local_normal->y);
	retval.r3 = lag_vec4sv_ret(tangent->z, bitangent->z, local_normal->z);
	retval.r4 = lag_vec4sp_ret(0, 0, 0);
	return (retval);
}

t_vec4s	rt_apply_normal_map(const t_obj *obj, const t_vec2s *uv,
			const t_vec4s *local_normal, const t_vec4s *tangent)
{
	const t_color	sample = rt_sample_texture(obj->material.tex, uv);
	t_vec4s			tangent_normal;
	t_vec4s			bitangent;
	t_mat4s			tbn_matrix;
	t_vec4s			perturbed_normal;

	lag_vec4s_cross(&bitangent, *local_normal, *tangent);
	tangent_normal = _from_sample_to_tangent_normal(&sample);
	lag_vec4s_negate(&bitangent);
	lag_vec4s_normalize(&bitangent);
	tbn_matrix = _construct_tbn_matrix(local_normal, tangent, &bitangent);
	lag_mat4s_cross_vec4s(&tbn_matrix, &tangent_normal, &perturbed_normal);
	lag_vec4s_normalize(&perturbed_normal);
	return (perturbed_normal);
}
