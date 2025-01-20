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

int	parse_int(char *data, size_t *i)
{
	int	value;

	while (data[*i] == '\t' || data[*i] == ' ' || data[*i] == ',')
		(*i)++;
	value = ft_atoi(&data[*i]);
	while (data[*i] && data[*i] != '\t' && data[*i] != ' ' \
			&& data[*i] != '\n' && data[*i] != ',')
		(*i)++;
	return (value);
}

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

 	color.a = 0.f;
    color.r = parse_int(data, i)/255.999f;
    color.g = parse_int(data, i)/255.999f;
	color.b = parse_int(data, i)/255.999f;
    return color;
}

void	parse_ambient(t_minirt *minirt, char *data, size_t *i)
{
	// Pass over 'A
	(*i) += 1;
	minirt->ambiance.ratio = parse_float(data, i);
	//  test
	printf("ambiance.ratio: %f\n", minirt->ambiance.ratio);
	minirt->ambiance.color = parse_color(data, i);
	// test
	printf("ambiance.color.b =: %f\n", minirt->ambiance.color.b);
}
