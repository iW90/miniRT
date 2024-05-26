/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:26:25 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/26 10:26:30 by maalexan         ###   ########.fr       */
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
