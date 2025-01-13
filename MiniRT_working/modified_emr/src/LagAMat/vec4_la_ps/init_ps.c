/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nth <nth@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:13:08 by nth          #+#    #+#             */
/*   Updated: 2024/11/02 07:14:22 by nth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lag.h"

t_vec4s	vec4s_re(float x, float y, float z, float w)
{
	return ((t_vec4s)
		{
			.simd = _mm_set_ps(w, z, y, x)
		});
}

void	vec4sp_ini(t_vec4s *target, float x, float y,
						float z)
{
	target->simd = _mm_set_ps(1.0, z, y, x);
}

t_vec4s	vec4sp_re(float x, float y, float z)
{
	return ((t_vec4s)
		{
			.simd = _mm_set_ps(1.0, z, y, x)
		});
}

void	vec_4sv_ini(t_vec4s *target, float x, float y,
						float z)
{
	target->simd = _mm_set_ps(0.0, z, y, x);
}

t_vec4s	vec4sv_re(float x, float y, float z)
{
	return ((t_vec4s)
		{
			.simd = _mm_set_ps(0.0, z, y, x)
		});
}
