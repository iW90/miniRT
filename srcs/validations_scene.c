/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:00:32 by inwagner          #+#    #+#             */
/*   Updated: 2023/12/12 21:58:58 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	validate_ambient(char *line)
{
	int		i;
	t_amb	*ambient;

	if (get_scene()->a)
		print_error(-2);
	ambient = malloc(sizeof(t_amb));
	if (!ambient)
		print_error(12);
	get_scene()->a = ambient;
	i = 1;
	validate_space(line, &i, TRUE);
	ambient->rat = get_double_number(line, &i, 0.0, 1.0);
	validate_space(line, &i, TRUE);
	get_rgb(line, &i, &ambient->rgb[3]);
	validate_space(line, &i, FALSE);
}

void	validate_camera(char *line)
{
	int		i;
	t_cam	*camera;

	if (get_scene()->c)
		print_error(-2);
	camera = malloc(sizeof(t_cam));
	if (!camera)
		print_error(12);
	get_scene()->c = camera;
	i = 1;
	validate_space(line, &i, TRUE);
	get_xyz(line, &i, &camera->cds[3], FALSE);
	validate_space(line, &i, TRUE);
	get_xyz(line, &i, &camera->vts[3], TRUE);
	validate_space(line, &i, TRUE);
	camera->fov = get_int_number(line, &i, 0, 180);
	validate_space(line, &i, FALSE);
}

void	validate_light(char *line)
{
	int		i;
	t_lgt	*light;

	if (get_scene()->l)
		print_error(-2);
	light = malloc(sizeof(t_lgt));
	if (!light)
		print_error(12);
	get_scene()->l = light;
	i = 1;
	validate_space(line, &i, TRUE);
	get_xyz(line, &i, &light->cds[3], FALSE);
	validate_space(line, &i, TRUE);
	light->bri = get_double_number(line, &i, 0.0, 1.0);
	validate_space(line, &i, TRUE);
	get_rgb(line, &i, &light->rgb[3]);
	validate_space(line, &i, FALSE);
}
