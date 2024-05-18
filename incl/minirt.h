/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:24:08 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/05/18 11:30:04 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/libft/incl/libft.h"
# include "../libs/libvec/libvector.h"
# include "definitions.h"
# include "hit.h"
# include "objects.h"
# include "render.h"
# include "scene.h"
# include "validate.h"
# include "window.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data
{
	t_mlx		mlx;
	t_camera	camera;
	t_ambient	ambient;
	t_light		light;
	t_object	*objects;
}				t_data;

t_data			*get_data(void);
void			print_header(void);
void			print_data(void);

#endif
