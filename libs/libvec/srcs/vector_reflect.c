/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reflect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:28:32 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/18 16:14:20 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector	vector_reflect(t_vector v, t_vector n)
{
	t_vector		result;
	const double	dot_product = 2 * (v.x * n.x + v.y * n.y + v.z * n.z);

	result.x = v.x - dot_product * n.x;
	result.y = v.y - dot_product * n.y;
	result.z = v.z - dot_product * n.z;
	return (result);
}
