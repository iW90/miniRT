/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:38:43 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/24 14:23:56 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit	init_hit(t_cylinder *cyl, t_ray *ray, t_range t, t_ray_hit *rec)
{
	t_hit	hit;

	hit.cyl = cyl;
	hit.ray = ray;
	hit.t = t;
	hit.rec = rec;
	return (hit);
}
