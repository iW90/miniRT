/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:24:00 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/24 14:38:29 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_root(t_range t, t_vector delta, double sqrt_d, double *root)
{
	if (t.min > *root || *root > t.max)
	{
		*root = (-delta.y + sqrt_d) / delta.x;
		if (t.min > *root || *root > t.max)
			return (0);
	}
	return (1);
}

static t_vector	set_out_normal(t_ray_hit *rec, t_sphere sphere)
{
	t_vector	new;

	new = vector_div(vector_diff(rec->point, sphere.center), sphere.radius);
	return (new);
}

int	hit_sphere(t_sphere sphere, t_ray *ray, t_range t, t_ray_hit *rec)
{
	t_vector	distance;
	t_vector	delta;
	t_vector	out_normal;
	double		discriminant;
	double		root;

	distance = vector_diff(ray->origin, sphere.center);
	delta.x = vector_length_sqd(ray->direction);
	delta.y = vector_dot(distance, ray->direction);
	delta.z = vector_length_sqd(distance) - sphere.radius * sphere.radius;
	discriminant = delta.y * delta.y - (delta.x * delta.z);
	if (discriminant < 0)
		return (0);
	root = (-delta.y - sqrt(discriminant)) / delta.x;
	if (!check_root(t, delta, sqrt(discriminant), &root))
		return (0);
	rec->t = root;
	rec->point = ray_at(*ray, rec->t);
	out_normal = set_out_normal(rec, sphere);
	set_face_normal(rec, ray, &out_normal);
	return (1);
}
