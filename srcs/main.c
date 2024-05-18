/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:08:29 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/18 10:43:50 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minirt.h"

int	main(int argc, char **argv)
{
	print_header();
	validate_args(argc, argv);
	set_ambient_light();
	init_resolution();
	render();
	window_loop();
	if (DEBUG)
		print_data();
	clear_objects();
	return (0);
}
