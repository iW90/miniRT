/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:35:15 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/25 14:05:02 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	validate_camera_fov(char *line)
{
	long double		fov;

	fov = ft_atof(line);
	if (fov < 0 || fov > 180 || errno == ERANGE)
		return (0);
	get_data()->camera.fov = fov;
	return (1);
}

static int	validate_camera_orientation(char *line)
{
	t_data	*data;
	char	**split;

	data = get_data();
	split = ft_split(line, ',');
	if (!validate_orientation(split[0], split[1], split[2]))
	{
		free_split(split);
		return (0);
	}
	data->camera.direction.x = ft_atof(split[0]);
	data->camera.direction.y = ft_atof(split[1]);
	data->camera.direction.z = ft_atof(split[2]);
	free_split(split);
	return (1);
}

static int	validate_camera_position(char *line)
{
	t_data	*data;
	char	**split;

	data = get_data();
	split = ft_split(line, ',');
	if (!ft_isstrnum(split[0]) || !ft_isstrnum(split[1])
		|| !ft_isstrnum(split[2]))
	{
		free_split(split);
		return (0);
	}
	data->camera.origin.x = ft_atof(split[0]);
	data->camera.origin.y = ft_atof(split[1]);
	data->camera.origin.z = ft_atof(split[2]);
	free_split(split);
	return (1);
}

int	validate_camera(char *line)
{
	char	**split;

	line++;
	while (*line == ' ')
		line++;
	split = ft_split(line, ' ');
	if (!split[0] || !split[1] || !split[2] || split[3] != NULL)
	{
		free_split(split);
		return (0);
	}
	if (!validate_camera_position(split[0])
		|| !validate_camera_orientation(split[1])
		|| !validate_camera_fov(split[2]))
	{
		free_split(split);
		return (0);
	}
	free_split(split);
	return (1);
}
