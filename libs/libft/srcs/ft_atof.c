/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:40:55 by inwagner          #+#    #+#             */
/*   Updated: 2024/04/10 19:29:44 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_decimal(const char *str)
{
	double	dot;
	double	decimal;

	dot = 1.0;
	decimal = 0.0;
	while (ft_isdigit(*str))
	{
		dot *= 10.0;
		decimal = decimal + (*str++ - '0') / dot;
	}
	return (decimal);
}

float	ft_atof(const char *str)
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
	while (ft_isdigit(*str))
		str++;
	if (*str == '.')
	{
		str++;
		result += ft_decimal(str);
	}
	if (neg)
		return (-result);
	return (result);
}
