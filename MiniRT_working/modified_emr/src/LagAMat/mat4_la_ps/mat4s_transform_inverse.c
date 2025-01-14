/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4s_transform_inverse.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nth <nth@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:34:23 by nth          #+#    #+#             */
/*   Updated: 2024/11/18 10:19:38 by nth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lag.h"

/*Process documented in https://docs.google.com/document/d/1ok8dzMk7EZiZaVRB61zGDlxRSDoelX3z6ixaCRlg0yM/edit?usp=sharing*/

/// @brief Calculates the inverse of a decomposed matrix
/// (rotation, scale, translation)
/// @param rot The rotational component of the matrix
/// @param s The scale factor of the matrix
/// @param t The translation component of the matrix
/// @return The inverse of the decomposed matrix
/// @warning The scale should NOT contain any zero components as that will
/// cause divide-by-zero errors! (And it doesn't really make sense anyway)

//t_mat4s	get_inv_tranform_mat4s(const t_mat4s rot, const __m128 s,
//			const __m128 t)
			
//{
//	t_mat4s			ret0;
//	__m128			tmp[4];
//	const __m128	rcps = _mm_div_ps(_mm_set1_ps(1.f), s);
//	const __m128	tinv = _mm_sub_ps(_mm_set1_ps(0.f), t);

//	tmp[0] = _mm_unpacklo_ps(rot.simd[0], rot.simd[1]);
//	tmp[1] = _mm_unpackhi_ps(rot.simd[0], rot.simd[1]);
//	tmp[2] = _mm_unpacklo_ps(rot.simd[2], rot.simd[3]);
//	tmp[3] = _mm_unpackhi_ps(rot.simd[2], rot.simd[3]);
//	ret0.simd[0] = _mm_movelh_ps(tmp[0], tmp[2]);
//	ret0.simd[1] = _mm_movehl_ps(tmp[2], tmp[0]);
//	ret0.simd[2] = _mm_movelh_ps(tmp[1], tmp[3]);
//	ret0.simd[3] = _mm_set_ps(1, 0, 0, 0);
//	ret0.simd[0] = _mm_mul_ps(ret0.simd[0],
//			_mm_shuffle_ps(rcps, rcps, _MM_SHUFFLE(0, 0, 0, 0)));
//	ret0.simd[1] = _mm_mul_ps(ret0.simd[1],
//			_mm_shuffle_ps(rcps, rcps, _MM_SHUFFLE(1, 1, 1, 1)));
//	ret0.simd[2] = _mm_mul_ps(ret0.simd[2],
//			_mm_shuffle_ps(rcps, rcps, _MM_SHUFFLE(2, 2, 2, 2)));
//	ret0.r1.w = _mm_cvtss_f32(_mm_dp_ps(ret0.simd[0], tinv, 0xF1));
//	ret0.r2.w = _mm_cvtss_f32(_mm_dp_ps(ret0.simd[1], tinv, 0xF1));
//	ret0.r3.w = _mm_cvtss_f32(_mm_dp_ps(ret0.simd[2], tinv, 0xF1));
//	return (ret0);
//}

t_mat4s get_inv_tranform_mat4s(const t_mat4s rot, const t_vec4s s, const t_vec4s t)
{
    t_mat4s ret;
    t_vec4s rcps, tinv;

    // Check for zero components in the scaling vector
    //if (s.a[0] == 0.0f || s.a[1] == 0.0f || s.a[2] == 0.0f)
    //{
    //    fprintf(stderr, "Error: Zero component in scaling vector\n");
    //    exit(EXIT_FAILURE);
    //}

    // Calculate reciprocal of scaling factors
    rcps.a[0] = 1.f / s.a[0];
    rcps.a[1] = 1.f / s.a[1];
    rcps.a[2] = 1.f / s.a[2];
    rcps.a[3] = 1.f; // No scaling for the w component

    // Negate the translation vector
    tinv.a[0] = -t.a[0];
    tinv.a[1] = -t.a[1];
    tinv.a[2] = -t.a[2];
    tinv.a[3] = -t.a[3];

    // Transpose the rotation matrix
    ret.a[0][0] = rot.a[0][0];
    ret.a[0][1] = rot.a[1][0];
    ret.a[0][2] = rot.a[2][0];
    ret.a[0][3] = 0.f;

    ret.a[1][0] = rot.a[0][1];
    ret.a[1][1] = rot.a[1][1];
    ret.a[1][2] = rot.a[2][1];
    ret.a[1][3] = 0.f;

    ret.a[2][0] = rot.a[0][2];
    ret.a[2][1] = rot.a[1][2];
    ret.a[2][2] = rot.a[2][2];
    ret.a[2][3] = 0.f;

    ret.a[3][0] = 0.f;
    ret.a[3][1] = 0.f;
    ret.a[3][2] = 0.f;
    ret.a[3][3] = 1.f;

    // Scale the transposed rotation matrix by the reciprocal scaling factors
    for (int i = 0; i < 3; ++i)
    {
        ret.a[i][0] *= rcps.a[0];
        ret.a[i][1] *= rcps.a[1];
        ret.a[i][2] *= rcps.a[2];
    }

    // Calculate the translation part
    ret.a[0][3] = ret.a[0][0] * tinv.a[0] + ret.a[0][1] * tinv.a[1] + ret.a[0][2] * tinv.a[2];
    ret.a[1][3] = ret.a[1][0] * tinv.a[0] + ret.a[1][1] * tinv.a[1] + ret.a[1][2] * tinv.a[2];
    ret.a[2][3] = ret.a[2][0] * tinv.a[0] + ret.a[2][1] * tinv.a[1] + ret.a[2][2] * tinv.a[2];

    return ret;
}