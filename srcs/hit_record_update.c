/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record_update.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:40:39 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/18 10:42:50 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minirt.h"

void	update_hit_record(t_hit_record *rec, t_vector point,
	t_vector cap_bottom, t_vector axis)
{
	rec->normal = vector_unit(vector_diff(point,
				vector_sum(cap_bottom, vector_mult(axis,
						vector_dot(vector_diff(point, cap_bottom), axis)))));
}