/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:42:45 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/22 19:34:06 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../libs/libvec/incl/libvector.h"
# include "scene.h"

typedef enum e_light_type
{
	AMBIENT,
	DIFFUSE,
	SPECULAR,
	RESULT
}	t_light_type;

typedef struct s_ray
{
	t_vector		origin;
	union
	{
		t_vector	direction;
		t_vector	dir;
	};
}					t_ray;

typedef struct s_range
{
	double			min;
	double			max;
}					t_range;

typedef struct s_hit_record
{
	t_vector		point;
	t_vector		normal;
	double			t;
	int				front_face;
	int				index;
	int				ignore_index;
}					t_ray_hit;

typedef struct s_hit
{
	union
	{
		void		*object;
		t_sphere	*sphere;
		t_cylinder	*cyl;
		t_plane		*plane;
	};
	t_ray			*ray;
	t_range			t;
	t_ray_hit		*rec;
}					t_hit;

void		render(void);
void		camera_on(t_camera *camera);
t_vector	ray_color(t_ray ray, t_object *world, t_light light);
t_vector	ray_at(t_ray ray, double t);
t_vector	lighting(t_material m, t_light light, t_hit *hit, int in_shadow);

#endif