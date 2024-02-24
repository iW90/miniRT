/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:52:10 by maalexan          #+#    #+#             */
/*   Updated: 2024/02/24 11:58:41 by maalexan         ###   ########.fr       */
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

# define TRUE 1
# define FALSE 0
# define OUT_OF_MEMORY 12

typedef int t_bool;

void	key_hook(struct mlx_key_data key_data, void* param);
void	close_hook(void *param);

float	vec3f_dot(t_vec3f a, t_vec3f b);
t_vec3f	vec3f_add(t_vec3f a, t_vec3f b);
t_vec3f	vec3f_sub(t_vec3f a, t_vec3f b);
t_vec3f	vec3f_scale(t_vec3f v, float scalar);
t_vec3f	vec3f_normalize(t_vec3f v);

float	rt_deg2grad(float degrees);
t_bool	solve_quadratic(t_vec3f coeffs, float *t0, float *t1);

t_bool	intersect_sphere(t_ray ray, t_sphere *sphere, float *t);

mlx_image_t *render(void);

#endif
