/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:02:57 by maalexan          #+#    #+#             */
/*   Updated: 2023/12/10 16:24:39 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	/*
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

	*/


	char str1[] = "-123.459999367";
	char str2[] = "0.100";
	char str3[] = "-0.0109";
	char str4[] = "1";
	char str5[] = "10.010086";
	char str6[] = "1240.100000000000000000000000000000000000000000000000000000000000000000000";
	
	printf("Teste1: %.10f\n", ft_atof(str1));
	printf("Teste2: %f\n", ft_atof(str2));
	printf("Teste3: %.10f\n", ft_atof(str3));
	printf("Teste4: %.10f\n", ft_atof(str4));
	printf("Teste5: %.10f\n", ft_atof(str5));
	printf("Teste6: %.20f\n", ft_atof(str6));

	return (0);
}
