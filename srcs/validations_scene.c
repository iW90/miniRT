/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:00:32 by inwagner          #+#    #+#             */
/*   Updated: 2023/12/12 20:24:06 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void	validate_ambient(char *line)
{
	int		i;
	t_conf	scene;
	t_amb	ambient;

	scene = get_scene();
	if (scene->a)
		print_error(-2);
	ambient = malloc(size_of(t_amb));
	if (!ambient)
		print_error(12);
	scene->a = ambient;
	i = 1;
	validate_space(line, &i, TRUE);
	ambient->rat = get_double_number(line, &i, 0.0, 1.0);
	validate_space(line, &i, TRUE);
	ambient->rgb = get_rgb(line, &i, &ambient->rgb);
	validate_space(line, &i, FALSE);
}

void	validate_camera(char *line)
{
	int		i;
	t_conf	scene;
	t_cam	camera;

	scene = get_scene();
	if (scene->c)
		print_error(-2);
	camera = malloc(size_of(t_cam));
	if (!camera)
		print_error(12);
	scene->c = camera;
	i = 1;
	validate_space(line, &i, TRUE);
	camera->cds = get_xyz(line, &i, FALSE);
	validate_space(line, &i, TRUE);
	camera->vts = get_xyz(line, &i, TRUE);
	validate_space(line, &i, TRUE);
	camera->fov = get_int_number(line, &i, 0, 180);
	validate_space(line, &i, FALSE);
}

void	validate_light(char *line)
{
	int		i;
	t_conf	scene;
	t_lgt	light;

	scene = get_scene();
	if (scene->l)
		print_error(-2);
	light = malloc(size_of(t_lgt));
	if (!light)
		print_error(12);
	scene->l = light;
	i = 1;
	validate_space(line, &i, TRUE);
	light->cds = get_xyz(line, &i, FALSE);
	validate_space(line, &i, TRUE);
	light->bri = get_double_number(line, &i, 0.0, 1.0);
	validate_space(line, &i, TRUE);
	light->rgb = get_rgb(line, &i, &light->rgb);
	validate_space(line, &i, FALSE);
}

int	validate_acl(char *letter)
{
	if (*letter == 'A')
	{
		validate_ambient(letter);
		return (1);
	}
	if (*letter == 'C')
	{
		validate_camera(letter);
		return (2);
	}
	if (*letter == 'L')
	{
		validate_light(letter);
		return (3);
	}
}
