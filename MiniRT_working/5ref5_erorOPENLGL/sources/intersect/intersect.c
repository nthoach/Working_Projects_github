/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:21:39 by goosterl          #+#    #+#             */
/*   Updated: 2024/11/29 13:58:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <jump_tables.h>
#include <unistd.h>

t_bool	intersect(const t_shapes *shapes, t_hitrecord *rec)
{
	t_shapes	*cur_shape;
	// int			idx;
	// t_bool		found;

	cur_shape = (t_shapes *)shapes;
	if (rec->ray.max == 0)
		return (false);
	rec->aabb_hit = false;
	while (cur_shape != NULL)
	{
		// idx = 0;
		// found = false;
		if (aabb_test(rec->ray, cur_shape->volume, &rec->aabb_hit))
			jump_intersect(cur_shape, rec);
		cur_shape = cur_shape->next;
	}
	if (rec->ref)
		return (true);
	return (false);
}
