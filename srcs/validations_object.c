/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_object.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:01:15 by inwagner          #+#    #+#             */
/*   Updated: 2023/12/12 21:10:25 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	validate_sphere(char *line)
{
	int		i;
	t_obj	*object;

	if (line[i++] != 'p')
		print_error(-2);
	object = malloc(size_of(t_obj));
	if (!object)
		print_error(12);
	if (!get_scene()->obj)
		get_scene()->obj = object;
	else
		add_object(object);
	i = 1;
	object->type = SP;
	validate_space(line, &i, TRUE);
	object->cds = get_xyz(line, &i, FALSE);
	validate_space(line, &i, TRUE);
	object->dia = get_double_number(line, &i, F_MIN, F_MAX);
	validate_space(line, &i, TRUE);
	object->rgb = get_rgb(line, &i, &object->rgb);
	validate_space(line, &i, FALSE);
}

void	validate_plane(char *line)
{
	int		i;
	t_obj	*object;

	if (line[i++] != 'l')
		print_error(-2);
	object = malloc(size_of(t_obj));
	if (!object)
		print_error(12);
	if (!get_scene()->obj)
		get_scene()->obj = object;
	else
		add_object(object);
	i = 1;
	object->type = PL;
	validate_space(line, &i, TRUE);
	object->cds = get_xyz(line, &i, FALSE);
	validate_space(line, &i, TRUE);
	object->vts = get_xyz(line, &i, TRUE);
	validate_space(line, &i, TRUE);
	object->rgb = get_rgb(line, &i, &object->rgb);
	validate_space(line, &i, FALSE);
}

void	validate_cylinder(char *line)
{
	int		i;
	t_obj	*object;

	if (line[i++] != 'y')
		print_error(-2);
	object = malloc(size_of(t_obj));
	if (!object)
		print_error(12);
	if (!get_scene()->obj)
		get_scene()->obj = object;
	else
		add_object(object);
	i = 1;
	object->type = CY;
	validate_space(line, &i, TRUE);
	object->cds = get_xyz(line, &i, FALSE);
	validate_space(line, &i, TRUE);
	object->vts = get_xyz(line, &i, TRUE);
	validate_space(line, &i, TRUE);
	object->dia = get_double_number(line, &i, F_MIN, F_MAX);
	validate_space(line, &i, TRUE);
	object->hgt = get_double_number(line, &i, F_MIN, F_MAX);
	validate_space(line, &i, TRUE);
	object->rgb = get_rgb(line, &i, &object->rgb);
	validate_space(line, &i, FALSE);
}
