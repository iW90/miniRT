/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_list_hittable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:21:09 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/22 17:47:37 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minirt.h"

int	set_record(double *closest, t_hit_record *tr, t_hit_record *rec, int index)
{
	*closest = tr->t;
	*rec = *tr;
	rec->index = index;
	return (1);
}

int	hit_object(t_object *obj, t_ray *ray, t_variation var, t_hit_record *tr)
{
	if (obj->shape == SPHERE)
		return (hit_sphere(*(obj->sphere), ray, var, tr));
	else if (obj->shape == PLANE)
		return (hit_plane(*(obj->plane), ray, var, tr));
	else if (obj->shape == CYLINDER)
		return (hit_cylinder(obj->cyl, ray, var, tr));
	return (0);
}

int	trace_ray_hit(t_object *list, t_ray *ray, t_variation t, t_hit_record *rec)
{
	t_hit_record	tr;
	int				hit_any;
	double			closest;
	t_variation		variation;

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
