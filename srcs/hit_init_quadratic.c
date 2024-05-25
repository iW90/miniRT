/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_init_quadratic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:39:32 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/24 14:24:53 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_quadratic	init_quadratic(t_vector pj_ori_center, t_vector v, double radius)
{
	t_quadratic	quad;

	quad.a = vector_length_sqd(v);
	quad.b = 2 * vector_dot(pj_ori_center, v);
	quad.c = vector_length_sqd(pj_ori_center) - radius * radius;
	quad.discr = quad.b * quad.b - 4 * quad.a * quad.c;
	return (quad);
}
