/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 19:19:46 by goosterl      #+#    #+#                 */
/*   Updated: 2019/11/14 12:36:42 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> 

void	ft_putchar_fd(char c, int fd)
{
	ssize_t result = write(fd, &c, 1); // Store the return value of write()

    if (result == -1)
    {
        perror("write failed");
    }
}
