/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:28:26 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/18 11:58:47 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector	vector_product(t_vector u, t_vector v)
{
	t_vector	new;

	new.x = u.x * v.x;
	new.y = u.y * v.y;
	new.z = u.z * v.z;
	return (new);
}
