/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:25:31 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/18 11:07:00 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minirt.h"

t_vector	ray_at(t_ray ray, double t)
{
	t_vector	point3;

	point3 = vector_sum(ray.origin, vector_mult(ray.direction, t));
	return (point3);
}
