/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:38:04 by nth          #+#    #+#             */
/*   Updated: 2025/01/14 18:20:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "macros.h"
#include "libft.h"
#include "colors.h"

bool	parse_cube(t_minirt *minirt, char *data, size_t *i, size_t idx)
{

	t_object	*cube;

	(*i) += 2;
	cube = minirt->scene.shapes + idx;
	cube->type = CUBIC;
	// test
	printf("shape[%ld], type = %d\n", idx, cube->type);// test

	cube->trans = parse_point(data, i);
	//test
	printf("cube position = %f, %f, %f\n", (minirt->scene.shapes + idx)->trans.x, \
		(minirt->scene.shapes + idx)->trans.y, (minirt->scene.shapes + idx)->trans.z);
	
	cube->orientation = parse_vector(data, i);
	// test
	printf("cube orientation = %f, %f, %f\n", (minirt->scene.shapes + idx)->orientation.x, \
		(minirt->scene.shapes + idx)->orientation.y, (minirt->scene.shapes + idx)->orientation.z);
	
	is_normalised(&cube->orientation, *i);

	cube->specs.side_length = parse_float(data, i);
	// test
	printf("cube side_length = %f\n", (minirt->scene.shapes + idx)->specs.side_length);

	cube->material.color = parse_color(data, i);
	//test	
	printf("cube color = %f, %f, %f\n", (minirt->scene.shapes + idx)->material.color.r, \
		(minirt->scene.shapes + idx)->material.color.g, (minirt->scene.shapes + idx)->material.color.b);
	//test
	printf("Bonus = %c\n", data[*i]);

	set_material(&cube->material, data, i, minirt);
	while (data[*i] == '\t' || data[*i] == ' ' || data[*i] == ',' || data[*i] == '\n')
		(*i)++;
	// initialize the cube
	cube->scale = vec4s_re(1.f, 1.f, 1.f, 1.f);
	cube->rot = rt_extract_rot_vertical(cube->orientation);
	cube->inv_transform = get_inv_tranform_mat4s(cube->rot,
			cube->scale, cube->trans);
	transpose_mat4s(&cube->inv_transform, &cube->transposed_inverse);
	return (true);
}
