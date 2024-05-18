/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:31:35 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/05/18 11:18:59 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "./mlx/MLX42/MLX42.h"

typedef struct s_mlx
{
	mlx_t				*mlx;
	mlx_image_t			*image;
	int					width;
	int					height;
}						t_mlx;

void	init_resolution(void);
void	window_loop(void);

#endif