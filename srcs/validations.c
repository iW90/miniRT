/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:58:39 by inwagner          #+#    #+#             */
/*   Updated: 2023/12/12 21:14:03 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_validations(char *line)
{
	if (*line == '\n' || !line)
		return ;
	else if (*line == 'A')
		validate_ambient(line);
	else if (*line == 'C')
		validate_camera(line);
	else if (*line == 'L')
		validate_light(line);
	else if (*line == 's')
		validate_sphere(line);
	else if (*line == 'p')
		validate_plane(line);
	else if (*line == 'c')
		validate_cylinder(line);
	else
		print_error(-2);
}

void	validate_file(char *argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error(-1);
	line = get_next_line(fd);
	get_scene()->line = line;
	while (line)
	{
		while (ft_isspace(*line))
			line++;
		parse_validations(line);
		free(line);
		line = get_next_line(fd);
	}
	fd = close(fd);
}
