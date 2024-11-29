/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:39:51 by goosterl      #+#    #+#                 */
/*   Updated: 2019/11/21 18:04:03 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		ssize_t result = write(fd, &s[i], 1); // Store the return value of write()
		if (result == -1)
		{
			perror("write failed");
		}
		i++;
	}
}
