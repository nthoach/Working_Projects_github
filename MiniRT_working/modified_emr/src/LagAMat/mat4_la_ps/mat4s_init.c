/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4s_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nth <nth@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 07:03:08 by nth          #+#    #+#             */
/*   Updated: 2024/11/02 09:37:45 by nth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lag.h"

t_mat4s	inirows_mat4s_re(const t_vec4s r1, const t_vec4s r2,
						const t_vec4s r3, const t_vec4s r4)
{
	t_mat4s	ret;

	ret.r1 = r1;
	ret.r2 = r2;
	ret.r3 = r3;
	ret.r4 = r4;
	return (ret);
}

t_mat4s	ini_indentity_mat4s(void)
{
	t_mat4s	ret;

	ret.r1.simd = _mm_set_ps(0.f, 0.f, 0.f, 1.f);
	ret.r2.simd = _mm_set_ps(0.f, 0.f, 1.f, 0.f);
	ret.r3.simd = _mm_set_ps(0.f, 1.f, 0.f, 0.f);
	ret.r4.simd = _mm_set_ps(1.f, 0.f, 0.f, 0.f);
	return (ret);
}

t_mat4s	translation_mat4s(float tx, float ty, float tz)
{
	t_mat4s	ret;

	ret.r1.simd = _mm_set_ps(tx, 0.f, 0.f, 1.f);
	ret.r2.simd = _mm_set_ps(ty, 0.f, 1.f, 0.f);
	ret.r3.simd = _mm_set_ps(tz, 1.f, 0.f, 0.f);
	ret.r4.simd = _mm_set_ps(1.f, 0.f, 0.f, 0.f);
	return (ret);
}

t_mat4s	scaling_mat4s(float sx, float sy, float sz)
{
	t_mat4s	ret;

	ret.r1.simd = _mm_set_ps(0.f, 0.f, 0.f, sx);
	ret.r2.simd = _mm_set_ps(0.f, 0.f, sy, 0.f);
	ret.r3.simd = _mm_set_ps(0.f, sz, 0.f, 0.f);
	ret.r4.simd = _mm_set_ps(1.f, 0.f, 0.f, 0.f);
	return (ret);
}
