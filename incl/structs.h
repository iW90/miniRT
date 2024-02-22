/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:47:44 by maalexan          #+#    #+#             */
/*   Updated: 2024/02/21 22:19:17 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_vec3f
{
	float	x;
	float	y;
	float	z;
}	t_vec3f;

typedef struct s_matrix44f
{
	float	m[4][4];
}	t_matrix44f;

typedef struct s_ray
{
	t_vec3f	orig;
	t_vec3f	dir;
}	t_ray;

typedef struct s_ambient //identifier A - example:	A 0.2	255,255,255
{
	float	ratio; // min 0.0 max 1.0
	t_vec3f	rgb; // from 0 to 255
}	t_ambient;

typedef struct s_camera // identifier C - example: C -50.0,0,20	0,0,1	70
{
	t_vec3f	coords;
	t_vec3f	norm_vector; //from -1 to 1
	int		horiz_fov; // from 0 to 180
}	t_camera;

typedef struct s_light
{
	t_vec3f	coords;
	float	bright_ratio; // 0 to 1
	t_vec3f	rgb; // from 0 to 255
}			t_light;

typedef struct s_sphere
{
	t_vec3f			coords;
	float			diameter;
	t_vec3f			rgb; // from 0 to 255
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	t_vec3f			coords;
	t_vec3f			norm_vector; //from -1 to 1
	t_vec3f			rgb; // from 0 to 255
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3f				coords;
	t_vec3f				norm_vector; //from -1 to 1
	float				diameter;
	float				height;
	t_vec3f				rgb; // from 0 to 255
	struct s_cylinder	*next;
}					t_cylinder;

typedef struct	s_scene
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
}				t_scene;

typedef struct s_objects
{
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
}				t_objects;

#endif
