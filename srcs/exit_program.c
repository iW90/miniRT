/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:50:12 by inwagner          #+#    #+#             */
/*   Updated: 2023/12/10 21:30:40 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// TRATAMENTO DE ERRO
/* A função "perror" imprime a mensagem referente ao último erro gravado, e a
 * "strerror" imprime uma mensagem de erro de acordo com o número passado pelo
 * parâmetro "errn". A lista de erros está disponível no arquivo "error.md".
 */
void	print_error(int errn)
{
	if (errn == -1)
		perror("");
	else if (errn > 0)
		write(2, strerror(errn), ft_strlen(strerror(errn)));
	else
		printf("Another error");
	write(2, "\n", 1);

	//dar free nos trem t_conf
	exit(-1);
}
