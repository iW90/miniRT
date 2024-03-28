/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_getters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:07:23 by inwagner          #+#    #+#             */
/*   Updated: 2024/03/28 14:27:30 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	get_rgb_component(char *line, int *i)
{
	int	number;

	number = ft_atoi(&line[*i]);
	if (number < 0 || number > 255)
		print_error(-2);
	while (ft_isdigit(line[*i]) || ft_isspace(line[*i]))
		(*i)++;
	if (line[*i] != ',' && line[*i] != '\0' && line[*i] != '\n')
		print_error(-2);
	if (line[*i] == ',')
		(*i)++;
	return ((float)number);
}

t_vec3f	get_rgb(char *line, int *i)
{
	t_vec3f	rgb;

	rgb.x = get_rgb_component(line, i);
	rgb.y = get_rgb_component(line, i);
	rgb.z = get_rgb_component(line, i);
/*	rgb.x = rgb.x / 255.0f;
	rgb.y = rgb.y / 255.0f; This is for normalizing
	rgb.z = rgb.z / 255.0f; */
	return (rgb);
}

static float	get_coords_component(char *line, int *i, int normalized)
{
	float	number;

	number = ft_atof(&line[*i]);
	if (normalized && (number < -1.0 || number > 1.0))
		print_error(-2);
	while (ft_isdigit(line[*i]) || line[*i] == '.' || line[*i] == '-')
		(*i)++;
	if (line[*i] != ',' && line[*i] != '\0')
		print_error(-2);
	if (line[*i] == ',')
		(*i)++;
	return (number);
}

t_vec3f	get_coords(char *line, int *i, int normalized)
{
	t_vec3f	coords;

	coords.x = get_coords_component(line, i, normalized);
	coords.y = get_coords_component(line, i, normalized);
	coords.z = get_coords_component(line, i, normalized);
	return (coords);
}
