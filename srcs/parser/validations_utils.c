/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:06:57 by inwagner          #+#    #+#             */
/*   Updated: 2024/03/25 21:29:49 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	validate_space(char *line, int *i, int next)
{
	while (ft_isspace(line[*i]))
		i++;
	if ((next && !ft_isdigit(line[*i])) || \
		(!next && (line[*i] != '\n' || line[*i])))
		print_error(-2);
}

float	get_float_number(char *line, int *i, float min, float max)
{
	float	number;

	if (!ft_isdigit(line[*i]) && line[*i] != '.')
		print_error(-2);
	number = ft_atof(&line[*i]);
	while (ft_isdigit(line[*i]) || line[*i] == '.')
		i++;
	if (number < min || number > max)
		print_error(-2);
	return (number);
}

int	get_int_number(char *line, int *i, int min, int max)
{
	int	number;

	if (!ft_isdigit(line[*i]))
		print_error(-2);
	number = ft_atoi(&line[*i]);
	while (ft_isdigit(line[*i]))
		i++;
	if (number < min || number > max)
		print_error(-2);
	return (number);
}
