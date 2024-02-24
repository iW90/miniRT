/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:25:35 by maalexan          #+#    #+#             */
/*   Updated: 2024/02/23 15:33:13 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	float_to_int_rgb(t_vec3f rgb)
{
	int		ir;
	int		ig;
	int		ib;
	t_vec3f	clamped;

	clamped.x = fmax(0.0, fmin(1.0, rgb.x));
	clamped.y = fmax(0.0, fmin(1.0, rgb.y));
	clamped.z = fmax(0.0, fmin(1.0, rgb.z));
	ir = (int)(255.99 * clamped.x);
	ig = (int)(255.99 * clamped.y);
	ib = (int)(255.99 * clamped.z);
	return ((ir << 16) | (ig << 8) | ib);
}
