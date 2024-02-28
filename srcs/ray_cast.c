/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:14:37 by maalexan          #+#    #+#             */
/*   Updated: 2024/02/27 21:41:09 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3f	ray_point_at(t_ray ray, float t)
{
	t_vec3f point;

	point.x = ray.orig.x + t * ray.dir.x;
	point.y = ray.orig.y + t * ray.dir.y;
	point.z = ray.orig.z + t * ray.dir.z;
	return (point);
}

t_vec3f	object_normal_at(t_object *object, t_vec3f point)
{
	t_vec3f	normal;

	if (object->type == SPHERE )
	{
			normal = vec3f_sub(point, object->data.sphere->coords); // point - sphere center
			normal = vec3f_normalize(normal); // Normalize the vector
	}
	if (object->type == PLANE)
		normal = object->data.plane->norm_vector;  // The normal vector is constant for a plane
	return (normal);
}

static t_bool	ray_hit(t_ray r, t_object *object, float *t) 
{
	if (object->type == SPHERE)
		return (intersect_sphere(r, object->data.sphere, t));
	return (FALSE);
}

void	insert_intersection_sorted(t_intersect **head, t_intersect *new_intersection)
{
	t_intersect	**current;

	current = head;
	while (*current && (*current)->distance < new_intersection->distance)
		current = &((*current)->next);
	new_intersection->next = *current;
	*current = new_intersection;
}

void	add_intersection(t_intersect **head, t_ray ray, t_object *object, float t)
{
	t_intersect	*new_intersection;

	new_intersection = malloc(sizeof(t_intersect));
	if (!new_intersection)
		exit_program(OUT_OF_MEMORY);
	*new_intersection = (t_intersect){0};
	new_intersection->distance = t;
	new_intersection->point = ray_point_at(ray, t);
	new_intersection->normal = object_normal_at(object, new_intersection->point);
	new_intersection->object = object;
	insert_intersection_sorted(head, new_intersection);
}

t_intersect *cast_ray(t_ray ray, t_object *objects)
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
** If an intersection is found, the color of the sphere is scaled by the ambient 
** light intensity to calculate the hit color. This hit color is then combined 
** with the ambient light color to determine the final color seen in the 
** direction of the ray. If no intersection is found, the resulting color
** is solely determined by the ambient light.

t_vec3f	cast_ray(t_ray r, t_object *objects, t_ambient amb)
{
	float		t;
	float		closest_t;
	t_vec3f		hit_color;
	t_vec3f		ambient_color;
	t_sphere	*closest_sphere;

	hit_color = (t_vec3f){0};
	closest_t = INFINITY;
	closest_sphere = NULL;
	while (objects)
	{
		t = INFINITY;
		if (intersect(r, spheres, &t) && t < closest_t)
		{
			closest_t = t;
			closest_sphere = spheres;
		}
		objects = objects->next;
	}
	if (closest_sphere)
		hit_color = vec3f_scale(closest_sphere->rgb, amb.ratio);
	ambient_color = vec3f_scale(amb.rgb, amb.ratio);
	return (vec3f_add(hit_color, ambient_color));
}

	if (object->type == CYLINDER)
	{
		// Vector from cylinder's base center to the intersection point
		t_vec3f to_point = vec3f_sub(intersection_point, object->data.cylinder->base_center);
		
		// Project to_point onto the cylinder's axis to find the closest point on the axis
		float projection_length = vec3f_dot(to_point, object->data.cylinder->axis);
		t_vec3f closest_point_on_axis = vec3f_scale(object->data.cylinder->axis, projection_length);
		
		// The normal is the vector from the closest point on the axis to the intersection point
		normal = vec3f_sub(to_point, closest_point_on_axis);
		normal = vec3f_normalize(normal);  // Make sure the normal is a unit vector
	}


*/