/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:08:08 by maalexan          #+#    #+#             */
/*   Updated: 2024/03/19 16:17:29 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec3f	calculate_cylinder_normal(t_cylinder *cylinder, t_vec3f point)
{
	float	height;
	t_vec3f	to_center;

	height = point.y - cylinder->coords.y;
	if (fabs(height) < EPSILON)
		return ((t_vec3f){0, -1, 0});
	else if (fabs(height - cylinder->height) < EPSILON)
		return ((t_vec3f){0, 1, 0});
	to_center.x = point.x - cylinder->coords.x;
	to_center.y = 0;
	to_center.z = point.z - cylinder->coords.z;
	return (vec3f_normalize(to_center));
}

static t_vec3f	check_object_normal(t_object *object, t_vec3f point)
{
	t_vec3f	normal;

	normal = (t_vec3f){0};
	if (object->type == SPHERE)
	{
		normal = vec3f_sub(point, object->data.sphere->coords);
		normal = vec3f_normalize(normal);
	}
	if (object->type == PLANE)
		normal = object->data.plane->norm_vector;
	if (object->type == CYLINDER)
		normal = calculate_cylinder_normal(object->data.cylinder, point);
	return (normal);
}

static void	insert_sorted(t_intersect **head, t_intersect *new)
{
	t_intersect	**current;

	current = head;
	while (*current && (*current)->distance < new->distance)
		current = &((*current)->next);
	new->next = *current;
	*current = new;
}

void	add_intersection(t_intersect **head, t_ray ray, t_object *obj, float t)
{
	t_intersect	*new;

	new = malloc(sizeof(t_intersect));
	if (!new)
		exit_program(OUT_OF_MEMORY);
	*new = (t_intersect){0};
	new->distance = t;
	new->point = ray_point_at(ray, t);
	new->normal = check_object_normal(obj, new->point);
	new->object = obj;
	insert_sorted(head, new);
}
