/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:57:37 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/26 10:25:03 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

typedef struct s_file
{
	char	*line;
	int		fd;
	int		valid;
}			t_file;

typedef struct s_parse
{
	char	*id;
	int		(*validate)(char *);
	int		flag;
}			t_parse;

void	validate_args(int argc, char **argv);
void	handle_line_error(t_file *file_scene);
void	process_line(t_file *file_scene);
int		validate_scene(char *file);
int		validate_orientation(char *str1, char *str2, char *str3);
int		validate_color(char *line, t_vector *color);
int		validate_ambient(char *line);
int		validate_camera(char *line);
int		validate_light(char *line);
int		validate_sphere(char *line);
int		validate_plane(char *line);
int		validate_cylinder(char *line);
int		validate_cy_split(char **split);
int		validate_cylinder_position(char *line, t_cylinder *cylinder);
int		validate_cylinder_diameter(char *line, t_cylinder *cylinder);
int		validate_cylinder_height(char *line, t_cylinder *cylinder);
int		validate_cylinder_orientation(char *line, t_cylinder *cylinder);
int		handle_invalid_split(char **split);
int		handle_invalid_cylinder(t_cylinder *cylinder, char **split);
int		parse_cylinder_properties(char **split, t_cylinder *cylinder);
void	set_cylinder_properties(t_cylinder *cylinder);
int		free_split(char **split);

#endif