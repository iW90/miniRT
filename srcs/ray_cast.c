/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:14:37 by maalexan          #+#    #+#             */
/*   Updated: 2024/02/22 13:21:11 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Casts a ray into the scene and determines the color seen along that ray, 
** based on intersections with spheres.
** The color calculation takes into account ambient lighting and the color 
** of the intersected sphere.
**
** Parameters:
** - orig: The origin of the ray.
** - dir: The direction of the ray.
** - spheres: A linked list of spheres in the scene.
** - amb: The ambient lighting, defined by its intensity and color.
**
** Returns:
** - The color seen along the ray as a vector, where each component 
** represents the red, green, and blue color channels.
**
** The function iterates through the list of spheres, using the intersect 
** function to find the closest sphere (if any) that intersects with the ray. 
** If an intersection is found, the color of the sphere is scaled by the ambient 
** light intensity to calculate the hit color. This hit color is then combined 
** with the ambient light color to determine the final color seen in the 
** direction of the ray. If no intersection is found, the resulting color
** is solely determined by the ambient light.
*/
t_vec3f	cast_ray(t_vec3f orig, t_vec3f dir, t_sphere *spheres, t_ambient amb)
{
	float		t;
	float		closest_t;
	t_vec3f		hit_color;
	t_vec3f		ambient_color;
	t_sphere	*closest_sphere;

	hit_color = (t_vec3f){0};
	closest_t = INFINITY;
	closest_sphere = NULL;
	while (spheres)
	{
		t = INFINITY;
		if (intersect((t_ray){orig, dir}, spheres, &t) && t < closest_t)
		{
			closest_t = t;
			closest_sphere = spheres;
		}
		spheres = spheres->next;
	}
	if (closest_sphere)
		hit_color = vec3f_scale(closest_sphere->rgb, amb.ratio);
	ambient_color = vec3f_scale(amb.rgb, amb.ratio);
	return (vec3f_add(hit_color, ambient_color));
}
