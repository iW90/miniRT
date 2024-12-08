/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init_resolution.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:28:09 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/24 13:53:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_resolution(void)
{
	t_data	*data;

	data = get_data();
	data->mlx.width = WIDTH;
	data->mlx.height = HEIGHT;
	if (data->mlx.height < 1)
		data->mlx.height = 1;
}

void	init_resolution(void)
{
	t_mlx	*mlx;

	mlx = &get_data()->mlx;
	set_resolution();
	mlx->mlx = mlx_init(mlx->width, mlx->height, "MiniRT", 0);
	mlx->image = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
}
