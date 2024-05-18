/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_div_self.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:28:01 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/18 16:13:54 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector	vector_div_self(t_vector *vector, double value)
{
	vector->x /= value;
	vector->y /= value;
	vector->z /= value;
	return (*vector);
}
