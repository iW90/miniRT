/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:01:15 by inwagner          #+#    #+#             */
/*   Updated: 2023/12/10 22:01:29 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	validate_obj(char	*letter)
{
	if (*letter == 's')
		validate_sphere(letter);
	if (*letter == 'p')
		validate_plane(letter);
	if (*letter == 'c')
		validate_cylinder(letter);
}
