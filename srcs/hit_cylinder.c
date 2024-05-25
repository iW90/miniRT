/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:35:56 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/24 14:23:25 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	hit_cylinder(t_cylinder *cyl, t_ray *ray, t_range t, t_ray_hit *rec)
{
	t_hit		hit;
	t_vector	v;
	t_vector	v_origin_center;
	t_vector	pj_ori_center;
	t_quadratic	quad;

	hit = init_hit(cyl, ray, t, rec);
	v_origin_center = vector_diff(ray->origin, cyl->cap_bottom);
	pj_ori_center = vector_project(v_origin_center, cyl->axis);
	v = vector_project(ray->direction, cyl->axis);
	quad = init_quadratic(pj_ori_center, v, cyl->radius);
	if (quad.discr < 0)
		return (0);
	quad.root[0] = (-quad.b - sqrt(quad.discr)) / (2 * quad.a);
	quad.root[1] = (-quad.b + sqrt(quad.discr)) / (2 * quad.a);
	if (!body_or_cap(&hit, select_hit(quad.root, &hit, 0, 0)))
		return (0);
	update_hit_record(rec, rec->point, cyl->cap_bottom, cyl->axis);
	set_face_normal(rec, ray, &rec->normal);
	if (!body_or_cap(&hit, select_hit(quad.root, &hit, 0, 0)))
		return (0);
	return (1);
}
