/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:22:28 by maalexan          #+#    #+#             */
/*   Updated: 2024/03/12 21:50:30 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	intersect_cylinder(t_ray r, t_cylinder *cylinder, float *t)
{
	// Step 1: Solve for intersection with the curved surface (similar to sphere but with cylinder equation)
	// This involves solving a quadratic equation derived from substituting the ray equation into the cylinder's equation

	// Step 2: Check intersections with the end caps
	// This can be done by treating the caps as planes and checking if the intersection points are within the cylinder's radius

	// Return TRUE if there's an intersection, and update 't' with the closest intersection distance
	return FALSE;  // Return FALSE if no intersection is found
}


t_bool intersect_cylinder_curved_surface(t_ray ray, t_cylinder *cylinder, float *t)
{
    t_vec3f to_center = vec3f_sub(ray.orig, cylinder->coords);  // Adjust if cylinder's base center isn't at the origin
    float a = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z;
    float b = 2.0 * (ray.orig.x * ray.dir.x + ray.orig.z * ray.dir.z);
    float c = to_center.x * to_center.x + to_center.z * to_center.z - radius_squared(cylinder);



	float	t0;
	float	t1;
	t_vec3f	to_center;
	t_vec3f	coeffs;

	to_center = vec3f_sub(ray.orig, cylinder->coords);
	coeffs.x = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z;
	coeffs.y = 2.0 * (ray.orig.x * ray.dir.x + ray.orig.z * ray.dir.z);
	coeffs.z = to_center.x * to_center.x + to_center.z * to_center.z - radius_squared(cylinder);
	if (!solve_quadratic(coeffs, &t0, &t1))
        return FALSE;

    // Now, check the y-component to ensure the intersection points are within the cylinder's height
    // This involves calculating y for t0 and t1 and checking if it's within [cylinder->base, cylinder->base + cylinder->height]
    
    // If an intersection is within bounds, set *t to the closest valid intersection distance and return TRUE
    // Otherwise, return FALSE
}
