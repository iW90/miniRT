/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_header.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:14:31 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/25 12:29:03 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_first_header(void)
{
	printf(COLOR_GR_1);
	printf("   •  •     \n");
	printf("┏┳┓┓┏┓┓  ┏┓╋\n");
	printf("┛┗┗┗┛┗┗  ┛ ┗\n");
	printf("\n");
}

void	print_second_header(void)
{
	printf(COLOR_WH);
	printf("███╗   ███╗██╗███╗   ██╗██╗    ██████╗ ████████╗\n");
	printf("████╗ ████║██║████╗  ██║██║    ██╔══██╗╚══██╔══╝\n");
	printf("██╔████╔██║██║██╔██╗ ██║██║    ██████╔╝   ██║   \n");
	printf("██║╚██╔╝██║██║██║╚██╗██║██║    ██╔══██╗   ██║   \n");
	printf("██║ ╚═╝ ██║██║██║ ╚████║██║    ██║  ██║   ██║   \n");
	printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝    ╚═╝  ╚═╝   ╚═╝   \n");
	printf("\n");
}

void	print_third_header(void)
{
	printf(COLOR_RE);
	printf("███▄ ▄███▓ ██▓ ███▄    █  ██▓    ██▀███  ▄▄▄█████▓\n");
	printf("▓██▒▀█▀ ██▒▓██▒ ██ ▀█   █ ▓██▒   ▓██ ▒ ██▒▓  ██▒ ▓▒\n");
	printf("▓██    ▓██░▒██▒▓██  ▀█ ██▒▒██▒   ▓██ ░▄█ ▒▒ ▓██░ ▒░\n");
	printf("▒██    ▒██ ░██░▓██▒  ▐▌██▒░██░   ▒██▀▀█▄  ░ ▓██▓ ░ \n");
	printf("▒██▒   ░██▒░██░▒██░   ▓██░░██░   ░██▓ ▒██▒  ▒██▒ ░ \n");
	printf("░ ▒░   ░  ░░▓  ░ ▒░   ▒ ▒ ░▓     ░ ▒▓ ░▒▓░  ▒ ░░   \n");
	printf("░  ░      ░ ▒ ░░ ░░   ░ ▒░ ▒ ░     ░▒ ░ ▒░    ░    \n");
	printf("░      ░    ▒ ░   ░   ░ ░  ▒ ░     ░░   ░   ░      \n");
	printf("       ░    ░           ░  ░        ░              \n");
}

void	print_header(void)
{
	printf("\n");
	if (DEBUG)
		print_third_header();
	else
		print_first_header();
	printf(COLOR_NO);
	printf("\n");
}
