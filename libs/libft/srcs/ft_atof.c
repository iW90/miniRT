/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:40:55 by inwagner          #+#    #+#             */
/*   Updated: 2023/12/10 16:21:16 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_decimal(const char *str)
{
	double	dot;
	double	decimal;

	dot = 1.0;
	while (ft_isdigit(*str))
	{
		dot *= 10.0;
		decimal = decimal + (*str++ - '0') / dot;
	}
	return (decimal);
}

double	ft_atof(const char *str)
{
	double	result;
	int		neg;

	neg = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		neg = 1;
	if (*str == '-' || *str == '+')
		str++;
	result = (double)ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (!str)
		return (result);
	str++;
	result += ft_decimal(str);
	if (neg)
		return (-result);
	return (result);
}
