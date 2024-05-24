/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:13:38 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/24 13:53:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_material	get_material(t_object *world, int index)
{
	t_material		material;

	while (world)
	{
		if (index == world->index && world->shape == PLANE)
			material = world->plane->material;
		else if (index == world->index && world->shape == SPHERE)
			material = world->sphere->material;
		else if (index == world->index && world->shape == CYLINDER)
			material = world->cyl->material;
		world = world->next;
	}
	return (material);
}

t_vector	ray_color(t_ray ray, t_object *world, t_light light)
{
	t_hit			hit;
	int				in_shadow;

	hit.t.min = 0;
	hit.t.max = HUGE_VAL;
	hit.ray = &ray;
	hit.rec = &(t_ray_hit){0};
	if (trace_ray_hit(world, hit.ray, hit.t, hit.rec))
	{
		in_shadow = is_shadowed(hit.rec->point, light, world, hit.rec->index);
		vector_negate_self(&hit.ray->direction);
		return (lighting(get_material(world, hit.rec->index), light,
				&hit, in_shadow));
	}
	return (vector_create(0, 0, 0));
}
