/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_default_material.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:35:28 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/18 11:06:32 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minirt.h"

t_material	default_material(t_vector color)
{
	t_material	m;

	m.ambient = get_data()->ambient.ratio;
	m.diffuse = 0.9;
	m.specular = 0;
	m.shininess = 200;
	m.color = vector_create(color.x, color.y, color.z);
	return (m);
}