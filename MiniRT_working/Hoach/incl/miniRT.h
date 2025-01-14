/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:02:32 by honguyen          #+#    #+#             */
/*   Updated: 2024/12/02 15:11:29 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H


# include "../libs/libft/libft.h"
# include "define.h"
# include "all_structs.h"

# ifdef __APPLE__
#	include "../libs/mlx_macos/mlx.h"
# else
# 	include "../libs/mlx_linux/mlx.h"
# 	include <X11/X.h>
# endif



void	msg_err(char *s, int err, t_minirt *minirt);
void	free_minirt(t_minirt *minirt);


#endif