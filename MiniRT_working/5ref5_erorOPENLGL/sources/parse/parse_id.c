/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:55:39 by goosterl          #+#    #+#             */
/*   Updated: 2024/11/29 13:56:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <parse.h>
# include <libft.h>

char	*parse_id(char **line)
{
	char	*id;
	int		len;
	// int		idx;

	// idx = 0;
	*line += ft_strspn(*line, DELIM_SPACE);
	if (**line == '\0')
		return (NULL);
	len = ft_strcspn(*line, DELIM_SPACE);
	if (len == 0)
		return (NULL);
	id = (char *)ft_calloc(1, len + 1);
	ft_memcpy(id, *line, len);
	*line += len;
	*line += ft_strspn(*line, DELIM_SPACE);
	return (id);
}

#endif
