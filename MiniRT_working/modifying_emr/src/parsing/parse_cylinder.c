///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   parse_cylinder.c                                   :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:38:59 by nth          #+#    #+#             */
/*   Updated: 2025/01/14 18:20:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "macros.h"
#include "libft.h"
#include "colors.h"
#include <assert.h>

bool	parse_cylinder(t_minirt *minirt, char *data, size_t *i, size_t idx)
{
	t_object	*cylinder;
	float		height;

	(*i) += 2;
	cylinder = minirt->scene.shapes + idx;
	cylinder->type = PLANE;
	// test
	printf("shape[%ld], type = %d\n", idx, cylinder->type);// test

	cylinder->trans = parse_point(data, i);
	//test
	printf("cylinder position = %f, %f, %f\n", (minirt->scene.shapes + idx)->trans.x, \
		(minirt->scene.shapes + idx)->trans.y, (minirt->scene.shapes + idx)->trans.z);
	
	cylinder->orientation = parse_vector(data, i);
	// test
	printf("cylinder orientation = %f, %f, %f\n", (minirt->scene.shapes + idx)->orientation.x, \
		(minirt->scene.shapes + idx)->orientation.y, (minirt->scene.shapes + idx)->orientation.z);
	
	is_normalised(&cylinder->orientation, *i);

	cylinder->radius = parse_float(data, i);
	//test	
	printf("cylinder radius = %f\n", (minirt->scene.shapes + idx)->radius);

	height = parse_float(data, i);
	cylinder->specs.min = -height / 2.0f;
	cylinder->specs.max = height / 2.0f;
	cylinder->specs.closed = true;
	// test
	printf("cylinder height = %f\n", 2 * cylinder->specs.max );

	cylinder->material.color = parse_color(data, i);
	//test	
	printf("cylinder color = %f, %f, %f\n", (minirt->scene.shapes + idx)->material.color.r, \
		(minirt->scene.shapes + idx)->material.color.g, (minirt->scene.shapes + idx)->material.color.b);
	//test
	printf("Bonus = %c\n", data[*i]);

	set_material(&cylinder->material, data, i, minirt);
	while (data[*i] == '\t' || data[*i] == ' ' || data[*i] == ',' || data[*i] == '\n')
		(*i)++;
	// initialize the cylinder
	cylinder->scale = vec4s_re(1.f, 1.f, 1.f, 1.f);
	cylinder->rot = rt_extract_rot_vertical(cylinder->orientation);
	cylinder->inv_transform = get_inv_tranform_mat4s(cylinder->rot,
			cylinder->scale, cylinder->trans);
	transpose_mat4s(&cylinder->inv_transform, &cylinder->transposed_inverse);
	return (cylinder->center.w = 1.f, true);
}
