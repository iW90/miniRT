/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:52:24 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/22 19:23:01 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minirt.h"

static int	init_shadow_variables(double *closest, t_range t)
{
	*closest = t.max;
	return (0);
}

static void	set_t_var(t_range *t_var, t_range t, double closest)
{
	t_var->min = t.min;
	t_var->max = closest;
}

int	trace_shadow_hit(t_object *list, t_range t, t_hit *h, int ignore_index)
{
	t_ray_hit	tr;
	int			hit_any;
	double		close;
	t_range		variation;

	hit_any = init_shadow_variables(&close, t);
	while (list)
	{
		if (list->index != ignore_index)
		{
			set_t_var(&variation, t, close);
			if (hit_object(list, h->ray, variation, &tr))
				hit_any = set_record(&close, &tr, h->rec, list->index);
		}
		list = list->next;
	}
	return (hit_any);
}

int	is_shadowed(t_vector point, t_light light, t_object *world, int ignored)
{
	t_vector	shadow_vector;
	t_ray		shadow_ray;
	t_ray_hit	temp_record;
	t_range		var;
	t_hit		hit;

	var.min = 0;
	var.max = HUGE_VAL;
	shadow_vector = vector_diff(light.origin, point);
	shadow_ray.origin = vector_sum(point,
			vector_mult(vector_unit(shadow_vector), 1e-4));
	shadow_ray.direction = normalize(shadow_vector);
	temp_record.ignore_index = ignored;
	hit.rec = &temp_record;
	hit.ray = &shadow_ray;
	if (trace_shadow_hit(world, var, &hit, ignored))
	{
		if (temp_record.t < vector_length(shadow_vector))
			return (1);
	}
	return (0);
}
