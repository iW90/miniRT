/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:02:42 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/26 10:21:00 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_cylinder_position(char *line, t_cylinder *cylinder)
{
	char	**split;

	split = ft_split(line, ',');
	if (!ft_isstrnum(split[0]) || !ft_isstrnum(split[1])
		|| !ft_isstrnum(split[2]))
	{
		free_split(split);
		return (0);
	}
	cylinder->center.x = ft_atof(split[0]);
	cylinder->center.y = ft_atof(split[1]);
	cylinder->center.z = ft_atof(split[2]);
	free_split(split);
	return (1);
}

int	validate_cylinder_diameter(char *line, t_cylinder *cylinder)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!ft_isstrnum(split[0]) || split[1] != NULL
		|| ft_atof(split[0]) < 0)
	{
		free_split(split);
		return (0);
	}
	cylinder->radius = ft_atof(split[0]) / 2;
	free_split(split);
	return (1);
}

int	validate_cylinder_height(char *line, t_cylinder *cylinder)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!ft_isstrnum(split[0]) || split[1] != NULL
		|| ft_atof(split[0]) < 0)
	{
		free_split(split);
		return (0);
	}
	cylinder->height = ft_atof(split[0]);
	free_split(split);
	return (1);
}

int	validate_cylinder_orientation(char *line, t_cylinder *cylinder)
{
	char	**split;

	split = ft_split(line, ',');
	if (!validate_orientation(split[0], split[1], split[2]))
	{
		free_split(split);
		return (0);
	}
	cylinder->axis.x = ft_atof(split[0]);
	cylinder->axis.y = ft_atof(split[1]);
	cylinder->axis.z = ft_atof(split[2]);
	free_split(split);
	return (1);
}

int	validate_cylinder(char *line)
{
	char		**split;
	t_cylinder	*cylinder;

	while (*line++ == ' ')
		;
	split = ft_split(line, ' ');
	if (!validate_cy_split(split))
		return (handle_invalid_split(split));
	cylinder = ft_calloc(1, sizeof(t_cylinder));
	if (!cylinder)
		return (handle_invalid_split(split));
	if (!parse_cylinder_properties(split, cylinder))
		return (handle_invalid_cylinder(cylinder, split));
	set_cylinder_properties(cylinder);
	add_object(CYLINDER, cylinder);
	free_split(split);
	return (1);
}
