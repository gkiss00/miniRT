/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:50:33 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/01 10:50:45 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <errno.h>
# include <stdio.h>
# include "minilibx/mlx.h"
# include "error/error.h"

# define EPSILON 0.01
# define LIMIT_LIGHT 1000

typedef struct	s_vec2
{
	int			x;
	int			y;
}				t_vec2;

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

typedef struct	s_vec4
{
	float		x;
	float		y;
	float		z;
	float		d;
}				t_vec4;

typedef	struct	s_line
{
	t_vec3		coord;
	t_vec3		dir;
}				t_line;

typedef	struct	s_screen
{
	float		a;
	float		b;
	float		c;
	float		d;
}				t_screen;

typedef struct	s_pix
{
	int			color;
	t_vec3		inter;
	int			shape_number;
}				t_pix;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_camera
{
	t_vec3		coord;
	t_vec3		or;
	int			vision;
	void		*next;
}				t_camera;

typedef struct	s_light
{
	t_vec3		coord;
	float		ntensity;
	t_color		color;
	void		*next;
}				t_light;

typedef struct	s_sphere
{
	t_vec3		coord;
	int			rayon;
	t_color		color;
	void		*next;
}				t_sphere;

typedef struct	s_plane
{
	t_vec3		coord;
	t_vec3		or;
	t_color		color;
	void		*next;
}				t_plane;

typedef struct	s_square
{
	t_vec3		coord;
	t_vec3		or;
	float		hight;
	t_color		color;
	void		*next;
}				t_square;

typedef struct	s_cyl
{
	t_vec3		coord;
	t_vec3		or;
	float		rayon;
	float		hight;
	t_color		color;
	void		*next;
}				t_cyl;

typedef struct	s_triangle
{
	t_vec3		coord1;
	t_vec3		coord2;
	t_vec3		coord3;
	t_color		color;
	void		*next;
}				t_triangle;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			save;
	t_pix		**pix;
	int			shape_number;
	t_vec2		res;
	float		ambiante_intensity;
	t_color		ambiante_color;
	t_camera	*camera;
	t_camera	*camera_first;
	t_light		*light;
	t_light		*light_first;
	t_sphere	*sphere;
	t_sphere	*sphere_first;
	t_plane		*plane;
	t_plane		*plane_first;
	t_square	*square;
	t_square	*square_first;
	t_cyl		*cyl;
	t_cyl		*cyl_first;
	t_triangle	*triangle;
	t_triangle	*triangle_first;
}				t_data;

typedef struct	s_equ2
{
	float		a;
	float		b;
	float		c;
	float		delta;
	t_vec3		inter;
	t_vec3		inter2;
}				t_equ2;

/*
** Read scene
*/
int				ft_read(int fd, t_data *data);
int				ft_atoi_s(const char *str, int *n);
float			ft_fatoi_s(const char *str, int *n);
t_color			ft_fcolor(char *scene, int *i);
t_vec3			ft_fvec3(char *scene, int *n);
void			ft_fresolution(char *scene, t_data *data);
void			ft_fambiante(char *scene, t_data *data);
int				ft_fcameras(char *scene, t_data *data);
int				ft_flights(char *scene, t_data *data);
int				ft_fspheres(char *scene, t_data *data);
int				ft_fplanes(char *scene, t_data *data);
int				ft_fsquares(char *scene, t_data *data);
int				ft_fcyls(char *scene, t_data *data);
int				ft_ftriangles(char *scene, t_data *data);
t_camera		*ft_add_camera(t_data *data);
t_light			*ft_add_light(t_data *data);
t_sphere		*ft_add_sphere(t_data *data);
t_plane			*ft_add_plane(t_data *data);
t_square		*ft_add_square(t_data *data);
t_cyl			*ft_add_cyl(t_data *data);
t_triangle		*ft_add_triangle(t_data *data);
/*
** Free
*/
void			ft_free(t_data *data);
void			ft_free_pix(t_data *data, int n);
/*
** Data_tocreen.c file
*/
void			ft_data_to_screen(t_data *data);
int				exit_hook(void);
int				ft_check_and_read(char *file_rt, t_data *data);
/*
** Camera
*/
t_vec3			ft_find_pix(t_data data, t_vec2 coord);
/*
** Shapes
*/
void			ft_set_shapes(t_data *data, t_vec3 pix, t_vec2 coord);
void			ft_sphere(t_data *data, t_vec3 pix,
		float dist_min[1], t_vec2 coord);
