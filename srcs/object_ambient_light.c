/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_ambient_light.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:17:48 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/24 13:53:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_ambient_light(void)
{
	t_ambient	*ambient_light;
	t_object	*object;

	ambient_light = &get_data()->ambient;
	object = get_data()->objects;
	while (object)
	{
		if (object->shape == PLANE)
			object->plane->material.ambient = ambient_light->ratio;
		else if (object->shape == SPHERE)
			object->sphere->material.ambient = ambient_light->ratio;
		else if (object->shape == CYLINDER)
			object->cyl->material.ambient = ambient_light->ratio;
		object = object->next;
	}
}
