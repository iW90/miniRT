/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersecs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:51:28 by maalexan          #+#    #+#             */
/*   Updated: 2024/03/23 20:24:50 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	intersect_plane(t_ray r, t_plane *plane, float *t)
{
	t_vec3f	p0_l0;
	float	denom;

	p0_l0 = vec3f_sub(plane->coords, r.orig);
	denom = vec3f_dot(plane->norm_vector, r.dir);
	if (fabs(denom) > EPSILON)
	{
		*t = vec3f_dot(p0_l0, plane->norm_vector) / denom;
		return (*t >= 0);
	}
	return (FALSE);
}

void	quadratic_calc(t_ray ray, t_vec3f center, float radius, t_vec3f *coefs)
{
	t_vec3f	to_center;
	float	radius_squared;

	radius_squared = radius * radius;
	to_center = vec3f_sub(ray.orig, center);
	coefs->x = vec3f_dot(ray.dir, ray.dir);
	coefs->y = 2.0 * vec3f_dot(ray.dir, to_center);
	coefs->z = vec3f_dot(to_center, to_center) - radius_squared;
}

t_bool	intersect_sphere(t_ray ray, t_sphere *sphere, float *t)
{
	float		t0;
	float		t1;
	t_vec3f		to_center;
	t_vec3f		coefs;

	quadratic_calc(ray, sphere->coords, sphere->diameter / 2.0f, &coefs);
	if (!solve_quadratic(coefs, &t0, &t1))
		return (FALSE);
	if (t0 < 0)
	{
		t0 = t1;
		if (t0 < 0)
			return (FALSE);
	}
	*t = t0;
	return (TRUE);
}

static t_bool	check_intersec(t_ray r, t_cylinder *c, float t, t_bool *cap)
{
	float	height;
	float	distance_squared;
	t_vec3f	intersect;
	t_vec3f	to_center;

	intersect = ray_point_at(r, t);
	height = intersect.y - c->coords.y;
	if (height >= 0 && height <= c->height)
	{
		*cap = FALSE;
		return (TRUE);
	}
	if (fabs(height) < EPSILON || fabs(height - c->height) < EPSILON)
	{
		to_center.x = intersect.x - c->coords.x;
		to_center.y = 0;
		to_center.z = intersect.z - c->coords.z;
		distance_squared = vec3f_dot(to_center, to_center);
		if (distance_squared <= (c->diameter / 2.0f) * (c->diameter / 2.0f))
		{
			*cap = TRUE;
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	intersect_cylinder(t_ray ray, t_cylinder *cylinder, float *t)
{
	float	t0;
	float	t1;
	t_vec3f	coefs;
	t_bool	is_cap;

	quadratic_calc(ray, cylinder->coords, cylinder->diameter / 2.0f, &coefs);
	if (solve_quadratic(coefs, &t0, &t1))
	{
		if (check_intersec(ray, cylinder, t0, &is_cap))
		{
			*t = t0;
			return (TRUE);
		}
		if (check_intersec(ray, cylinder, t1, &is_cap))
		{
			*t = t1;
			return (TRUE);
		}
	}
	return (FALSE);
}
