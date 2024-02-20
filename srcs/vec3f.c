/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:39:59 by maalexan          #+#    #+#             */
/*   Updated: 2024/02/20 19:42:45 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3f	vec3f_add(t_vec3f a, t_vec3f b)
{
	return ((t_vec3f){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_vec3f	vec3f_scale(t_vec3f v, float scalar)
{
	return ((t_vec3f){v.x * scalar, v.y * scalar, v.z * scalar});
}

t_vec3f	vec3f_normalize(t_vec3f v)
{
	float	len;

	len = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	v.x /= len;
	v.y /= len;
	v.z /= len;
	return (v);
}
