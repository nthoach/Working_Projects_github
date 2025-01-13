/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_algebra_2_ps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nth <nth@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 03:28:04 by nth          #+#    #+#             */
/*   Updated: 2024/11/02 07:15:24 by nth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lag.h"

void	cross_vec4s(t_vec4s *out, const t_vec4s in1,
						const t_vec4s in2)
{
	const __m128	a_yzx = \
					_mm_shuffle_ps(in1.simd, in1.simd, _MM_SHUFFLE(3, 0, 2, 1));
	const __m128	b_yzx = \
					_mm_shuffle_ps(in2.simd, in2.simd, _MM_SHUFFLE(3, 0, 2, 1));
	const __m128	a_zxy = \
					_mm_shuffle_ps(in1.simd, in1.simd, _MM_SHUFFLE(3, 1, 0, 2));
	const __m128	b_zxy = \
					_mm_shuffle_ps(in2.simd, in2.simd, _MM_SHUFFLE(3, 1, 0, 2));

	out->simd = _mm_sub_ps(\
		_mm_mul_ps(a_yzx, b_zxy), \
		_mm_mul_ps(a_zxy, b_yzx) \
	);
}

t_vec4s	cross_vec4s_re(const t_vec4s in1,
						const t_vec4s in2)
{
	const __m128	a_yzx = \
					_mm_shuffle_ps(in1.simd, in1.simd, _MM_SHUFFLE(3, 0, 2, 1));
	const __m128	b_yzx = \
					_mm_shuffle_ps(in2.simd, in2.simd, _MM_SHUFFLE(3, 0, 2, 1));
	const __m128	a_zxy = \
					_mm_shuffle_ps(in1.simd, in1.simd, _MM_SHUFFLE(3, 1, 0, 2));
	const __m128	b_zxy = \
					_mm_shuffle_ps(in2.simd, in2.simd, _MM_SHUFFLE(3, 1, 0, 2));

	return ((t_vec4s)
		{
			.simd = _mm_sub_ps(\
				_mm_mul_ps(a_yzx, b_zxy), \
				_mm_mul_ps(a_zxy, b_yzx) \
			)
		});
}
