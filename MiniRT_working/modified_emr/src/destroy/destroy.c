/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nth <nth@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 06:06:16 by nth          #+#    #+#             */
/*   Updated: 2024/10/07 09:26:22 by nth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "miniRT.h"
#include "macros.h"

void	destroy_mlx(t_minirt *minirt)
{
	mlx_destroy_image(minirt->mlx, minirt->frame.ptr);
	mlx_destroy_window(minirt->mlx, minirt->win);
	free(minirt->mlx);
}

void	destroy_scene(t_minirt *minirt)
{
	free(minirt->scene.lights);
	free(minirt->scene.shapes);
}

void	destroy_textures(t_minirt *minirt)
{
	t_list	*temp;

	temp = minirt->textures;
	while (temp)
	{
		free(((t_tex_frame *)temp->content)->name);
		mlx_destroy_image(minirt->mlx,
			((t_tex_frame *)temp->content)->fra_tex->ptr);
		free(((t_tex_frame *)temp->content)->fra_tex);
		temp = temp->next;
	}
	ft_lstclear(&minirt->textures, free);
}

int	destroy_minirt(t_minirt *minirt)
{
	int	i;

	if (minirt->core)
	{
		minirt->stop = true;
		i = -1;
		while (++i < _RT_NUM_THREADS)
		{
			pthread_mutex_lock(&minirt->core[i].mutex);
			pthread_cond_signal(&minirt->core[i].cond);
			pthread_mutex_unlock(&minirt->core[i].mutex);
			pthread_mutex_destroy(&minirt->core[i].mutex);
			pthread_cond_destroy(&minirt->core[i].cond);
		}
		i = -1;
		while (++i < _RT_NUM_THREADS)
			pthread_join(minirt->core[i].thread, NULL);
		free(minirt->core);
		minirt->core = NULL;
	}
	destroy_scene(minirt);
	destroy_textures(minirt);
	destroy_mlx(minirt);
	return (exit(0), 0);
}

// @warning Assumes `arr` is `NULL`-terminated.
void	str_arr_destroy(char **arr)
{
	char	**original;

	if (!arr)
		return ;
	original = arr;
	while (*arr)
		free(*arr++);
	free(original);
}
