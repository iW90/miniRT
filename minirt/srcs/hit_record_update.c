/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record_update.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:40:39 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/24 15:26:21 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector	calc_projec(t_vector point, t_vector cap_bottom, t_vector axis)
{
	t_vector	diff;
	double		projection_length;

	diff = vector_diff(point, cap_bottom);
	projection_length = vector_dot(diff, axis);
	return (vector_mult(axis, projection_length));
}

static t_vector	calc_normal(t_vector point, t_vector cap_bottom, t_vector axis)
{
	t_vector	projection;
	t_vector	projected_point;

	projection = calc_projec(point, cap_bottom, axis);
	projected_point = vector_sum(cap_bottom, projection);
	return (vector_unit(vector_diff(point, projected_point)));
}

void	update_hit_record(\
		t_ray_hit *rec, t_vector point, t_vector cap_bottom, t_vector axis)
{
	rec->normal = calc_normal(point, cap_bottom, axis);
}
