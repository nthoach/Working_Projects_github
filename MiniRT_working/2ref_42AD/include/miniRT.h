/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:35:52 by ebinjama          #+#    #+#             */
/*   Updated: 2024/10/16 13:18:51 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "lag.h"
# include "common.h"
# include <pthread.h>
# include <stdint.h> // for `uint32_t`
# include "libft.h" // for `t_split`
# include <stdio.h> //// TEMP
# include <sys/time.h>

# ifdef EPSILON
#  undef EPSILON
#  define EPSILON 0.0001f
# endif // !EPSILON

long long	my_gettime(void);

typedef struct s_canvas
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		bpp_8;
	int		line_length;
	int		endian;
	int		tex_width;
	int		tex_height;
}	t_canvas;

typedef struct s_thread_data	t_thread;

typedef struct s_tex_node
{
	char		*name;
	t_canvas	*tex;
}	t_texture;

typedef struct s_program
{
	int			runtime_error;
	int			flt_operations;
	void		*mlx;
	void		*win;
	t_list		*textures;
	t_canvas	canvas;
	t_world		world;
	t_camera	cam;
	t_thread	*pool;
	bool		stop;
	float		delta_time;
	struct s_select
	{
		bool	is_cam;
		t_obj	*object;
		t_vec4s	ray_dir;
	}	selected;
	struct s_ambient
	{
		bool	is_set;
		int		line_set;
		t_color	color;
		float	ratio;
	}	ambiance;
	struct s_movement
	{
		bool		w;
		bool		a;
		bool		s;
		bool		d;
		bool		up;
		bool		down;
		bool		left;
		bool		right;
		bool		space;
		bool		lctrl;
		bool		lshift;
	}	movement;
	struct s_mouse
	{
		bool		left_click;
	}	mouse;
}	t_program;

struct s_thread_data
{
	int				id;
	pthread_t		thread;
	t_program		*context;
	int				y;
	int				y_f;
	int				x;
	int				x_f;
	bool			work_ready;
	pthread_mutex_t	mutex;
	pthread_cond_t	cond;
};

typedef struct itx_computation
{
	bool		shadowed;
	double		t;
	t_obj		*obj;
	t_vec4s		p;
	t_vec4s		over_point;
	t_vec4s		under_point;
	t_vec4s		eyev;
	t_vec4s		normalv;
	t_vec4s		reflectv;
	int			inside;
	double		n1;
	double		n2;
}	t_comps;

/*--- PARSING ---*/

typedef struct s_validate_atof
{
	size_t	sign_count;
	size_t	dot_count;
	size_t	digit_count;
	bool	found_alpha;
}	t_vatof;

bool		is_normalised(t_vec4s *vec, int curr_line);
float		ft_atof(char *rep, t_program *context);
bool		parse_file(const char *filename, t_program *context);
bool		parse_ambient(t_program *context, t_split *fields, int curr_line);
bool		parse_light(t_program *context, const t_split *fields,
				int curr_line);
bool		parse_spot_light(t_program *context, const t_split *fields,
				int curr_line);
bool		parse_camera(t_program *context, const t_split *fields,
				int curr_line);
bool		parse_sphere(t_program *context, const t_split *fields,
				int curr_line);
bool		parse_plane(t_program *context, const t_split *fields,
				int curr_line);
bool		parse_cube(t_program *context, const t_split *fields,
				int curr_line);
bool		parse_cylinder(t_program *context, const t_split *fields,
				int curr_line);
bool		parse_cone(t_program *context, const t_split *fields,
				int curr_line);
bool		parse_color(t_color *color, char *str, int curr_line);
bool		parse_vec4v(t_vec4s *vec, char *str, t_program *context,
				int curr_line);
bool		parse_vec4p(t_vec4s *vec, char *str, t_program *context,
				int curr_line);
bool		parse_single_f(float *f, char *str, t_program *context,
				int curr_line);
bool		parse_material(t_material *obj_material, char **material_fields,
				t_program *context, int curr_line);
bool		parse_plane_checker(t_material *obj_mat, t_program *context,
				char *is_checker);
bool		parse_bump_xpm(t_material *obj_mat, t_program *context,
				char *filename);
t_mat4s		rt_extract_rot_vertical(const t_vec4s u);
t_mat4s		rt_get_cam_inverse(const t_mat4s *view);
bool		check_object_validity_init(t_program *context, const char *info,
				int curr_line, const t_split fields);
void		parse_fatal_msg(char *msg, int curr_line);
void		parse_warn_msg(char *msg, char *expected, int curr_line, bool ign);
void		parse_err_msg(char *msg, char *expected, int curr_line);
void		parse_syn_err_msg(char *msg, int curr_line);

/*--- RENDERING ---*/

t_color		rt_render_pixel(t_program *context, int x, int y);
t_ray		ray_for_pixel(const t_camera *cam, int px, int py);
bool		create_canvas(t_program *context, int width, int height);
void		put_pixel(t_canvas *canvas, int x, int y, const t_color *color);
void		render_frame(t_program *current_context);
t_color		color_at(t_world *w, t_ray *r, int depth);

