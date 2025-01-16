/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nth <nth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 03:10:59 by nth          #+#    #+#             */
/*   Updated: 2024/10/16 13:29:29 by nth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"

void	count_elements(t_minirt *minirt, char *line)
{
	//size_t	len;

	//len = ft_strlen(line);
	while (*line == ' ')
		line++;
	if (*line == 'A' && *(line + 1) == ' ')
		minirt->scene.num_a++;
	else if (*line == 'C' && *(line + 1) == ' ')
		minirt->scene.num_c++;
	else if ((*line == 'L' && *(line + 1) == ' ') || \
	 (*line == 'S' && *(line + 1) == 'L' && *(line + 2) == ' '))
		minirt->scene.num_lights++;
	else if ((*line == 's' && *(line + 1) == 'p' && *(line + 2) == ' ') || \
		(*line == 'p' && *(line + 1) == 'l' && *(line + 2) == ' ') || \
		(*line == 'c' && *(line + 1) == 'y' && *(line + 2) == ' ') || \
		(*line == 'c' && *(line + 1) == 'u' && *(line + 2) == ' ') || \
		(*line == 'c' && *(line + 1) == 'o' && *(line + 2) == ' '))
		minirt->scene.num_shapes++;
	else
		errors(CER_OBJ_TYPE, ER_OBJ_TYPE, minirt);
}
void	check_elements(t_minirt *minirt)
{
	if (minirt->scene.num_c != 1)
		errors(CER_ONE_CAMERA, ER_ONE_CAMERA, minirt);
	if (minirt->scene.num_a != 1)
		errors(CER_ONE_AMBIENT, ER_ONE_AMBIENT, minirt);
	if (minirt->scene.num_lights == 0)
		errors(CER_NO_LIGHT, ER_NO_LIGHT, minirt);
	if (minirt->scene.num_lights > LIGHTS_MAX)
		errors(CER_MAX_LIGHT, ER_MAX_LIGHT, minirt);
	if (minirt->scene.num_shapes == 0)
		errors(CER_NO_OBJ, ER_NO_OBJ, minirt);
	if (minirt->scene.num_shapes > SHAPES_MAX)
		errors(CER_MAX_SHAPES, ER_MAX_SHAPES, minirt);
}

// Helper function: Calculate the memory required
size_t	calculate_required_size(char *file, t_minirt *minirt)
{
	char	*line;
	int		fd;
	size_t	total_size;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		errors(CER_OPEN_FILE, ER_OPEN_FILE, minirt);
	total_size = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!ft_strchr("\n#", line[0]))
		{
			total_size += ft_strlen(line);
			count_elements(minirt, line);
		}
		free(line);
	}
	close(fd);
	// Check errors in file data
	check_elements(minirt);
	return (total_size);
}

char	*file_data(t_minirt *minirt, size_t *total_size, char *file)
{
	int		fd;
	char	*line;
	char	*data;
	size_t	line_len;

	data = ft_calloc(calculate_required_size(file, minirt) + 1, sizeof(char));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		errors(CER_OPEN_FILE, ER_OPEN_FILE, minirt);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!ft_strchr("\n#", line[0]))
		{
			line_len = ft_strlen(line);
			ft_memcpy(data + *total_size, line, line_len);
			*total_size += line_len;
		}
		free(line);
	}
	data[*total_size]= '\0';
	close(fd);
	return (data);
}

void	allocate_light_obj(t_minirt *minirt)
{
	minirt->scene.lights = (t_light *)malloc(minirt->scene.num_lights * sizeof(t_light));
	if (!minirt->scene.lights)
		errors(CER_MALLOC, ER_MALLOC, minirt);
	minirt->scene.shapes = (t_object *)malloc(minirt->scene.num_shapes * sizeof(t_object));
	if (!minirt->scene.shapes)
		errors(CER_MALLOC, ER_MALLOC, minirt);
}

void	parse(char *file, t_minirt *minirt)
{
	char	*data;
	size_t	total_size;

	total_size = 0;
	data = NULL;
	data = file_data(minirt, &total_size, file);
	if (!data || total_size == 0)
	{
		free(data);
		errors(CER_EMPTY_MAP, ER_EMPTY_MAP, minirt);
	}
	// test
	printf("%s\n", data);
	printf("num_a: %d\n", minirt->scene.num_a);
	printf("num_c: %d\n", minirt->scene.num_c);
	printf("num_lights: %d\n", minirt->scene.num_lights);
	printf("num_shapes: %d\n", minirt->scene.num_shapes);
	//
	allocate_light_obj(minirt);
	parse_data(minirt, data);
	free(data);
}

//bool	parse_uppercase_object(t_minirt *minirt, const char *info,
//			int curr_line)
//{
//	t_split	split;

//	split = ft_split(info, " ");
//	if (!split.array)
//		errors(CER_MALLOC, ER_MALLOC, minirt);
//	if (*info == 'A')
//		return (parse_ambient(minirt, &split, curr_line));
//	if (*info == 'C')
//		return (parse_camera(minirt, &split, curr_line));
//	if (*info == 'L')
//		return (parse_light(minirt, &split, curr_line));
//	destroy_2d_arr(split.array);
//	return (true);
//}
//bool	check_object_validity_and_add(t_minirt *minirt, const char *info,
//			int curr_line, size_t line_len)
//{
//	const t_split	fields = ft_split(info, " ");

//	if (!ft_isalpha(*info))
//		return (destroy_2d_arr(fields.array),
//			parse_syn_err_msg((char *)info, curr_line), false);
//	if (*info == 'A' || *info == 'C' || *info == 'L')
//	{
//		if (line_len > 1 && *(info + 1) != ' ')
//			return (destroy_2d_arr(fields.array),
//				parse_syn_err_msg((char *)info, curr_line), false);
//		return (destroy_2d_arr(fields.array),
//			parse_uppercase_object(minirt, info, curr_line));
//	}
//	return (check_object_validity_init(minirt, info, curr_line, fields));
//}

//bool	read_file_ext(t_gnl *line, t_minirt *minirt, int curr_line,
//		const char *filename)
//{
//	if (line->error)
//		return (parse_fatal_msg("Allocation failure", curr_line), false);
//	if ((line->eof && curr_line == 1)
//		|| (minirt->scene.num_lights == 0 || minirt->scene.num_shapes == 0)
//		|| (!minirt->ambiance.is_set || !minirt->cam.is_set))
//	{
//		if (line->line)
//			free(line->line);
//		ft_putstr_fd("Error: file `", STDERR_FILENO);
//		ft_putstr_fd((char *)filename, STDERR_FILENO);
//		ft_putendl_fd("` appears to be incomplete. Need:", STDERR_FILENO);
//		if (!minirt->scene.num_lights)
//			ft_putendl_fd("\tAt least one light.", 2);
//		if (!minirt->scene.num_shapes)
//			ft_putendl_fd("\tAt least one shape.", 2);
//		if (!minirt->ambiance.is_set)
//			ft_putendl_fd("\tExactly one value for global Ambiance lighting.",
//				2);
//		if (!minirt->cam.is_set)
//			ft_putendl_fd("\tExactly one camera.", 2);
//		return (false);
//	}
//	return (true);
//}

//bool	read_file(int fd, t_minirt *minirt, const char *filename)
//{
//	t_gnl		line;
//	uint32_t	curr_line;

//	line = get_next_line(fd);
//	curr_line = 1;
//	while (!line.error && !line.eof)
//	{
//		if (*line.line == '\n' || *line.line == '#')
//		{
//			(free(line.line), curr_line++);
//			line = get_next_line(fd);
//			continue ;
//		}
//		if (!check_object_validity_and_add(minirt, line.line, curr_line++,
//				line.len))
//		{
//			ft_putstr_fd((char *)filename, 2);
//			ft_putstr_fd(":\n\t", 2);
//			ft_putendl_fd(line.line, 2);
//			return ((void)close(fd), free(line.line), errors(CER_SYNTAX, ER_SYNTAX, minirt), false);
//		}
//		free(line.line);
//		line = get_next_line(fd);
//	}
//	return (close(fd), read_file_ext(&line, minirt, curr_line, filename));
//}

//bool	parse(const char *filename, t_minirt *minirt)
//{
//	int			fd;

//	fd = open(filename, O_RDONLY);
//	if (fd < 0)
//		errors(CER_OPEN_FILE, ER_OPEN_FILE, NULL);
//	return (read_file(fd, minirt, filename));
//}
