/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_orientation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:11:57 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/25 14:05:02 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_orientation(char *str1, char *str2, char *str3)
{
	if (!str1 || !str2 || !str3)
		return (0);
	if (!ft_isstrnum(str1) || !ft_isstrnum(str2)
		|| !ft_isstrnum(str3))
		return (0);
	if (ft_atof(str1) < -1.0 || ft_atof(str1) > 1.0 || ft_atof(str2) < -1.0
		|| ft_atof(str2) > 1.0 || ft_atof(str3) < -1.0 || ft_atof(str3) > 1.0)
		return (0);
	return (1);
}
