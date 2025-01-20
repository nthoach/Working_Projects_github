/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:34:49 by nth          #+#    #+#             */
/*   Updated: 2025/01/14 18:20:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "macros.h"
#include "libft.h"
#include "colors.h"
#include <assert.h>

bool	parse_cone(t_minirt *minirt, char *data, size_t *i, size_t idx)
{
	t_object	*cone;
	float		height;

	(*i) += 2;
	cone = minirt->scene.shapes + idx;
	cone->type = CONE;

	// test
	printf("shape[%ld], type = %d\n", idx, cone->type);// test

	cone->trans = parse_point(data, i);
	//test
	printf("cone position = %f, %f, %f\n", (minirt->scene.shapes + idx)->trans.x, \
		(minirt->scene.shapes + idx)->trans.y, (minirt->scene.shapes + idx)->trans.z);
	
	cone->orientation = parse_vector(data, i);
	// test
	printf("cone orientation = %f, %f, %f\n", (minirt->scene.shapes + idx)->orientation.x, \
		(minirt->scene.shapes + idx)->orientation.y, (minirt->scene.shapes + idx)->orientation.z);
	
	is_normalised(&cone->orientation, *i);

	cone->radius = parse_float(data, i);
	//test
	printf("cone radius = %f\n", (minirt->scene.shapes + idx)->radius);

	height = parse_float(data, i);
	cone->specs.min = -height / 2.0f;
	cone->specs.max = height / 2.0f;
	cone->specs.closed = false;
	// test
	printf("cone height = %f\n", 2 * cone->specs.max );

	cone->material.color = parse_color(data, i);
	//test	
	printf("cone color = %f, %f, %f\n", (minirt->scene.shapes + idx)->material.color.r, \
		(minirt->scene.shapes + idx)->material.color.g, (minirt->scene.shapes + idx)->material.color.b);
	
	//test
	printf("Bonus = %c\n", data[*i]);

	set_material(&cone->material, data, i, minirt);
	while (data[*i] == '\t' || data[*i] == ' ' || data[*i] == ',' || data[*i] == '\n')
		(*i)++;
	// initialize the cone
	cone->scale = vec4s_re(cone->radius, height, cone->radius, 1);
	cone->rot = rt_extract_rot_vertical(cone->orientation);
	cone->inv_transform = get_inv_tranform_mat4s(cone->rot,
			cone->scale, cone->trans);
	return (true);
}
