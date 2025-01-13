/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:12:50 by honguyen          #+#    #+#             */
/*   Updated: 2024/12/05 15:31:32 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/miniRT.h"

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

int	errors(int err_code, t_minirt *minirt)
{
	close_minirt(minirt);
	if (err_code == ER_AGC)
		ft_putstr_fd(ER_USAGE, 2);
	else if (err_code == ER_MLX)
		ft_putstr_fd("Error in MLX initialization \n", 2);
	else if (err_code == ER_MOR)
		ft_putstr_fd("Error in MORE \n", 2);
	else
		ft_putstr_fd("Other Errors \n", 2);
	return (err_code);
}

