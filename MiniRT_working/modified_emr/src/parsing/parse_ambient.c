/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nth <nth@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:26:43 by nth          #+#    #+#             */
/*   Updated: 2024/10/09 04:07:00 by nth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "macros.h"
#include "libft.h"
#include "colors.h"


float	parse_float(char *data, size_t *i)
{
	float	value;

	while (data[*i] == '\t' || data[*i] == ' ' || data[*i] == ',')
		(*i)++;
	value = ft_atof(&data[*i]);
	while (data[*i] && data[*i] != '\t' && data[*i] != ' ' \
			&& data[*i] != '\n' && data[*i] != ',')
		(*i)++;
	
	return (value);
}

t_color	parse_color(char *data, size_t *i)
{
    t_color	color;
    // check format of number

    color.v[0] = parse_float(data, i);
    color.v[1] = parse_int(data, i)/255.999;
    color.v[2] = parse_int(data, i)/255.999;
	color.v[2] = parse_int(data, i)/255.999;
    return color;
}

void	parse_ambient(t_minirt *minirt, char *data, size_t *i)
{
	(*i) += 1;
	minirt->ambiance.ratio = parse_float(data, i);
	minirt->ambiance.color = parse_color(data, i);
}

//static bool	get_ambient_color(t_minirt *minirt, t_split *fields,
//				int curr_line);

//bool	parse_ambient(t_minirt *minirt, t_split *fields, int curr_line)
//{
//	if (minirt->ambiance.is_set)
//		return (parse_fatal_msg(ER_AMBIENT_DEFINED, curr_line),
//			destroy_2d_arr(fields->array), false);
//	if (fields->wordcount != 3)
//		return (parse_err_msg(ER_AMBIENT_FORMAT, ER_EXPECT_TYPE_A,
//				curr_line), destroy_2d_arr(fields->array), false);
//	minirt->ambiance.ratio = ft_atof(fields->array[1], minirt);
//	if (minirt->error_code == 2)
//		return (parse_err_msg(ER_AMBIENT_FORMAT, ER_EXPECT_TYPE_A,
//				curr_line), destroy_2d_arr(fields->array), false);
//	if (minirt->ambiance.ratio < -0.f || minirt->ambiance.ratio > 1.f)
//		return (parse_err_msg(ER_AMBIENT_VALUE, ER_EXPECT_F_RANGE,
//				curr_line), destroy_2d_arr(fields->array), false);
//	return (get_ambient_color(minirt, fields, curr_line));
//}

//bool	get_ambient_color(t_minirt *minirt, t_split *fields, int curr_line)
//{
//	if (!parse_color(&minirt->ambiance.color, fields->array[2], curr_line))
//		return (destroy_2d_arr(fields->array), false);
//	minirt->ambiance.is_set = true;
//	minirt->ambiance.line_set = curr_line;
//	scale_color(&minirt->scene.ambiance, &minirt->ambiance.color,
//		minirt->ambiance.ratio);
//	return (destroy_2d_arr(fields->array), true);
//}
