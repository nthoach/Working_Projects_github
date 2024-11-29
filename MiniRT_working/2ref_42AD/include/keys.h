/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:00:13 by ebinjama          #+#    #+#             */
/*   Updated: 2024/11/20 10:16:29 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __linux__

enum e_keysyms
{
	MOUSE_LMB = 1,
	MSCROLL_UP = 4,
	MSCROLL_DOWN,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_R = 114,
	KEY_LCTRL = 65507,
	KEY_LSHIFT = 65505,
	KEY_SPACE = 32,
	AKEY_L = 65361,
	AKEY_U,
	AKEY_R,
	AKEY_D,
	KEY_ESC = 65307
};
# endif // !__linux__

# ifdef __MACH__

enum e_keysyms
{
	MSCROLL_UP = 4,
	MSCROLL_DOWN,
	KEY_ESC = 53,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_R = 15,
	KEY_SPACE = 49,
	KEY_LCTRL = 256,
	KEY_LSHIFT = 257,
	AKEY_L = 123,
	AKEY_R,
	AKEY_D,
	AKEY_U
};

enum e_mouse
{
	MOUSE_LMB = 1
};

# endif // !__MACH__

enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP,
	ON_MOUSEDOWN,
	ON_MOUSEUP,
	ON_MOUSEMOVE,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

#endif // !KEYS_H