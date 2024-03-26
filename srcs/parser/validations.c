/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:58:39 by inwagner          #+#    #+#             */
/*   Updated: 2024/03/26 20:36:13 by maalexan         ###   ########.fr       */
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

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		print_error(-1);
	line = get_next_line(fd);
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

int	apply_validations(int argc, char **argv)
{
	if (argc != 2)
		print_error(-1);
	validate_file(argv[1]);
	return (3);
}
