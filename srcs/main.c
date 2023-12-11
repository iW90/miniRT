/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:02:57 by maalexan          #+#    #+#             */
/*   Updated: 2023/12/10 17:47:34 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	open_window(void)
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
}


// TRATAMENTO DE ERRO
/* A função "perror" imprime a mensagem referente ao último erro gravado, e a
 * "strerror" imprime uma mensagem de erro de acordo com o número passado pelo
 * parâmetro "errn". A lista de erros está disponível no arquivo "error.md".
 */
void	print_error(int errn)
{
	if (errn == -1)
		perror("");
	else
		write(2, strerror(errn), ft_strlen(strerror(errn)));
	write(2, "\n", 1);
	exit(-1);
}

int	main(int argc, char **argv)
{
	int			len;
	int			ext;

	if (argc != 2)
		print_error(22);
	len = ft_strlen(argv[1]);
	ext = ft_strncmp(&argv[1][len - 3], ".rt", 4);
	if (len < 5 || ext)
		print_error(22);

	open_window();
	return (0);
}
