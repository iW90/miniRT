/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:48:00 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/25 12:31:28 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# define COLOR_NO "\033[m"
# define COLOR_RE "\033[0;31m"
# define COLOR_RE_1 "\033[1;31m"
# define COLOR_YE "\033[0;33m"
# define COLOR_YE_1 "\033[1;33m"
# define COLOR_GR "\033[0;32m"
# define COLOR_GR_1 "\033[1;32m"
# define COLOR_BL "\033[0;34m"
# define COLOR_BL_1 "\033[1;34m"
# define COLOR_PL "\033[0;35m"
# define COLOR_PL_1 "\033[1;35m"
# define COLOR_CY "\033[0;36m"
# define COLOR_CY_1 "\033[1;36m"
# define COLOR_WH "\033[0;37m"
# define COLOR_WH_1 "\033[1;37m"

# ifdef DEBUG
#  define WIDTH 320
#  define HEIGHT 240
#  define ASPECT_RATIO 1.33333333333
# else
#  define WIDTH 1920
#  define HEIGHT 1080
#  define ASPECT_RATIO 1.7777777777679
#  define DEBUG 0
# endif

# define PI 3.1415926535897932385

# define M_EPSILON 1e-6

#endif
