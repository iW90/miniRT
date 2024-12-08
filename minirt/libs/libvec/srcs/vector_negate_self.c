/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_negate_self.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:28:23 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/18 11:58:47 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector	vector_negate_self(t_vector *vector)
{
	vector->x *= -1;
	vector->y *= -1;
	vector->z *= -1;
	return (*vector);
}
