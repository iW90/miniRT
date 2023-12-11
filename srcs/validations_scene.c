/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:00:32 by inwagner          #+#    #+#             */
/*   Updated: 2023/12/10 22:22:20 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void validate_ambient()
{
	
}

void validate_camera()
{
	
}

void validate_light()
{
	
}

int	validate_acl(char	*letter)
{
	if (*letter == 'A')
	{
		validate_ambient(letter);
		return (1);
	}
	if (*letter == 'C')
	{
		validate_camera(letter);
		return (2);
	}
	if (*letter == 'L')
	{
		validate_light(letter);
		return (3);
	}
}
