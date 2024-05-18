/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:39:35 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/18 17:49:22 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minirt.h"

static double	clamp(double value, double min, double max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

static int	color_component_to_int(double component)
{
	int	value;

	value = (int)(component * 255.99);
	if (value > 255)
		return (255);
	if (value < 0)
		return (0);
	return (value);
}

static uint32_t	vec_to_rgb(t_vector color)
{
	int	r;
	int	g;
	int	b;

	color.x = clamp(color.x, 0.0, 1.0);
	color.y = clamp(color.y, 0.0, 1.0);
	color.z = clamp(color.z, 0.0, 1.0);
	r = color_component_to_int(color.x);
	g = color_component_to_int(color.y);
	b = color_component_to_int(color.z);
	return (r << 24 | g << 16 | b << 8 | 255);
}

static t_ray	ray_constructor(t_camera *cam, t_vector normal)
{
	t_ray		new_ray;
	t_vector	horiz_component;
	t_vector	verti_component;
	t_vector	viewport_point;
	t_vector	direction;

	horiz_component = vector_mult(cam->viewport.horizontal, normal.x);
	verti_component = vector_mult(cam->viewport.vertical, normal.y);
	viewport_point = vector_sum(\
			vector_sum(cam->viewport.lower_left_corner, horiz_component), \
			verti_component);
	direction = normalize(vector_diff(viewport_point, cam->origin));
	new_ray.origin = cam->origin;
	new_ray.direction = direction;
	return (new_ray);
}

void	render(void)
{
	t_vector	normal;
	t_vector	loop;
	t_ray		ray;
	t_light		point_light;
	uint32_t	rgb;

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
			rgb = vec_to_rgb(ray_color(ray, get_data()->objects, point_light));
			mlx_put_pixel(get_data()->mlx.image, loop.x, loop.y, rgb);
			loop.y++;
		}
		loop.x++;
	}
}
