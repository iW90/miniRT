/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:52:10 by maalexan          #+#    #+#             */
/*   Updated: 2024/02/21 22:34:13 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "mlx/MLX42/MLX42.h"
# include "structs.h"

# define WIN_HEIGHT 600
# define WIN_WIDTH 800
# define TRUE 1
# define FALSE 0

typedef int t_bool;

void	key_hook(struct mlx_key_data key_data, void* param);
void	close_hook(void *param);

float	vec3f_dot(t_vec3f a, t_vec3f b);
t_vec3f	vec3f_add(t_vec3f a, t_vec3f b);
t_vec3f	vec3f_sub(t_vec3f a, t_vec3f b);
t_vec3f	vec3f_scale(t_vec3f v, float scalar);
t_vec3f	vec3f_normalize(t_vec3f v);

#endif
