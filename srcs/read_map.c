/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:58:39 by inwagner          #+#    #+#             */
/*   Updated: 2023/12/10 21:14:38 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_acl(char	*letter)
{
	if (*letter == 'A')
	{
		
		return (1);
	}
	else if (*letter == 'C')
	{
		
		return (2);
	}
	else if (*letter == 'L')
	{
		
		return (3);
	}
	else
		return (7);
}

void	validate_file(char *argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error(-1);
	format_validation(argv, fd);
	fd = close(fd);
}

void	parse_validations(char *line)
{
	int	sum;
	int	acl;

	sum = 0;
	acl = 0;
	if (*line == '\n')
		return ;
	else if (*line == 's' || *line == 'p' || *line == 'c' )
		validate_obj(*line);
	else if (*line == 'L' || *line == 'A' || *line == 'C' )
	{
		sum += validate_acl(*line);
		if (sum != 6 && ++acl != 3)
			print_error(-2);
	}
	else
		print_error(-2);
}

void	validate_formatation(char *file, int fd)
{
	char	*line;

	line = get_next_line(fd);
	get_scene()->line = line;
	while (line)
	{
		while (ft_isspace(line))
			line++;
		parse_validations(line);
		free(line);
		get_scene()->line = NULL;
		line = get_next_line(fd);
	}
}
