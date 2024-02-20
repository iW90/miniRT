/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:14:37 by maalexan          #+#    #+#             */
/*   Updated: 2024/02/20 19:51:00 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3f	cast_ray(t_vec3f orig, t_vec3f dir, t_ambient ambient)
{
	t_vec3f	ambient_color;
	t_vec3f	final_color;
	/* Ray-object intersection logic
	*/

	// Apply ambient lighting to the hit color
	// Note: You might want to normalize ambient.rgb values to [0, 1] if they are initially [0, 255]
	ambient_color = vec3f_scale(ambient.rgb, ambient.ratio);
	final_color = vec3f_add(hit_color, ambient_color); //hit color is ray object logic

	return (final_color);
}
