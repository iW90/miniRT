/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:13:49 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/24 13:53:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	is_valid_color(char *str)
{
	if (!str)
		return (0);
	return (ft_is_numeric_string(str) && ft_atoi(str) >= 0
		&& ft_atoi(str) <= 255);
}

int	validate_color(char *line, t_vector *color)
{
	char	**split;

	while (*line == ' ')
		line++;
	split = ft_split(line, ',');
	if (!is_valid_color(split[0]) || !is_valid_color(split[1])
		|| !is_valid_color(split[2]) || split[3])
	{
		free_split(split);
		return (0);
	}
	color->x = ft_atof(split[0]) / 255;
	color->y = ft_atof(split[1]) / 255;
	color->z = ft_atof(split[2]) / 255;
	free_split(split);
	return (1);
}
