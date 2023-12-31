/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:02:57 by maalexan          #+#    #+#             */
/*   Updated: 2023/11/25 10:52:31 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "miniRT", false);
	if (!mlx)
		return (1);
	image = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_key_hook(mlx, key_hook, mlx);
	mlx_close_hook(mlx, close_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
