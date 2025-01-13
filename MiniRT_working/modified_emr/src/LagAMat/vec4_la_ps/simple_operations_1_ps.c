/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_operations_1_ps.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nth <nth@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:57:10 by nth          #+#    #+#             */
/*   Updated: 2024/11/18 10:46:05 by nth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lag.h"

void	add_vec4s(t_vec4s *out, const t_vec4s *in1,
						const t_vec4s *in2)
{
	out->simd = _mm_add_ps(in1->simd, in2->simd);
}

t_vec4s	add_vec4s_re(const t_vec4s in1, const t_vec4s in2)
{
	return ((t_vec4s)
		{
			.simd = _mm_add_ps(in1.simd, in2.simd)
		});
}

void	sub_vec4s(t_vec4s *out, const t_vec4s *in1,
						const t_vec4s *in2)
{
	out->simd = _mm_sub_ps(in1->simd, in2->simd);
}

t_vec4s	sub_vec4s_re(const t_vec4s in1, const t_vec4s in2)
{
	return ((t_vec4s)
		{
			.simd = _mm_sub_ps(in1.simd, in2.simd)
		});
}
