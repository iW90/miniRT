/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_orientation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:11:57 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/18 11:11:31 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minirt.h"

int	validate_orientation(char *str1, char *str2, char *str3)
{
	if (!str1 || !str2 || !str3)
		return (0);
	if (!ft_is_numeric_string(str1) || !ft_is_numeric_string(str2)
		|| !ft_is_numeric_string(str3))
		return (0);
	if (ft_atof(str1) < -1.0 || ft_atof(str1) > 1.0 || ft_atof(str2) < -1.0
		|| ft_atof(str2) > 1.0 || ft_atof(str3) < -1.0 || ft_atof(str3) > 1.0)
		return (0);
	return (1);
}
