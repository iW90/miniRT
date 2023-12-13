/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:52:10 by maalexan          #+#    #+#             */
/*   Updated: 2023/12/12 22:08:08 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx/MLX42/MLX42.h"
# include "../libs/libft/incl/libft.h"
# include "scene.h"
# include "errors.h"

# define WIN_HEIGHT 600
# define WIN_WIDTH 800

# ifndef DBL_MIN
#  define DBL_MIN 2.225074e-308
# endif

# ifndef DBL_MAX
#  define DBL_MAX 1.797693e+308
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

typedef enum e_boolean
{
	FALSE,
	TRUE
}	t_bool;

void	key_hook(struct mlx_key_data key_data, void* param);
void	close_hook(void *param);

void	print_error(int errn);

#endif
