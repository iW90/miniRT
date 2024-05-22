/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:31:25 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/22 19:12:24 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minirt.h"

int	hit_plane(t_plane plane, t_ray *ray, t_range t, t_ray_hit *rec)
{
	double	v_distance;
	double	v_origin;
	double	temp;

	v_distance = vector_dot(plane.normal, ray->direction);
	if (fabs(v_distance) < 1e-8)
		return (0);
	v_origin = -(vector_dot(plane.normal, ray->origin)
			- vector_dot(plane.normal, plane.position));
	temp = v_origin / v_distance;
	if (temp > t.max || temp < t.min)
		return (0);
	rec->t = temp;
	rec->point = ray_at(*ray, rec->t);
	rec->normal = plane.normal;
	if (vector_dot(plane.normal, ray->direction) > 0.00001)
		vector_negate_self(&rec->normal);
	return (1);
}
