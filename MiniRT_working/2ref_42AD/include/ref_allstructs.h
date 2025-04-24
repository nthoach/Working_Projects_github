/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref_allstructs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:19:52 by marvin            #+#    #+#             */
/*   Updated: 2025/01/06 16:19:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
# include <immintrin.h> // For AVX/SSE intrinsics (__m256d, __m128)
# include <stdint.h> // For bit-wise magic (having the option is nice)
//# include <stdbool.h> // for `true`, `false`

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//Graphic
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

// vector 4d
typedef union u_vec4s
{
	float		a[4];
	__m128		simd;
	uint32_t	raw[4];
	struct
	{
		float	x;
		float	y;
		float	z;
		float	w;
	};
}__attribute((aligned(16)))	t_vec4s;

//color
typedef union u_color
{
	t_vec4s	v;
	struct
	{
		float	a;
		float	r;
		float	g;
		float	b;
	};
}	t_color;

// matrix 4x4
typedef union u_mat4s
{
	float	a[4][4];
	__m128	simd[4];
	__m256	_ymm[2];
	struct
	{
		t_vec4s	r1;
		t_vec4s	r2;
		t_vec4s	r3;
		t_vec4s	r4;
	};
}__attribute((aligned(16)))	t_mat4s;


// Material = data for object
typedef struct s_material
{
	t_color		color;
	t_color		xordc;
	float		ambient;
	float		diffuse;
	float		specular;
	float		sheen;
	float		reflective;
	float		transparency;
	float		refractive_index;
	bool		checkered;
	t_canvas	*tex;
}	t_material;

// object
typedef struct s_obj
{
	int			type;
	t_vec4s		center;
	t_mat4s		inv_transform;
	t_mat4s		transposed_inverse;
	t_mat4s		rot;
	t_vec4s		trans;
	t_vec4s		scale;
	t_vec4s		orientation;
	t_material	material;
	float		radius;
	union u_specs
	{
		struct
		{
			t_vec4s	normal;
		};
		struct
		{
			float	side_length;
		};
		struct
		{
			float	min;
			float	max;
			bool	closed;
		};
	}	specs;
}	t_obj;


// lights

typedef struct s_light
{
	int		type;
	t_vec4s	pos;
	float	ratio;
	union u_light_type
	{
		struct s_point
		{
			t_color	intensity;
		}	point;
		struct s_spot
		{
			t_color	intensity;
			t_vec4s	orientation;
			float	spot_angle;
		}	spot;
	}	specs;
}	t_light;


// Scene
typedef struct s_world
{
	bool	refract_reflect;
	t_color	ambiance;
	int		num_shapes;
	int		num_lights;
	t_obj	*shapes;
	t_light	*lights;
}	t_world;

// Camera
typedef struct s_camera
{
	bool		is_set; //Indicates whether the camera has been properly initialized and set up.
	int			line_set; //Line number where the camera was set up.
	int			hsize; //he horizontal size (width) of the camera's view in pixels.
	int			vsize; //The vertical size (height) of the camera's view in pixels.
	float		fov; //Field of view in degrees.
	t_mat4s		inv_transform; //The inverse transformation matrix of the camera. This matrix is used to transform world coordinates into camera coordinates.
	t_vec4s		forward; //The forward vector of the camera.
	t_vec4s		up; //The up vector of the camera.
	t_vec4s		left; //The left vector of the camera.
	t_mat4s		rot; //The rotation matrix of the camera.
	t_vec4s		trans; //The translation vector of the camera. This defines the camera's position in the world.
	t_vec4s		scale; //The scale vector of the camera. This can be used to apply scaling transformations to the camera, though it's less common in typical camera setups.
	float		half_width; //Half the width of the canvas.
	float		half_height; //Half the height of the camera's view at the near plane. This is used in perspective projection calculations.
	float		half_view; // Half the view size, which is related to the field of view and the aspect ratio. This is used to calculate the dimensions of the view frustum.
	float		aspect_ratio; // The aspect ratio of the camera's view, calculated as hsize / vsize. This determines the proportional relationship between the width and height of the view.
	float		pixel_size; //The size of a single pixel in world units. This is used to map screen coordinates to world coordinates and vice versa.
}	t_camera;

//unit processor
typedef struct s_thread
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
} 	t_thread;



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