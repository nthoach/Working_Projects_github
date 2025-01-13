/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_operations_2_ps.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nth <nth@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 23:24:33 by nth          #+#    #+#             */
/*   Updated: 2024/11/02 07:16:36 by nth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lag.h"

void	scale_vec4s(t_vec4s *out, const t_vec4s in,
						float scalar)
{
	out->simd = _mm_mul_ps(in.simd, _mm_set1_ps(scalar));
}

t_vec4s	scale_vec4s_re(const t_vec4s in, float scalar)
{
	return ((t_vec4s)
		{
			.simd = _mm_mul_ps(in.simd, _mm_set1_ps(scalar))
		});
}

void	negate_vec4s_new(t_vec4s *out, const t_vec4s in)
{
	out->simd = _mm_sub_ps(_mm_set1_ps(0.0f), in.simd);
}

void	negate_vec4s(t_vec4s *target)
{
	target->simd = _mm_sub_ps(_mm_set1_ps(0.0f), target->simd);
}

t_vec4s	negate_vec4s_re(const t_vec4s in)
{
	return ((t_vec4s)
		{
			.simd = _mm_sub_ps(_mm_set1_ps(0.0f), in.simd)
		});
}
