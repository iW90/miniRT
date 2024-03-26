/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_object.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:01:15 by inwagner          #+#    #+#             */
/*   Updated: 2024/03/25 21:12:02 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_object	*new_object(t_type type)
{
	t_object	*object;
	t_object	*last;

	object = malloc(sizeof(t_object));
	if (!object)
		print_error(12);
	object->type = type;
	object->next = NULL;
	if (!get_scene()->objects)
		get_scene()->objects = object;
	else
	{
		last = get_scene()->objects;
		while (last->next)
			last = last->next;
		last->next = object;
	}
	return (object);
}

void	validate_sphere(char *line)
{
	int			i;
	t_sphere	*sphere;
	t_object	*object;

	i = 2;
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		print_error(12);
	validate_space(line, &i, TRUE);
	sphere->coords = get_xyz(line, &i, FALSE);
	validate_space(line, &i, TRUE);
	sphere->diameter = get_float_number(line, &i, FLT_MIN, FLT_MAX);
	validate_space(line, &i, TRUE);
	sphere->rgb = get_rgb(line, &i);
	validate_space(line, &i, FALSE);
	object = new_object(SPHERE);
	object->data.sphere = sphere;
}

void	validate_plane(char *line)
{
	int			i;
	t_plane		*plane;
	t_object	*object;

	i = 2;
	plane = malloc(sizeof(t_plane));
	if (!plane)
		print_error(12);
	validate_space(line, &i, TRUE);
	plane->coords = get_xyz(line, &i, FALSE);
	validate_space(line, &i, TRUE);
	plane->norm_vector = get_xyz(line, &i, TRUE);
	validate_space(line, &i, TRUE);
	plane->rgb = get_rgb(line, &i);
	validate_space(line, &i, FALSE);
	object = new_object(PLANE);
	object->data.plane = plane;
}

void	validate_cylinder(char *line)
{
	int			i;
	t_cylinder	*cylinder;
	t_object	*object;

	i = 2;
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		print_error(12);
	validate_space(line, &i, TRUE);
	cylinder->coords = get_xyz(line, &i, FALSE);
	validate_space(line, &i, TRUE);
	cylinder->norm_vector = get_xyz(line, &i, TRUE);
	validate_space(line, &i, TRUE);
	cylinder->diameter = get_float_number(line, &i, FLT_MIN, FLT_MAX);
	validate_space(line, &i, TRUE);
	cylinder->height = get_float_number(line, &i, FLT_MIN, FLT_MAX);
	validate_space(line, &i, TRUE);
	cylinder->rgb = get_rgb(line, &i);
	validate_space(line, &i, FALSE);
	object = new_object(CYLINDER);
	object->data.cylinder = cylinder;
}
