/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:53:19 by maalexan          #+#    #+#             */
/*   Updated: 2024/03/23 20:57:02 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	key_hook(struct mlx_key_data key_data, void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		mlx_close_window(mlx);
	else if (key_data.action == MLX_PRESS)
		printf("Key: %i\n", key_data.key);
}

void	close_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	mlx_close_window(mlx);
}

void	exit_program(int code)
{
	exit(code);
}
