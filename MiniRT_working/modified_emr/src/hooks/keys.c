/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:11:55 by nth          #+#    #+#             */
/*   Updated: 2025/01/13 17:34:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "keys.h"
#include "macros.h"

int	check_state(void *minirt)
{
	t_minirt	*state;

	state = (t_minirt *)minirt;
	if (state->stop)
	{
		if (!state->selected.is_cam)
		{
			state->selected.is_cam = true;
			state->selected.object = NULL;
			state->stop = false;
		}
		else
			return (destroy_minirt(minirt), 0);
	}
	if (state->selected.is_cam)
	{
		camera_controls(state);
		if (state->movement.left || state->movement.right
			|| state->movement.up || state->movement.down)
			camera_rotations(state);
	}
	else if (state->movement.a || state->movement.d || state->movement.s
		|| state->movement.w || state->movement.space || state->movement.leftshift)
		object_controls(state);
	return (update(minirt), 0);
}

static inline void	_check_movement_controls(t_minirt *state, int keysym)
{
	if (keysym == KEY_A)
		state->movement.a = true;
	if (keysym == KEY_D)
		state->movement.d = true;
	if (keysym == KEY_S)
		state->movement.s = true;
	if (keysym == KEY_W)
		state->movement.w = true;
	if (keysym == KEY_SPACE)
		state->movement.space = true;
	if (keysym == KEY_LSHIFT)
		state->movement.leftshift = true;
	if (keysym == AKEY_U)
		state->movement.up = true;
	if (keysym == AKEY_D)
		state->movement.down = true;
	if (keysym == AKEY_L)
		state->movement.left = true;
	if (keysym == AKEY_R)
		state->movement.right = true;
}

static inline void	_check_config_controls(t_minirt *state, int keysym)
{
	if (keysym == KEY_R)
		state->scene.refract_reflect ^= true;
}

int	check_key_presses(int keysym, void *minirt)
{
	t_minirt	*state;

	state = (t_minirt *)minirt;
	if (keysym == KEY_ESC)
	{
		state->stop = true;
		return (0);
	}
	_check_config_controls(state, keysym);
	_check_movement_controls(state, keysym);
	return (keysym);
}

int	check_key_releases(int keysym, void *param)
{
	t_minirt	*state;

	state = (t_minirt *)param;
	if (keysym == KEY_A)
		state->movement.a = false;
	if (keysym == KEY_D)
		state->movement.d = false;
	if (keysym == KEY_S)
		state->movement.s = false;
	if (keysym == KEY_W)
		state->movement.w = false;
	if (keysym == KEY_SPACE)
		state->movement.space = false;
	if (keysym == KEY_LSHIFT)
		state->movement.leftshift = false;
	if (keysym == AKEY_U)
		state->movement.up = false;
	if (keysym == AKEY_D)
		state->movement.down = false;
	if (keysym == AKEY_L)
		state->movement.left = false;
	if (keysym == AKEY_R)
		state->movement.right = false;
	return (keysym);
}
