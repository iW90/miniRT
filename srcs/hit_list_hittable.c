/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_list_hittable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:21:09 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/24 13:53:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	set_record(double *closest, t_ray_hit *tr, t_ray_hit *rec, int index)
{
	*closest = tr->t;
	*rec = *tr;
	rec->index = index;
	return (1);
}

int	hit_object(t_object *obj, t_ray *ray, t_range var, t_ray_hit *tr)
{
	if (obj->shape == SPHERE)
		return (hit_sphere(*(obj->sphere), ray, var, tr));
	else if (obj->shape == PLANE)
		return (hit_plane(*(obj->plane), ray, var, tr));
	else if (obj->shape == CYLINDER)
		return (hit_cylinder(obj->cyl, ray, var, tr));
	return (0);
}

int	trace_ray_hit(t_object *list, t_ray *ray, t_range t, t_ray_hit *rec)
{
	t_ray_hit	tr;
	int			hit_any;
	double		closest;
	t_range		variation;

	hit_any = 0;
	closest = t.max;
	while (list)
	{
		variation.min = t.min;
		variation.max = closest;
		if (hit_object(list, ray, variation, &tr))
			hit_any = set_record(&closest, &tr, rec, list->index);
		list = list->next;
	}
	return (hit_any);
}
