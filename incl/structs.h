/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:47:44 by maalexan          #+#    #+#             */
/*   Updated: 2023/12/10 11:53:49 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_ambient //identifier A - example:	A 0.2	255,255,255
{
	double	ratio; // min 0.0 max 1.0
	int		r; // from 0 to 255
	int		g; // from 0 to 255
	int		b; // from 0 to 255
}			t_ambient;

typedef struct s_camera // identifier C - example: C -50.0,0,20	0,0,1	70
{
	double	coord_x; 
	double	coord_y;
	double	coord_z;
	double	norm_vec_x; //from -1 to 1
	double	norm_vec_y; //from -1 to 1
	double	norm_vec_z; //from -1 to 1
	int		horiz_fov; // from 0 to 180
}			t_camera;

typedef struct s_light
{
	double	coord_x; 
	double	coord_y;
	double	coord_z;
	double	bright_ratio; // 0 to 1
	int		r; // from 0 to 255
	int		g; // from 0 to 255
	int		b; // from 0 to 255
}			t_light;

typedef struct s_sphere
{
	double			coord_x; 
	double			coord_y;
	double			coord_z;
	double			diameter;
	int				r; // from 0 to 255
	int				g; // from 0 to 255
	int				b; // from 0 to 255
	struct s_sphere	*next;
}					t_sphere;

typedef struct s_plane
{
	double			coord_x; 
	double			coord_y;
	double			coord_z;
	double			norm_vec_x; //from -1 to 1
	double			norm_vec_y; //from -1 to 1
	double			norm_vec_z; //from -1 to 1
	int				r; // from 0 to 255
	int				g; // from 0 to 255
	int				b; // from 0 to 255
	struct s_plane	*next;
}					t_plane;

typedef struct s_cylinder
{
	double				coord_x; 
	double				coord_y;
	double				coord_z;
	double				norm_vec_x; //from -1 to 1
	double				norm_vec_y; //from -1 to 1
	double				norm_vec_z; //from -1 to 1
	double				diameter;
	double				height;
	int					r; // from 0 to 255
	int					g; // from 0 to 255
	int					b; // from 0 to 255
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
