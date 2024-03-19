/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:14:37 by maalexan          #+#    #+#             */
/*   Updated: 2024/03/19 16:19:26 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3f	ray_point_at(t_ray ray, float t)
{
	t_vec3f	point;

	point.x = ray.orig.x + t * ray.dir.x;
	point.y = ray.orig.y + t * ray.dir.y;
	point.z = ray.orig.z + t * ray.dir.z;
	return (point);
}

static t_bool	ray_hit(t_ray r, t_object *object, float *t)
{
	if (object->type == SPHERE)
		return (intersect_sphere(r, object->data.sphere, t));
	else if (object->type == PLANE)
		return (intersect_plane(r, object->data.plane, t));
	else if (object->type == CYLINDER)
		return (intersect_cylinder(r, object->data.cylinder, t));
	return (FALSE);
}

t_intersect	*cast_ray(t_ray ray, t_object *objects)
{
	t_intersect	*head;
	float		t;

	head = NULL;
	while (objects)
	{
		if (ray_hit(ray, objects, &t) && t > 0)
			add_intersection(&head, ray, objects, t);
		objects = objects->next;
	}
	return (head);
}

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
** If intersection is found, the color of the sphere is scaled by the ambient
** light intensity to calculate the hit color. This hit color is then combined
** with the ambient light color to determine the final color seen in the 
** direction of the ray. If no intersection is found, the resulting color
** is solely determined by the ambient light.
*/