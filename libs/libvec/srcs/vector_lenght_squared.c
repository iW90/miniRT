/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_lenght_squared.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:28:14 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/18 11:58:47 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

double	vector_length_sqd(const t_vector vector)
{
	return ((vector.x * vector.x)
		+ (vector.y * vector.y)
		+ (vector.z * vector.z));
}
