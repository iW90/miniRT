/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_div.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:28:04 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/18 16:13:58 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector	vector_div(t_vector vector, double value)
{
	t_vector	new;

	new.x = vector.x / value;
	new.y = vector.y / value;
	new.z = vector.z / value;
	return (new);
}
