/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_object.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:01:15 by inwagner          #+#    #+#             */
/*   Updated: 2023/12/12 18:25:39 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	validate_sphere()
{
	
}

void	validate_plane()
{
	
}

void	validate_cylinder()
{
	
}

void	validate_obj(char *letter)
{
	if (*letter == 's')
		validate_sphere(letter);
	if (*letter == 'p')
		validate_plane(letter);
	if (*letter == 'c')
		validate_cylinder(letter);
}
