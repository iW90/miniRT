/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_set_normal_face.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:27:12 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/22 19:12:24 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minirt.h"

void	set_face_normal(t_ray_hit *rec, t_ray *ray, t_vector *out_normal)
{
	rec->front_face = vector_dot(ray->direction, *out_normal) < 0;
	if (rec->front_face)
		rec->normal = *out_normal;
	else
		rec->normal = vector_negate_self(out_normal);
}
