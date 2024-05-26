/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_core_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:23:06 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/26 10:26:41 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	validate_line(char *line)
{
	int				i;
	char			*id;
	static t_parse	parse[] = {{"A ", validate_ambient, 0},\
	{"C ", validate_camera, 0}, {"L ", validate_light, 0},\
	{"sp", validate_sphere,	0}, {"pl", validate_plane, 0},\
	{"cy", validate_cylinder, 0}, {NULL, NULL, 0}};

	id = ft_substr(line, 0, 2);
	if (!id)
		return (0);
	i = 0;
	while (parse[i].id && ft_strncmp(id, parse[i].id, 2) != 0)
		i++;
	if (!parse[i].id || parse[i].flag)
	{
		free(id);
		return (0);
	}
	if (i < 3)
		parse[i].flag = 1;
	free(id);
	return (parse[i].validate(++line));
}

static int	print_line_error(char *line)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("Invalid line: ", STDERR_FILENO);
	ft_putstr_fd(line, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (0);
}

void process_line(t_file *file_scene)
{
	while (file_scene->line && file_scene->valid == 1 && file_scene->line[0] != '\0')
	{
		if (file_scene->line[0] == '\n')
		{
			free(file_scene->line);
			file_scene->line = get_next_line(file_scene->fd);
			continue;
		}
		if (!validate_line(file_scene->line))
		{
			handle_line_error(file_scene);
			break;
		}
		free(file_scene->line);
		file_scene->line = get_next_line(file_scene->fd);
	}
}

void	handle_line_error(t_file *file_scene)
{
	file_scene->valid = print_line_error(file_scene->line);
	while (file_scene->line)
	{
		free(file_scene->line);
		file_scene->line = get_next_line(file_scene->fd);
	}
}



