/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:18:15 by maalexan          #+#    #+#             */
/*   Updated: 2024/02/23 22:32:54 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Determines if a ray intersects with a given sphere 
** and calculates the intersection distance.
** Uses the analytical solution to the ray-sphere intersection problem.
**
** Parameters:
** - ray: The ray being cast, defined by an origin and a direction.
** - sphere: The sphere to test for intersection,
** defined by its center coordinates and diameter.
** - t: A pointer to a float where the distance from the ray origin
** to the intersection point will be stored.
**
** Returns:
** - TRUE if the ray intersects with the sphere, FALSE otherwise.
**
** The function first converts the sphere's diameter to a radius
** for the intersection calculation.
** It then computes the coefficients for the quadratic equation 
** that arises from plugging the ray equation into the sphere's equation.
** These coefficients are used in the solve_quadratic function to find 
** potential intersection points. The function ensures that the intersection
** point is the closest one in the direction of the ray and discards 
** intersections behind the ray origin.
*/
static inline float	radius_squared(const t_sphere *sphere)
{
	float	radius;

	radius = sphere->diameter / 2.0f;
	return (radius * radius);
}

t_bool	intersect_sphere(t_ray ray, void *object, float *t)
{
	float		t0;
	float		t1;
	t_sphere	*sphere;
	t_vec3f		to_center;
	t_vec3f		coeffs;

	sphere = (t_sphere *)object;
	to_center = vec3f_sub(ray.orig, sphere->coords);
	coeffs.x = vec3f_dot(ray.dir, ray.dir);
	coeffs.y = 2.0 * vec3f_dot(ray.dir, to_center);
	coeffs.z = vec3f_dot(to_center, to_center) - radius_squared(sphere);
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

/*
Gpt weirdness
t_bool	intersect_sphere_wrapper(t_ray ray, void *data, float *t)
{
	t_sphere *sphere;

	sphere = (t_sphere *)data;
    return (intersect_sphere(ray, sphere, t));
}
*/