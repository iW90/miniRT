/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:09:57 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/26 09:51:58 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "../incl/validate.h"

static int	validate_sphere_position(char *line, t_sphere *sphere)
{
	char	**split;

	split = ft_split(line, ',');
	if (!ft_isstrnum(split[0]) || !ft_isstrnum(split[1])
		|| !ft_isstrnum(split[2]))
	{
		free_split(split);
		return (0);
	}
	sphere->center.x = ft_atof(split[0]);
	sphere->center.y = ft_atof(split[1]);
	sphere->center.z = ft_atof(split[2]);
	free_split(split);
	return (1);
}

static int	validate_sphere_diameter(char *line, t_sphere *sphere)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!ft_isstrnum(split[0]) || split[1] != NULL
		|| ft_atof(split[0]) < 0)
	{
		free_split(split);
		return (0);
	}
	sphere->radius = ft_atof(split[0]) / 2;
	free_split(split);
	return (1);
}

int	validate_sphere(char *line)
{
	char		**split;
	t_sphere	*sphere;

	sphere = ft_calloc(1, sizeof(t_sphere));
	while (*line++ == ' ')
		;
	split = ft_split(line, ' ');
	if (!split[0] || !split[1] || !split[2] || split[3] != NULL)
		return (free_split(split));
	if (!validate_sphere_position(split[0], sphere)
		|| !validate_sphere_diameter(split[1], sphere)
		|| !validate_color(split[2], &sphere->material.color))
	{
		free(sphere);
		return (free_split(split));
	}
	sphere->material = default_material(sphere->material.color);
	add_object(SPHERE, sphere);
	free_split(split);
	return (1);
}
