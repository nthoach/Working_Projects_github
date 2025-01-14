/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nth <nth@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:30:03 by nth          #+#    #+#             */
/*   Updated: 2024/11/18 13:30:07 by nth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	transpose_mat4s(const t_mat4s *m, t_mat4s *out)
{
    //if (m == NULL || out == NULL)
    // {
    //     ft_fprintf(stderr, "Error: NULL pointer passed to transpose_mat4s\n");
    //     return;
    // }
	 int    i;
	 int	j;

	 i = 0;
	 while (i < 4)
     {
         j = 0;
         while (j < 4)
         {
             out->a[i][j] = m->a[j][i];
             j++;
         }
         i++;
     }

    // Recreate out->r1.simd, out->r2.simd, out->r3.simd, and out->r4.simd from elements of out->a
    //out->r1.simd = _mm_set_ps(out->a[0][3], out->a[0][2], out->a[0][1], out->a[0][0]);
    //out->r2.simd = _mm_set_ps(out->a[1][3], out->a[1][2], out->a[1][1], out->a[1][0]);
    //out->r3.simd = _mm_set_ps(out->a[2][3], out->a[2][2], out->a[2][1], out->a[2][0]);
    //out->r4.simd = _mm_set_ps(out->a[3][3], out->a[3][2], out->a[3][1], out->a[3][0]);

	//const __m128	tmp0 = _mm_unpacklo_ps(m->r1.simd, m->r2.simd);
	//const __m128	tmp1 = _mm_unpacklo_ps(m->r3.simd, m->r4.simd);
	//const __m128	tmp2 = _mm_unpackhi_ps(m->r1.simd, m->r2.simd);
	//const __m128	tmp3 = _mm_unpackhi_ps(m->r3.simd, m->r4.simd);

	//out->r1.simd = _mm_movelh_ps(tmp0, tmp1);
	//out->r2.simd = _mm_movehl_ps(tmp1, tmp0);
	//out->r3.simd = _mm_movelh_ps(tmp2, tmp3);
	//out->r4.simd = _mm_movehl_ps(tmp3, tmp2);
}
