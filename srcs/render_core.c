/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:39:35 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/24 13:53:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	clamp(double value, double min, double max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

uint32_t	color_create_rgb(t_vector *color)
{
	int	r;
	int	g;
	int	b;

	color->x = clamp(color->x, 0.0, 1.0);
	color->y = clamp(color->y, 0.0, 1.0);
	color->z = clamp(color->z, 0.0, 1.0);
	r = (int)(color->x * 255.99);
	g = (int)(color->y * 255.99);
	b = (int)(color->z * 255.99);
	r = clamp(r, 0, 255);
	g = clamp(g, 0, 255);
	b = clamp(b, 0, 255);
	return (r << 24 | g << 16 | b << 8 | 255);
}

static t_vector	calculate_ray_direction(t_camera *camera, t_vector normal)
{
	t_vector	horizontal_offset;
	t_vector	vertical_offset;
	t_vector	lower_left_with_horizontal;
	t_vector	lower_left_with_horizontal_and_vertical;
	t_vector	direction;

	horizontal_offset = vector_mult(camera->viewport.horizontal, normal.x);
	vertical_offset = vector_mult(camera->viewport.vertical, normal.y);
	lower_left_with_horizontal = \
		vector_sum(camera->viewport.lower_left_corner, horizontal_offset);
	lower_left_with_horizontal_and_vertical = \
		vector_sum(lower_left_with_horizontal, vertical_offset);
	direction = \
		vector_diff(lower_left_with_horizontal_and_vertical, camera->origin);
	return (normalize(direction));
}

static t_ray	ray_constructor(t_camera *camera, t_vector normal)
{
	t_ray	new_ray;

	new_ray.origin = camera->origin;
	new_ray.direction = calculate_ray_direction(camera, normal);
	return (new_ray);
}

void	render(void)
{
	t_vector	normal;
	t_vector	loop;
	t_ray		ray;
	t_vector	color;
	t_light		point_light;

	camera_on(&get_data()->camera);
	point_light = get_data()->light;
	point_light.color = vector_create(1, 1, 1);
	loop.x = 0;
	while (loop.x < WIDTH)
	{
		loop.y = 0;
		while (loop.y < HEIGHT)
		{
			normal.x = (double)loop.x / (WIDTH - 1);
			normal.y = (double)loop.y / (HEIGHT - 1);
			ray = ray_constructor(&get_data()->camera, normal);
			color = ray_color(ray, get_data()->objects, point_light);
			mlx_put_pixel(get_data()->mlx.image, loop.x, loop.y,
				color_create_rgb(&color));
			loop.y++;
		}
		loop.x++;
	}
}
