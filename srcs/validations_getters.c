/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_getters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:07:23 by inwagner          #+#    #+#             */
/*   Updated: 2023/12/12 21:36:52 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	get_rgb_number(char *line, int *i, int color)
{
	int	number;

	number = ft_atoi(&line[*i]);
	if (number < 0 || number > 255)
		print_error(-2);
	while (ft_isdigit(line[*i]))
		i++;
	if (color < 2 && line[*i] != ',')
		print_error(-2);
	return (number);
}

void	get_rgb(char *line, int *i, int *rgb)
{
	rgb[R] = get_rgb_number(line, i, R);
	rgb[G] = get_rgb_number(line, i, G);
	rgb[B] = get_rgb_number(line, i, B);
}

static double	get_xyz_number(char *line, int *i, int axis, int vts)
{
	double	number;

	number = ft_atof(&line[*i]);
	if (vts && (number < -1.0 || number > 1.0))
		print_error(-2);
	while (ft_isdigit(line[*i]))
		i++;
	if (axis < 2 && line[*i] != ',')
		print_error(-2);
	return (number);
}

void	get_xyz(char *line, int *i, double *xyz, int vts)
{
	xyz[X] = get_xyz_number(line, i, X, vts);
	xyz[Y] = get_xyz_number(line, i, Y, vts);
	xyz[Z] = get_xyz_number(line, i, Z, vts);
}
