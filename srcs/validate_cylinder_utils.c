/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cylinder_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:09:54 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/26 10:16:58 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_cy_split(char **split)
{
	return (split[0] \
			&& split[1] \
			&& split[2] \
			&& split[3] \
			&& split[4] \
			&& !split[5]);
}

int	handle_invalid_split(char **split)
{
	free_split(split);
	return (0);
}

int	handle_invalid_cylinder(t_cylinder *cylinder, char **split)
{
	free(cylinder);
	return (handle_invalid_split(split));
}

int	parse_cylinder_properties(char **split, t_cylinder *cylinder)
{
	return (validate_cylinder_position(split[0], cylinder) \
		&& validate_cylinder_orientation(split[1], cylinder) \
		&& validate_cylinder_diameter(split[2], cylinder) \
		&& validate_cylinder_height(split[3], cylinder) \
		&& validate_color(split[4], &cylinder->material.color));
}

void	set_cylinder_properties(t_cylinder *cylinder)
{
	cylinder->material = default_material(cylinder->material.color);
	cylinder->cap_top = vector_sum(cylinder->center, \
									vector_mult(cylinder->axis, \
												cylinder->height / 2.0));
	cylinder->cap_bottom = vector_sum(cylinder->center, \
									vector_mult(\
											cylinder->axis, \
											-(cylinder->height / 2.0)));
}
