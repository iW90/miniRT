/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:20:50 by maalexan          #+#    #+#             */
/*   Updated: 2024/02/23 12:25:00 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

mlx_image_t *render(void)
{
	int	*framebuffer;

	framebuffer = malloc(WIN_WIDTH * WIN_HEIGHT * sizeof(int));
	if (!framebuffer)
		return (NULL);
	
}