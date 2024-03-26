/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:02:57 by maalexan          #+#    #+#             */
/*   Updated: 2024/03/26 20:36:42 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*get_scene(void)
{
	static t_scene	scene;

	return (&scene);
}

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
//	mlx_image_t	*image;
//	t_scene		*scene;

	mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "miniRT", false);
	if (!mlx)
		return (1);
	apply_validations(argc, argv);
/*	scene = get_scene();
	parse_scene(scene);
	render_scene(scene);*/
//	mlx_image_to_window(mlx, image, 0, 0);
	mlx_key_hook(mlx, key_hook, mlx);
	mlx_close_hook(mlx, close_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
