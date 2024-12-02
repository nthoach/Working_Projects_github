/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:02:32 by honguyen          #+#    #+#             */
/*   Updated: 2024/12/02 12:09:43 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H


# ifdef __APPLE__
#	include "../libs/mlx_macos/mlx.h"
# else
# 	include "../libs/mlx_linux/mlx.h"
# 	include <X11/X.h>
# endif


# include "define.h"
# include "../libs/libft/libft.h"

typedef struct s_minirt
{
	int		w;
	int		h;
	int		no_aw;
	int		ct_exit;
	int		ct_aw;
	int		exit;
	int		i0;
	int		j0;
	int		ri0;
	int		rj0;
	int		ct_steps;
	char	**map;
	char	map_h[256][256];
	void	*mlx;
	void	*mlx_win;
	void	*mlx_text;
	void	*img;
}	t_minrt;

void	msg_err(char *s, int err, t_solong *solong);
void	free_solong(t_solong *solong);


#endif