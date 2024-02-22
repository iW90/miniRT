/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:18:15 by maalexan          #+#    #+#             */
/*   Updated: 2024/02/22 13:21:20 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Solves a quadratic equation of the form ax^2 + bx + c = 0.
** The coefficients of the equation are passed as a vector, where
** coeffs.x represents 'a', coeffs.y represents 'b', and coeffs.z represents 'c'.
** The roots of the equation, if existants, are returned as pointers t0 and t1.
**
** Parameters:
** - coeffs: A vector containing the coefficients of the quadratic equation.
** - t0: A pointer to a float where the first root will be stored.
** - t1: A pointer to a float where the second root will be stored.
**
** Returns:
** - TRUE if the equation has real roots, FALSE otherwise.
**
** The function first calculates the discriminant to check if the roots are real.
** If real roots exist, it computes them using the quadratic formula. 
** The roots are then sorted to ensure t0 <= t1.
*/
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
