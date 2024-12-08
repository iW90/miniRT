/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:10:33 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/18 16:13:37 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector	normalize(t_vector vector)
{
	t_vector	result;
	double		length;

	length = vector_length(vector);
	if (length == 0)
		return (vector);
	result.x = vector.x / length;
	result.y = vector.y / length;
	result.z = vector.z / length;
	return (result);
}
