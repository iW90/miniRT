/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:28:19 by inwagner          #+#    #+#             */
/*   Updated: 2024/05/22 19:29:47 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "minirt.h"
# include "objects.h"
# include "scene.h"
# include "render.h"

typedef struct s_quadratic
{
	double	a;
	double	b;
	double	c;
	double	discr;
	double	root[2];
}			t_quadratic;

int			hit_sphere(t_sphere sphere, t_ray *ray, t_range t, t_ray_hit *rec);
void		set_face_normal(t_ray_hit *rec, t_ray *ray,	t_vector *out_normal);
int			hit_plane(t_plane plane, t_ray *ray, t_range t,	t_ray_hit *rec);
t_hit		init_hit(t_cylinder *cyl, t_ray *ray, t_range t, t_ray_hit *rec);
t_quadratic	init_quadratic(t_vector pj_ori_center, t_vector v, double radius);
int			body_or_cap(t_hit *hit, int body_hit);
int			select_hit(double rt[2], t_hit *hit, \
						int vld_inter1, int vld_inter2);
int			trace_ray_hit(t_object *list, t_ray *ray, \
							t_range t, t_ray_hit *rec);
int			hit_cylinder(t_cylinder *cyl, t_ray *ray, \
							t_range t, t_ray_hit *rec);
int			is_shadowed(t_vector point, t_light light, \
						t_object *world,	int ignored);
int			set_record(double *closest, t_ray_hit *tr, \
						t_ray_hit *rec, int index);
int			hit_object(t_object *obj, t_ray *ray, \
						t_range t_var, t_ray_hit *tr);
void		update_hit_record(t_ray_hit *rec, t_vector point, \
								t_vector cap_bottom, t_vector axis);

#endif