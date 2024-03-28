/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_v2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:00:54 by inwagner          #+#    #+#             */
/*   Updated: 2024/03/28 14:27:30 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_rgb
{
	R,
	G,
	B
}	t_rgb;

typedef enum e_coordinate
{
	X,
	Y,
	Z
}	t_coord;

typedef enum e_object_type
{
	SP,
	PL,
	CY
}	t_type;

/* SCENE CONFIGS
*/
typedef struct s_ambient //identifier A - example:	A 0.2	255,255,255
{
	double	rat; // min 0.0 max 1.0
	int		rgb[3];
}			t_amb;

typedef struct s_camera //identifier C - example: C -50.0,0,20	0,0,1	70
{
	double	cds[3];
	double	normalized[3];
	int		fov; // from 0 to 180
}			t_cam;

typedef struct s_light //identifier L - example: L -40.0,50.0,0.0 0.6 10,0,255
{
	double	cds[3];
	double	bri; // 0.0 to 1.0
	int		rgb[3];
}			t_lgt;

/* SCENE OBJECT
*/
typedef struct s_object
{
	t_type		type;
	double		cds[3];
	double		normalized[3];
	double		dia;
	double		hgt;
	int			rgb[3];
	s_object	*next;
}				t_obj;

/* SINGLETON
*/
typedef struct s_configuration
{
	t_amb	*a;
	t_cam	*c;
	t_lgt	*l;
	t_obj	*objs;
}			t_conf;

#endif