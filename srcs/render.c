/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:23:33 by maalexan          #+#    #+#             */
/*   Updated: 2024/03/23 21:13:07 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	get_ray(float x_coord_on_viewplane, float y_coord_on_viewplane)
{
	t_ray	ray;
	t_vec3f	ray_dir;

	ray_dir.x = x_coord_on_viewplane;
	ray_dir.y = y_coord_on_viewplane;
	ray_dir.z = VIEW_PLANE_DIST_TO_CAM;
	ray_dir = vec3f_normalize(ray_dir);
	ray.orig = get_scene()->camera->coords;
	ray.dir = ray_dir;
	return (ray);
}

void	process_rays(float vp_height, float vp_width, t_intersect **inters)
{
	int		x;
	int		y;
	float	px_norm_x;
	float	px_norm_y;
	t_ray	ray;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			px_norm_x = (x / (float)(WIN_WIDTH - 1)) * 2.0f - 1.0f;
			px_norm_y = 1.0f - (y / (float)(WIN_HEIGHT - 1)) * 2.0f;
			ray = get_ray(px_norm_x * vp_width, px_norm_y * vp_height);
			inters[y * WIN_WIDTH + x] = cast_ray(ray, get_scene()->objects);
			x++;
		}
		y++;
	}
}

void	render_scene(t_scene *scene)
{
	float		aspect_ratio;
	float		view_plane_height;
	float		view_plane_width;
	t_camera	*cam;

	ft_memset(scene->fb.intersections, 0, sizeof(scene->fb.intersections));
	cam = get_scene()->camera;
	aspect_ratio = (float)WIN_WIDTH / (float)WIN_HEIGHT;
	view_plane_height = 2.0f * tan((cam->horiz_fov * M_PI / 180.0f) / 2.0f);
	view_plane_width = view_plane_height * aspect_ratio;
	process_rays(view_plane_height, view_plane_width, scene->fb.intersections);
}
