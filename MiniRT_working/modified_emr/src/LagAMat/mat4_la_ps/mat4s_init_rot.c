/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4s_init_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nth <nth@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:08:59 by nth          #+#    #+#             */
/*   Updated: 2024/11/18 10:15:20 by nth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lag.h"

t_mat4s	rotatex_mat4s(float rad)
{
	t_mat4s	ret;

	ret.r1.simd = _mm_set_ps(0.f, 0.f, 0.f, 1.f);
	ret.r2.simd = _mm_set_ps(0.f, -sinf(rad), cosf(rad), 0.f);
	ret.r3.simd = _mm_set_ps(0.f, cosf(rad), sinf(rad), 0.f);
	ret.r4.simd = _mm_set_ps(1.f, 0.f, 0.f, 0.f);
	return (ret);
}

t_mat4s	rotatey_mat4s(float rad)
{
	t_mat4s	ret;

	ret.r1.simd = _mm_set_ps(0.f, sinf(rad), 0.f, cosf(rad));
	ret.r2.simd = _mm_set_ps(0.f, 0.f, 1.f, 0.f);
	ret.r3.simd = _mm_set_ps(0.f, cosf(rad), 0.f, -sinf(rad));
	ret.r4.simd = _mm_set_ps(1.f, 0.f, 0.f, 0.f);
	return (ret);
}

t_mat4s	rotatez_mat4s(float rad)
{
	t_mat4s	ret;

	ret.r1.simd = _mm_set_ps(0.f, 0.f, -sinf(rad), cosf(rad));
	ret.r2.simd = _mm_set_ps(0.f, 0.f, cosf(rad), sinf(rad));
	ret.r3.simd = _mm_set_ps(0.f, 1.f, 0.f, 0.f);
	ret.r4.simd = _mm_set_ps(1.f, 0.f, 0.f, 0.f);
	return (ret);
}