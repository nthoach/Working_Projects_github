/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:25:14 by nth          #+#    #+#             */
/*   Updated: 2024/10/16 13:01:58 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void		init_atof(char **rep, float *sign, t_minirt *f);
static void		validate_rep(char *rep, t_minirt *minirt);
static float	validate_float(float num, t_minirt *f);

float	ft_atof(char *rep, t_minirt *minirt)
{
	float	mantissa;
	float	dividend;
	bool	found_point;
	float	sign;

	validate_rep(rep, minirt);
	mantissa = 0.0;
	dividend = 1.0;
	found_point = false;
	init_atof(&rep, &sign, minirt);
	while (*rep && ++minirt->flt_operations)
	{
		if (ft_isdigit(*rep))
		{
			mantissa = (10 * mantissa) + (*rep - '0');
			if (found_point)
				dividend *= 10;
		}
		else if (*rep == '.' && !found_point)
			found_point = true;
		else
			break ;
		++rep;
	}
	return (validate_float((mantissa / dividend) * sign, minirt));
}

static void	init_atof(char **rep, float *sign, t_minirt *f)
{
	*sign = 1.0;
	while (**rep && (**rep == ' ' || **rep == '\t'))
		(*rep)++;
	if (**rep == '-' || **rep == '+')
	{
		if (**rep == '-')
			*sign = -1.0;
		(*rep)++;
		f->flt_operations++;
		if (!ft_isdigit(**rep))
			return (f->error_code = 2, (void)free(NULL));
	}
	else if (ft_isdigit(**rep))
	{
		if (*(*rep + 1) == '.')
		{
			if (!ft_isdigit(*(*rep + 2)))
				return (f->error_code = 2, (void)free(NULL));
		}
		else if (!ft_isdigit(*(*rep + 1)) && (*(*rep + 1) && *(*rep + 1)
				!= ',' && *(*rep + 1) != ' '))
			return (f->error_code = 2, (void)free(NULL));
	}
	else
		return (f->error_code = 2, (void)free(NULL));
}

static void	validate_rep(char *rep, t_minirt *minirt)
{
	t_vatof	utils;

	if (!rep || (rep && !*rep))
		return (minirt->error_code = 2, (void)free(NULL));
	utils = (t_vatof){0};
	while (*rep == ' ' || *rep == '\t')
		++rep;
	while (*rep)
	{
		if (*rep == '-' || *rep == '+')
			++utils.sign_count;
		else if (ft_isdigit(*rep))
			++utils.digit_count;
		else if (*rep == '.')
			++utils.dot_count;
		else if (ft_isalpha(*rep))
			utils.found_alpha = true;
		else
			break ;
		++rep;
	}
	if (!utils.digit_count || utils.sign_count > 1 || utils.found_alpha)
		return (minirt->error_code = 2, (void)free(NULL));
	minirt->error_code = 0;
	minirt->flt_operations = 0;
}

static float	validate_float(float num, t_minirt *f)
{
	if (isnan(num) || isinf(num))
		f->error_code = 2;
	return (num);
}