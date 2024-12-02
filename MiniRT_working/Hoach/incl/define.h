/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:53:43 by honguyen          #+#    #+#             */
/*   Updated: 2024/12/02 12:08:01 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

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

//define error codes
# define OK     0
# define NOK    1
# define E_ARG  2
# define E_MLX  3
# define E_MOR  4
# define E_OTH  5


// Image size
#   define IMGW		    100
#   define IMGH		    100

// color define
#   define ORANGE       0xFE6500
#   define BLUE		    (t_color){0, 0, 0, 255}
#   define BLACK		(t_color){0, 0, 0, 0}
#   define WHITE		(t_color){0, 255, 255, 255}
#   define RED		    (t_color){0, 255, 0, 0}

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
#   define C            8
#   define V            9
# else // Linux
#   define KEY_ESC 65307
#   define KEY_W 119
#   define KEY_A 97
#   define KEY_S 115
#   define KEY_D 100
#   define KEY_C 99
#   define KEY_V 118
# endif

#endif
