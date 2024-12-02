/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:53:43 by honguyen          #+#    #+#             */
/*   Updated: 2024/12/02 15:12:59 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "all_structs.h"

// C libraries
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>

// define assets
# define S      "data/xpm/S100.xpm"
# define W	    "data/xpm/W100.xpm"
# define W0     "data/xpm/W0100.xpm"
# define P      "data/xpm/P100.xpm"
# define P_F	"data/xpm/P_F100.xpm"
# define P_B	"data/xpm/P_B100.xpm"
# define P_R	"data/xpm/P_R100.xpm"
# define P_L	"data/xpm/P_L100.xpm"
# define C      "data/xpm/C100.xpm"
# define E      "data/xpm/E100.xpm"
# define G      "data/xpm/G.xpm"

// math define
# define PI 3.1415926535f
# define RADIANS(deg) ((deg * PI) / 180.0f)
# define DEGREES(rad) ((rad * 180.0f) / PI)
# define EPSILON 0.0001
# define UPGUIDE		(t_vec3d){0.0, 1.0, 0.0}
# define VEC_EPSILON	(t_vec3d){EPSILON, EPSILON, EPSILON}

//define error codes
# define OK     0
# define NOK    1
# define ER_AGC  2
# define ER_MLX  3
# define ER_MOR  4
# define ER_OTH  5

# define ER_COLOR_A		"Wrong color syntax for ambient lightning."
# define ER_COLOR_L		"Wrong color syntax for light source."
# define ER_SYNTAX		"Syntax: file format misconfiguration."
# define ER_NOT_RT		"File extension is not '.rt'."
# define ER_OPEN_FILE	"Couldn't open requested file"
# define ER_EMPTY_MAP	"Empty map"
# define ER_NO_CAMERA	"No camera in the map"
# define ER_TOO_MANY	"Found more than 1 A, C or L entities"
# define ER_MALLOC(str) "Failed allocation on "str"."
# define ER_USAGE 		 "Usage: ./miniRT <scene>.rt \n"

//Window sizes
# ifdef __APPLE__
#  define WIDTH 1440
# else
#  define WIDTH 1920
# endif
# define RATIO 	(16.0/9.0)
# define HEIGHT (WIDTH/RATIO)

// color define
#  define ORANGE    (t_color){255, 254, 101, 0}
#  define BLUE		(t_color){0, 0, 0, 255}
#  define BLACK		(t_color){0, 0, 0, 0}
#  define WHITE		(t_color){0, 255, 255, 255}
#  define RED		(t_color){0, 255, 0, 0}

// Keyboard define
# ifdef __APPLE__
#   define KEY_A		0
#   define KEY_D		2
#   define KEY_W		13
#   define KEY_S		1	
#   define KEY_LEFT	    123
#   define KEY_RIGHT	124
#   define KEY_UP		126
#   define KEY_DOWN	    125
#   define KEY_ESC      53
#   define KEY_Q		12
#   define KEY_C        8
#   define KEY_V        9
#   define KeyPress     2
#   define KeyPressMask (1L<<0)
#   define DestroyNotify 17
#   define StructureNotifyMask (1L<<17)
# else // Linux
#   define KEY_A        97      
#   define KEY_D        100     // 'd'
#   define KEY_W        119     // 'w'
#   define KEY_S        115     // 's'
#   define KEY_LEFT     65361   // Left arrow
#   define KEY_RIGHT    65363   // Right arrow
#   define KEY_UP       65362   // Up arrow
#   define KEY_DOWN     65364   // Down arrow
#   define KEY_ESC      65307   // Escape key
#   define KEY_Q        113     // 'q'
#   define KEY_C        99      // 'c'
#   define KEY_V        118     // 'v'
# endif

#endif
