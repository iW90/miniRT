/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:06:48 by maalexan          #+#    #+#             */
/*   Updated: 2024/02/23 21:18:13 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	rt_deg2grad(float degrees)
{
	return (degrees * M_PI / 180.0f);
}

/*
** Solves a quadratic equation of the form ax^2 + bx + c = 0.
** The coefficients of the equation are passed as a vector, where
** coeffs.x represents 'a', coeffs.y represents 'b', and coeffs.z represents 'c'.
** The roots of the equation, if existants, are returned as pointers t0 and t1.
**
** Parameters:
** - coeffs: A vector containing the coefficients of the quadratic equation.
** - t0: A pointer to a float where the first root will be stored.
** - t1: A pointer to a float where the second root will be stored.
**
** Returns:
** - TRUE if the equation has real roots, FALSE otherwise.
**
** The function first calculates the discriminant to check if the roots are real.
** If real roots exist, it computes them using the quadratic formula. 
** The roots are then sorted to ensure t0 <= t1.
*/
t_bool	solve_quadratic(t_vec3f coeffs, float *t0, float *t1)
{
	float	q;
	float	discriminant;
	float	temp;

	discriminant = coeffs.y * coeffs.y - 4 * coeffs.x * coeffs.z;
	if (discriminant < 0)
		return (FALSE);
	if (coeffs.y > 0)
		q = -0.5 * (coeffs.y + sqrt(discriminant));
	else
		q = -0.5 * (coeffs.y - sqrt(discriminant));
	*t0 = q / coeffs.x;
	*t1 = coeffs.z / q;
	if (*t0 > *t1) 
	{
		temp = *t0;
		*t0 = *t1;
		*t1 = temp;
	}
	return (TRUE);
}
