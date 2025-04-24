/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:48:35 by marvin            #+#    #+#             */
/*   Updated: 2024/12/04 16:48:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/miniRT.h"

char **read_rt(t_minirt *minirt, char *filert)
{
    int fd, i = 0;
    char *line;
    char **rt;

    if (!minirt || !filert)
        return errors(ER_INVALID_INPUT, minirt), NULL;

    map = malloc_map(get_filesize(minirt, filert), 0);
    if (!map)
        return errors(ER_MALLOC, minirt), NULL;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        free(map);
        return errors(ER_OPEN_FILE, minirt), NULL;
    }

    while ((line = get_next_line(fd)))
    {
        if (!ft_strchr("\n#", line[0]))
            map[i++] = line;
        else
            free(line);
    }
    close(fd);
//    map[i] = NULL; // Ensure NULL-termination
    return map;
}
