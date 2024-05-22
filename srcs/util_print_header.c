/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_header.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:14:31 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/22 16:53:45 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minirt.h"

static void	print_first_header(void)
{
	printf(COLOR_PL);
	printf("   •  •     \n");
	printf("┏┳┓┓┏┓┓  ┏┓╋\n");
	printf("┛┗┗┗┛┗┗  ┛ ┗\n");
	printf("\n");
}

static void	print_second_header(void)
{
	printf(COLOR_WH);
	printf("HEADER2\n\n");
	printf("███╗   ███╗██╗███╗   ██╗██╗    ██████╗ ████████╗\n");
	printf("████╗ ████║██║████╗  ██║██║    ██╔══██╗╚══██╔══╝\n");
	printf("██╔████╔██║██║██╔██╗ ██║██║    ██████╔╝   ██║   \n");
	printf("██║╚██╔╝██║██║██║╚██╗██║██║    ██╔══██╗   ██║   \n");
	printf("██║ ╚═╝ ██║██║██║ ╚████║██║    ██║  ██║   ██║   \n");
	printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝    ╚═╝  ╚═╝   ╚═╝   \n");
	printf("\n");
}

static void	print_third_header(void)
{
	printf("HEADER3\n\n");
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
	print_first_header();
	print_second_header();
	print_third_header();
	printf(COLOR_NO);
	printf("\n");
}
