/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:18:15 by maalexan          #+#    #+#             */
/*   Updated: 2024/02/22 11:45:23 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	solve_quadratic(t_vec3f coeffs, float *t0, float *t1)
{
	float	q;
	float	discriminant;
	float	temp;

	discriminant = coeffs.y * coeffs.y - 4 * coeffs.x * coeffs.z;
	if (discriminant < 0)
		return (FALSE);
	if (coeffs.y > 0)
		q = -0.5 * (coeffs.y + sqrt(discriminant));
	else
		q = -0.5 * (coeffs.y - sqrt(discriminant));
	*t0 = q / coeffs.x;
	*t1 = coeffs.z / q;
	if (*t0 > *t1) 
	{
		temp = *t0;
		*t0 = *t1;
		*t1 = temp;
	}
	return (TRUE);
}

t_bool	intersect(t_ray ray, t_sphere sphere, float *t)
{
	float	t0;
	float	t1;
	float	radius;
	t_vec3f	to_center;
	t_vec3f	coeffs;

	radius = sphere.diameter / 2.0f;
	to_center = vec3f_sub(ray.orig, sphere.coords);
	coeffs.x = vec3f_dot(ray.dir, ray.dir);
	coeffs.y = 2.0 * vec3f_dot(ray.dir, to_center);
	coeffs.z = vec3f_dot(to_center, to_center) - radius * radius;
	if (!solve_quadratic(coeffs, &t0, &t1))
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