/*---- THREADS ----*/

bool		pool_init(t_program *context);
bool		thread_arbiter(t_program *context);
void		*await_task(void *arg);
void		interpolate_horizontal(t_thread const *data);
void		interpolate_vertical(t_thread const *data);
int			cdiff(t_color a, t_color b);
t_color		lerp_colors(const t_color *a, const t_color *b, float t);
t_color		fetch_pixel_color(const t_canvas *canvas, int x, int y);

/*--- STATE ---*/

//void		update_camera_state(t_camera *camera);
int			update(void *context);
int			check_state(void *context);
int			check_key_presses(int keysym, void *context);
int			check_key_releases(int keysym, void *param);
int			check_mouse_clicks(int button, int x, int y, void *param);

/*--- EVENTS ---*/
void		object_controls(t_program *state);
void		camera_controls(t_program *state);
void		camera_rotations(t_program *state);
t_mat4s		rt_rotation_matrix_from_axis_angle(const t_vec4s *axis,
				float angle);

/*--- DESTROY ---*/

void		destroy_mlx(t_program *context);
void		destroy_world(t_program *context);
int			destroy_program(t_program *context);
void		destroy_textures(t_program *context);
void		str_arr_destroy(char **arr);

/*--- RAY - MANIPULATION ---*/

void		ray_create(t_ray *ray, t_vec4s *origin, t_vec4s *direction);
void		ray_position(t_vec4s *result, const t_ray *ray, float t);
void		ray_transform(t_ray *ray, const t_mat4s *matrix);
t_vec4s		reflect(t_vec4s *in, t_vec4s *normal);

/*--- FRAGMENT CALCULATION ---*/

t_itx_grp	intersect_world(t_world *w, t_ray *r);
bool		intersect_sphere(t_ray *r, t_obj *sphere, t_itx_grp *xs);
bool		intersect_plane(t_ray *ray, t_obj *plane, t_itx_grp *xs);
bool		intersect_cylinder(t_ray *ray, t_obj *cy, t_itx_grp *xs);
bool		intersect_cube(t_ray *ray, t_obj *cube, t_itx_grp *xs);
bool		intersect_cone(t_ray *ray, t_obj *cone, t_itx_grp *xs);
t_vec4s		cone_normal_at(t_obj *cone, t_vec4s *world_point);
t_vec4s		cube_normal_at(t_obj *cube, t_vec4s *world_point);
t_vec4s		cylinder_normal_at(t_obj *cylinder, t_vec4s *world_point);
void		cast_shadow_ray(t_world *w, t_ray *r, t_itx_grp *xs);
t_vec4s		plane_normal_at(t_obj *plane, t_vec4s *world_p);
t_vec4s		sphere_normal_at(t_obj *sphere, t_vec4s *world_p);
void		quick_sort_intersections(t_itx *arr, size_t size);
t_itx		*get_hit(t_itx_grp *xs);
void		lag_mat4s_transpose(const t_mat4s *m, t_mat4s *out);

/*--- TEXTURES ---*/

t_canvas	*rt_xpm_file_to_canvas(char *filepath, void *mlx);
t_vec2s		rt_get_sphere_uv_local(t_vec4s *hitp);
t_vec2s		rt_get_plane_uv_local(t_vec4s *hitp, t_vec4s tangent,
				t_vec4s *normal);
t_vec4s		rt_get_sphere_tangent(t_vec4s *local_normal);
t_vec4s		rt_get_plane_tangent(t_vec4s *local_normal);
t_vec2s		rt_get_cylinder_uv_local(t_vec4s *hitp);
t_vec4s		rt_get_cylinder_tangent(t_vec4s *local_normal, t_obj *cylinder);
t_color		rt_sample_texture(const t_canvas *tex, const t_vec2s *uv);
t_vec4s		rt_apply_normal_map(const t_obj *obj, const t_vec2s *uv,
				const t_vec4s *local_normal, const t_vec4s *tangent);

/*--- LIGHTING ---*/

t_color		shade_hit(t_world *world, t_comps *comps, int depth);
t_color		check_for_refref(t_world *world, t_comps *comps, int depth);
bool		is_shadowed(t_world *world, t_vec4s *point, t_light *light);
void		prepare_refractions(t_itx *hit, t_comps *comps,
				t_itx_grp *itxs);
t_color		refracted_color(t_world *world, t_comps *comps,
				int depth);
t_color		reflected_color(t_world *world, t_comps *comps,
				int depth);
float		schlick(t_comps *comps);
t_color		lighting(t_comps *comps, t_material *material, t_light *light,
				bool in_shadow);
float		get_spot_light_intensity(t_light *light, t_vec4s light_v);
bool		is_spot_light_shadowed(t_light *light, t_vec4s *v);
void		check_for_texture(t_comps *comps, t_material *material,
				t_material_colors *mat_colors);

#endif // !MINIRT_H
