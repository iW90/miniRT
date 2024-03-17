/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:47:44 by maalexan          #+#    #+#             */
/*   Updated: 2024/03/17 11:33:29 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define WIN_HEIGHT 600
# define WIN_WIDTH 800
# define EPSILON 1e-6


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

typedef struct s_scene
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
}				t_scene;

typedef enum e_type
{
	SPHERE,
	PLANE,
	CYLINDER	
}	t_type;

typedef union u_object_data
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
}	t_object_data;

typedef struct s_object
{
	t_type			type;
	t_object_data	data;
	struct s_object	*next;
}	t_object;

typedef struct s_intersect
{
	float				distance;	// Distance from the ray origin to the intersection
	t_vec3f				point;		// Intersection point
	t_vec3f				normal;		// Normal at the intersection point
	t_object			*object;	// Pointer to the intersected object
	struct s_intersect	*next;		// Next intersection in the list
}	t_intersect;

typedef struct s_framebuffer
{
	t_intersect		*intersections[WIN_WIDTH * WIN_HEIGHT];
}	t_framebuffer;

#endif
