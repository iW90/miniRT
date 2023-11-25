/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:52:10 by maalexan          #+#    #+#             */
/*   Updated: 2023/11/25 11:05:50 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "mlx/MLX42/MLX42.h"

# define WIN_HEIGHT 600
# define WIN_WIDTH 800

void    key_hook(struct mlx_key_data key_data, void* param);
void    close_hook(void *param);

#endif