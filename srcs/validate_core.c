/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:26:25 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/26 09:54:54 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "../incl/validate.h"

static int	valid_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

static int	print_line_error(char *line)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("Invalid line: ", STDERR_FILENO);
	ft_putstr_fd(line, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (0);
}

static int	validate_line(char *line)
{
	int				i;
	char			*id;
	static t_parse	parse[] = {{"A ", validate_ambient, 0},
	{"C ", validate_camera, 0}, {"L ", validate_light, 0},
	{"sp", validate_sphere,	0}, {"pl", validate_plane, 0},
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

char	*format_spaces(char *line)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	new_line = malloc(ft_strlen(line) + 1);
	if (!new_line)
		return (NULL);
	while (line[i] && line[i + 1])
	{
		if (line[i] == ' ' && (line[i + 1] == ' ' || line[i + 1] == '\t'))
		{
			i++;
			continue ;
		}
		new_line[j] = line[i];
		i++;
		j++;
	}
	new_line[j] = '\0';
	free(line);
	return (new_line);
}

static void handle_line_error(t_file *file_scene)
{
	file_scene->valid = print_line_error(file_scene->line);
	while (file_scene->line)
	{
		free(file_scene->line);
		file_scene->line = get_next_line(file_scene->fd);
	}
}

static void process_line(t_file *file_scene)
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

int validate_scene(char *file)
{
	t_file file_scene;

	file_scene.valid = 1;
	file_scene.fd = valid_fd(file);
	file_scene.line = get_next_line(file_scene.fd);

	process_line(&file_scene);

	free(file_scene.line);
	close(file_scene.fd);
	return file_scene.valid;
}
