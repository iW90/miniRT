/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_init_bhaskara.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:39:32 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/18 10:41:58 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minirt.h"

t_bhaskara	init_bhaskara(t_vector pj_ori_center,
	t_vector v, double radius)
{
	t_bhaskara	bhaskara;

	bhaskara.a = vector_length_sqd(v);
	bhaskara.b = 2 * vector_dot(pj_ori_center, v);
	bhaskara.c = vector_length_sqd(pj_ori_center) - radius * radius;
	bhaskara.discr = bhaskara.b * bhaskara.b - 4 * bhaskara.a * bhaskara.c;
	return (bhaskara);
}