/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_camera_on.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:47:23 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/24 13:53:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	convert_to_radians(double degrees)
{
	return (degrees * PI / 180.0);
}

static t_vector	calculate_corner(t_camera *camera, t_vector w)
{
	t_vector	half_horizontal;
	t_vector	half_vertical;
	t_vector	origin_minus_horizontal;
	t_vector	origin_minus_halves;
	t_vector	negated_horizontal;

	negated_horizontal = vector_negate_self(&camera->viewport.horizontal);
	half_horizontal = vector_div(negated_horizontal, 2);
	half_vertical = vector_div(camera->viewport.vertical, 2);
	origin_minus_horizontal = vector_diff(camera->origin, half_horizontal);
	origin_minus_halves = vector_diff(origin_minus_horizontal, half_vertical);
	return (vector_diff(origin_minus_halves, w));
}

void	camera_on(t_camera *camera)
{
	double		theta;
	double		h_cam;
	t_vector	w;
	t_vector	u;
	t_vector	v;

	if (vector_is_equal(camera->direction, vector_create(0, 1, 0)))
		camera->direction.z += 0.0001;
	else if (vector_is_equal(camera->direction, vector_create(0, -1, 0)))
		camera->direction.z += 0.0001;
	theta = convert_to_radians(camera->fov);
	h_cam = tan(theta / 2);
	camera->viewport.view_up = vector_create(0, 1, 0);
	camera->viewport.height = 1.175 * h_cam;
	camera->viewport.width = ASPECT_RATIO * camera->viewport.height;
	w = vector_unit(vector_negate_self(&camera->direction));
	u = vector_unit(vector_cross(camera->viewport.view_up, w));
	v = vector_cross(u, w);
	camera->viewport.horizontal = vector_mult(u, camera->viewport.width);
	camera->viewport.vertical = vector_mult(v, camera->viewport.height);
	camera->viewport.lower_left_corner = calculate_corner(camera, w);
}
