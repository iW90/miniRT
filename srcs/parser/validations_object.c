/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_object.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:01:15 by inwagner          #+#    #+#             */
/*   Updated: 2023/12/12 22:26:15 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_obj	*new_object(void)
{
	t_obj	*object;
	t_obj	*last;

	object = malloc(sizeof(t_obj));
	if (!object)
		print_error(12);
	*object = (t_obj){0};
	if (!get_scene()->objs)
		get_scene()->objs = object;
	else
	{
		last = get_scene()->objs;
		while (last->next)
			last = last->next;
		last->next = object;
	}
	return (object);
}

void	validate_sphere(char *line)
{
	int		i;
	t_obj	*object;

	if (line[1] != 'p')
		print_error(-2);
	object = new_object();
	i = 2;
	object->type = SP;
	validate_space(line, &i, TRUE);
	get_xyz(line, &i, &object->cds[3], FALSE);
	validate_space(line, &i, TRUE);
	object->dia = get_double_number(line, &i, DBL_MIN, DBL_MAX);
	validate_space(line, &i, TRUE);
	get_rgb(line, &i, &object->rgb[3]);
	validate_space(line, &i, FALSE);
}

void	validate_plane(char *line)
{
	int		i;
	t_obj	*object;

	if (line[1] != 'l')
		print_error(-2);
	object = new_object();
	i = 2;
	object->type = PL;
	validate_space(line, &i, TRUE);
	get_xyz(line, &i, &object->cds[3], FALSE);
	validate_space(line, &i, TRUE);
	get_xyz(line, &i, &object->vts[3], TRUE);
	validate_space(line, &i, TRUE);
	get_rgb(line, &i, &object->rgb[3]);
	validate_space(line, &i, FALSE);
}

void	validate_cylinder(char *line)
{
	int		i;
	t_obj	*object;

	if (line[1] != 'y')
		print_error(-2);
	object = new_object();
	i = 2;
	object->type = CY;
	validate_space(line, &i, TRUE);
	get_xyz(line, &i, &object->cds[3], FALSE);
	validate_space(line, &i, TRUE);
	get_xyz(line, &i, &object->vts[3], TRUE);
	validate_space(line, &i, TRUE);
	object->dia = get_double_number(line, &i, DBL_MIN, DBL_MAX);
	validate_space(line, &i, TRUE);
	object->hgt = get_double_number(line, &i, DBL_MIN, DBL_MAX);
	validate_space(line, &i, TRUE);
	get_rgb(line, &i, &object->rgb[3]);
	validate_space(line, &i, FALSE);
}
