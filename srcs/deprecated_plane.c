/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:13:19 by maalexan          #+#    #+#             */
/*   Updated: 2024/03/12 21:16:25 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	intersect_plane(t_ray r, t_plane *plane, float *t)
{
	t_vec3f	p0_l0;
	float	denom;

	p0_l0 = vec3f_sub(plane->coords, r.orig);
	denom = vec3f_dot(plane->norm_vector, r.dir);
	if (fabs(denom) > 1e-6)
	{
		*t = vec3f_dot(p0_l0, plane->norm_vector) / denom;
		return (*t >= 0);
	}
	return (FALSE);
}
