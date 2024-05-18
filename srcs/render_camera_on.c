/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_camera_on.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:47:23 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/18 17:05:56 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minirt.h"

static double	convert_to_radians(double degrees)
{
	return (degrees * PI / 180.0);
}

static void	adjust_camera_direction(t_camera *cam)
{
	if (vector_is_equal(cam->direction, vector_create(0, 1, 0)) || \
		vector_is_equal(cam->direction, vector_create(0, -1, 0)))
	{
		cam->direction.z += 0.0001;
	}
}

static void	calculate_viewport_vectors(t_camera *cam)
{
	t_vector	w;
	t_vector	u;
	t_vector	v;

	w = vector_unit(vector_negate_self(&cam->direction));
	u = vector_unit(vector_cross(cam->viewport.view_up, w));
	v = vector_cross(u, w);
	cam->viewport.horizontal = vector_mult(u, cam->viewport.width);
	cam->viewport.vertical = vector_mult(v, cam->viewport.height);
}

static void	set_lower_left_corner(t_camera *cam)
{
	t_vector	half_horizontal;
	t_vector	half_vertical;
	t_vector	origin_minus_horiz;
	t_vector	origin_minus_both;
	t_vector	dir_unit;

	half_horizontal = vector_div(cam->viewport.horizontal, 2);
	half_vertical = vector_div(cam->viewport.vertical, 2);
	origin_minus_horiz = vector_diff(cam->origin, half_horizontal);
	origin_minus_both = vector_diff(origin_minus_horiz, half_vertical);
	dir_unit = vector_unit(vector_negate_self(&cam->direction));
	cam->viewport.lower_left_corner = vector_diff(origin_minus_both, dir_unit);
}

void	camera_on(t_camera *camera)
{
	double	theta;
	double	h_cam;

	adjust_camera_direction(camera);
	theta = convert_to_radians(camera->fov);
	h_cam = tan(theta / 2);
	camera->viewport.view_up = vector_create(0, 1, 0);
	camera->viewport.height = 1.175 * h_cam;
	camera->viewport.width = ASPECT_RATIO * camera->viewport.height;
	calculate_viewport_vectors(camera);
	set_lower_left_corner(camera);
}
