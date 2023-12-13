/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:47:44 by maalexan          #+#    #+#             */
/*   Updated: 2023/12/12 21:51:32 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

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

typedef struct s_ambient //identifier A - example:	A 0.2	255,255,255
{
	double	rat; // min 0.0 max 1.0
	int		rgb[3];
}			t_amb;

typedef struct s_camera //identifier C - example: C -50.0,0,20	0,0,1	70
{
	double	cds[3];
	double	vts[3];
	int		fov; // from 0 to 180
}			t_cam;

typedef struct s_light //identifier L - example: L -40.0,50.0,0.0 0.6 10,0,255
{
	double	cds[3];
	double	bri; // 0.0 to 1.0
	int		rgb[3];
}			t_lgt;

typedef struct s_object
{
	t_type			type;
	double			cds[3];
	double			vts[3];
	double			dia;
	double			hgt;
	int				rgb[3];
	struct s_object	*next;
}				t_obj;

typedef struct s_configuration
{
	t_amb	*a;
	t_cam	*c;
	t_lgt	*l;
	t_obj	*objs;
	char	*line;
}			t_conf;

t_conf	*get_scene(void);

void	validate_ambient(char *line);

void	validate_space(char *line, int *i, int next);
double	get_double_number(char *line, int *i, double min, double max);
int		get_int_number(char *line, int *i, int min, int max);
void	get_rgb(char *line, int *i, int *rgb);
void	get_xyz(char *line, int *i, double *xyz, int vts);

void	add_object(t_obj *object);

#endif
