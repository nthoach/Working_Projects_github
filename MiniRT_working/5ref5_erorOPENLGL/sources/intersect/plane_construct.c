/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_construct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:40:59 by goosterl          #+#    #+#             */
/*   Updated: 2024/11/29 13:58:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <scene.h>

t_bool	plane_construct(t_shapes *catch)
{
	// t_plane		*plane;

	// plane = catch->shape;
	catch->volume.using = false;
	return (true);
}

#endif