void			ft_plane(t_data *data, t_vec3 pix,
		float dist_min[1], t_vec2 coord);
void			ft_triangle(t_data data, t_vec3 pix,
		float dist_min[1], t_vec2 coord);
void			ft_square(t_data data, t_vec3 pix,
		float dist_min[1], t_vec2 coord);
void			ft_cyl(t_data *data, t_vec3 pix,
		float dist_min[1], t_vec2 coord);
/*
** Functions called in shapes functions
*/
float			ft_norm(t_data data, t_vec3 i);
float			ft_norm_sq(t_data data, t_vec3 i);
void			ft_4point(t_data data, t_vec3 p[4]);
float			ft_affiche(t_data data, t_vec3 i);
float			ft_affiche_sq(t_data data, t_vec3 i);
float			ft_is_sq(t_data data, t_triangle triangle, t_vec3 inter);
float			ft_is_sq2(t_data data, t_triangle triangle, t_vec3 inter);
int				ft_good_side(t_vec3 vec1, t_vec3 vec2);
float			ft_norm_cyl(t_data data, t_vec3 coord);
/*
** Lights
*/
void			ft_set_light(t_data *data, t_vec2 coord);
int				ft_is_sphere_closer(t_data *data, t_vec2 coord);
int				ft_is_plane_closer(t_data *data, t_vec2 coord);
int				ft_is_cyl_closer(t_data *data, t_vec2 coord);
int				ft_is_square_closer(t_data *data, t_vec2 coord);
int				ft_is_triangle_closer(t_data *data, t_vec2 coord);
float			ft_norm_light(t_data *data, t_vec2 coord);
int				ft_same_side(t_data *data, t_vec2 coord, t_vec3 normale);
float			ft_norm_sqrt(t_data *data, t_vec2 coord, t_vec3 *normale);
float			ft_norm_sphere(t_data *data, t_vec2 coord, t_vec3 *normale);
float			ft_norm_tri(t_data *data, t_vec2 coord, t_vec3 *normale);
float			ft_norm_plane(t_data *data, t_vec2 coord, t_vec3 *normale);
/*
** Operations on vectors
*/
float			ft_vec3len(t_vec3 vec);
float			ft_dist_pp(t_vec3 vec1, t_vec3 vec2);
float			ft_prod_scal(t_vec3 vec1, t_vec3 vec2);
t_vec3			ft_vec3_sous(t_vec3 vec1, t_vec3 vec2);
t_vec3			ft_produit_vect(t_vec3 ab, t_vec3 bc);
t_vec3			ft_addition_vect(t_vec3 s1, t_vec3 s2);
t_vec3			ft_find_point(t_vec3 or, t_vec3 dir, float t);
t_vec3			ft_find_v(t_vec3 p1, t_vec3 p2);
t_vec4			ft_v3_to_v4(t_vec3 v3);
t_vec3			ft_v4_to_v3(t_vec4 v4);
t_vec4			ft_create_v4(t_vec3 v, float dist);
t_vec3			ft_create_v3(float x, float y, float z);
t_triangle		ft_create_tr(t_vec3 p1, t_vec3 p2, t_vec3 p3);
t_vec4			ft_find_p(t_vec3 p1, t_vec3 p2, t_vec3 p3);
/*
** Operations on colors
*/
int				ft_color_plus_color(int color, int ambiante);
int				ft_color_int(int color, float intensity);
int				ft_rgb_to_int(t_color rgb);
t_color			ft_int_to_rgb(int color);
t_color			ft_rgb_intensity(t_color rgb, float intensity);
/*
** Save data in bmp format
*/
int				ft_save(t_data data, char *name);
/*
** Other functions
*/
void			ft_init_lst_shapes(t_data *data);
void			ft_move_camera(t_data *data, int key);
int				deal_mouse2(int button, int x, int y, t_data *temp);

#endif
