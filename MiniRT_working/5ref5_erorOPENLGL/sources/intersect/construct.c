/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 12:28:23 by goosterl          #+#    #+#             */
/*   Updated: 2024/11/29 13:57:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <jump_tables.h>
#include <unistd.h>

t_bool	construct(t_shapes **list)
{
	t_shapes	*cur_shape;
	// int			idx;

	cur_shape = *list;
	while (cur_shape != NULL)
	{
		// idx = 0;
		jump_construct(cur_shape);
		cur_shape = cur_shape->next;
	}
	return (true);
}
