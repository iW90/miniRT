/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:00:32 by inwagner          #+#    #+#             */
/*   Updated: 2024/03/28 14:18:55 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	validate_ambient(char *line)
{
	t_ambient	*ambient;
	int			i;

	i = 1;
	if (get_scene()->ambient)
		print_error(-2);
	ambient = malloc(sizeof(t_ambient));
	if (!ambient)
		print_error(12);
	get_scene()->ambient = ambient;
	validate_space(line, &i, TRUE);
	ambient->ratio = get_float_number(line, &i, 0.0, 1.0);
	validate_space(line, &i, TRUE);
	ambient->rgb = get_rgb(line, &i);
	validate_space(line, &i, FALSE);
}

void	validate_camera(char *line)
{
	t_camera	*camera;
	int			i;

	i = 1;
	if (get_scene()->camera)
		print_error(-2);
	camera = malloc(sizeof(t_camera));
	if (!camera)
		print_error(12);
	get_scene()->camera = camera;
	validate_space(line, &i, TRUE);
	printf("camin\n");
	camera->coords = get_coords(line, &i, FALSE);
	printf("camcords\n");
	validate_space(line, &i, TRUE);
	camera->norm_vector = get_coords(line, &i, TRUE);
	validate_space(line, &i, TRUE);
	camera->horiz_fov = get_int_number(line, &i, 0, 180);
	validate_space(line, &i, FALSE);
}

void	validate_light(char *line)
{
	t_light	*light;
	int		i;
	printf("lightsin\n");
	i = 1;
	if (get_scene()->light)
		print_error(-2);
	light = malloc(sizeof(t_light));
	if (!light)
		print_error(12);
	get_scene()->light = light;
	validate_space(line, &i, TRUE);
	light->coords = get_coords(line, &i, FALSE);
	validate_space(line, &i, TRUE);
	light->bright_ratio = get_float_number(line, &i, 0.0, 1.0);
	validate_space(line, &i, TRUE);
	light->rgb = get_rgb(line, &i);
	validate_space(line, &i, FALSE);
	printf("lightsout\n");
}
