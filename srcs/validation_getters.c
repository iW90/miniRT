/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_getters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:07:23 by inwagner          #+#    #+#             */
/*   Updated: 2023/12/12 20:21:03 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


double	get_double_number(char *line, int *i, double min, double max)
{
	double	number;

	if (!ft_isdigit(line[i]) && line[i] != '.')
		print_error(-2);
	number = ft_atof(line[i]);
	while (ft_isdigit(line[i]) || line[i] == '.')
		i++;
	if (number < min || number > max)
		print_error(-2);
	return (number);
}

int	get_int_number(char *line, int *i, int min, int max)
{
	int	number;

	if (!ft_isdigit(line[i]))
		print_error(-2);
	number = ft_atoi(line[i]);
	while (ft_isdigit(line[i]))
		i++;
	if (number < min || number > max)
		print_error(-2);
	return (number);
}
