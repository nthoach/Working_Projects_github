/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_ref.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 08:03:20 by marvin            #+#    #+#             */
/*   Updated: 2025/01/09 08:03:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "lag.h" // for t_vec4s, t_mat4s, and their funcs
# include <stdbool.h> // for `true`, `false`
# include "libft.h"
# include <pthread.h>

typedef union u_vec4d //double presision, multiple members share the same memory location, size of union is the size of the largest member
{
	double		a[4]; // Array access
	__m256d		simd; // SIMD access for parallel processing with AVX instructions
	uint64_t	raw[4]; // for low-level operation
	struct  // named access
	{
		double	x;
		double	y;
		double	z;
		double	w;
	};
}__attribute((aligned(32)))	t_vec4d;

typedef union u_vec4s // single precsision in SIMD
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

typedef union u_vec3d
{
	double	a[3];
	__m256d	simd;
	struct
	{
		double	x;
		double	y;
		double	z;
		double	ignore;
	};
}__attribute((aligned(32)))	t_vec3d;

typedef union u_vec2s
{
	float	a[2];
	__m128d	simd;
	struct
	{
		float	x;
		float	y;
	};
}__attribute((aligned(16)))	t_vec2s;

// 2D Matrices can be held inside a single 128-bit vector, fix. (for all)
typedef union u_mat2d
{
	float	a[2][2];
	__m128d	simd[2];
	struct
	{
		t_vec2s	r1;
		t_vec2s	r2;
	};
}__attribute((aligned(16)))	t_mat2d;

typedef union u_mat3d
{
	float	a[4][4];
	__m256	simd[4];
	struct
	{
		t_vec3d	r1;
		t_vec3d	r2;
		t_vec3d	r3;
		t_vec3d	ignore;
	};
}__attribute((aligned(32)))	t_mat3d;

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

typedef union u_mat4d
{
	float	a[4][4];
	__m256d	simd[4];
	struct
	{
		t_vec4d	r1;
		t_vec4d	r2;
		t_vec4d	r3;
		t_vec4d	r4;
	};
}__attribute((aligned(32)))	t_mat4d;

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

typedef struct s_canvas	t_canvas;

typedef struct s_material
{
	t_color		color;// Represents the base color of the material.This is the primary color that the material reflects when illuminated.
	t_color		xordc;// additional color for the material
	float		ambient; // how much ambient light the matrerial reflects
	float		diffuse; // how much diffuse light the material reflects
	float		specular; // how much specular light the material reflects
	float		sheen;// how much sheen the material reflects, secondary specular highlight; softer reflective/specular effect
	float		reflective; // Determines how much light the material reflects as mirror-like reflections. Higher values make the material more reflective, like a mirror
	float		transparency; // Determines how much light passes through the material. Higher values make the material more transparent.
	float		refractive_index; //Determines how much light bends when it enters the material. It is used in refraction calculations for transparent materials.
	bool		checkered; //the material uses a checkered pattern, which can be used for visual effects or debugging.
	t_canvas	*tex; //This texture can be used to apply detailed patterns or images to the material's surface.
}	t_material;

typedef struct s_material_colors
{
	int		light_type; // point, directional or spotlight
	t_color	intensity; // The intensity of the light source
	t_color	effective_color; //product of material's base color and the light's color
	t_color	ambient; // ambient light color, applied to all scence
	t_color	diffuse; //diffuce refelection clor
	t_color	specular; //specular reflection color
	t_color	return_color; //final color of the material
}	t_material_colors;

typedef struct s_obj
{
	int			type;  // 0 = SPHERE, CYLINDER, PLANE, CUBE, CONE, SPOT_LIGHT, POINT_LIGHT
	t_vec4s		center; // center point of the object
	t_mat4s		inv_transform; // used to transfrom world coordinates to object's local coordinates
	t_mat4s		transposed_inverse; //transpose of the inverse transformation matrix
	t_mat4s		rot; // rotation matrix to define object's orientation
	t_vec4s		trans; // translation vector to define object's position
	t_vec4s		scale; // scale vector to define object's size
	t_vec4s		orientation; // orientation of the object
	t_material	material; // material properties of the object
	float		radius; //radius of the object like sphere
	union u_specs
	{
		struct
		{
			t_vec4s	normal; //normal vector like plane
		};
		struct
		{
			float	side_length; //sligde length like cube
		};
		struct
		{
			float	min; //min extends value like cylinder
			float	max; //max extends value like cylinder
			bool	closed; // closed at end or not
		};
	}	specs;
}	t_obj;

typedef struct s_intersection // intersection of ray with object
{
	float	t; // distance from ray's origin to the intersection point
	t_obj	*object; // object that ray intersects with
	float	n1; // refractive index of the medium where the ray comes from
	float	n2; // refractive index of the medium where the ray goes to
}	t_itx;

typedef struct s_intersection_group
{
	t_itx	arr[200]; // array of intersections to record all intersections to objects in the scene
	int		count; // number of intersections, usually define for a single ray
}	t_itx_grp;

typedef struct s_ray
{
	t_vec4s		origin; // starting point of the ray, uaully camera position
	t_vec4s		dir; // direction of the ray, usually from camera to pixel on the canvas
}	t_ray;

typedef struct s_camera
{
	bool		is_set; // Flag to check before rendering
	int			line_set; //Line number where the camera was set up in the scene file when parsing
	int			hsize; // horizontal size (width) of the camera's view in pixels
	int			vsize; // vertical size (height) of the camera's view in pixels
	float		fov; // Field of view in degrees
	t_mat4s		inv_transform; // inversve transformation matrix of the camera to transtform world coridnates to camera coordinates
	t_vec4s		forward; // forward direction of camera
	t_vec4s		up; // up direction of camera
	t_vec4s		left; // up direction of camera
	t_mat4s		rot; // rotation matrix
	t_vec4s		trans; // translation vector define the oriatation of the camera in the world
	t_vec4s		scale; // scaling transformaiton
	float		half_width; // half the width of the near phane (distance = 1)
	float		half_height; // half the height of the camera's view at the near plane
	float		half_view; // near plane is where the object cannot be rendered
	float		aspect_ratio;
	float		pixel_size; // number of world units each pixel of the canvas represents
}	t_camera;

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
			float	spot_angle; // cone or beam angle == spread of light emitted from the spotlight
		}	spot;
	}	specs;
}	t_light;

typedef struct s_world
{
	bool	refract_reflect; // flag to enable refraction and reflection
	t_color	ambiance; // color of the ambient light in the scene
	int		num_shapes; // total shapes in scenes
	int		num_lights; // total lights in the scene
	t_obj	*shapes; // array of shapes in the scene
	t_light	*lights; // array of lights in the scene
}	t_world;

typedef struct s_canvas  // 2D drawing area where pixels are drawn to creat an image
{
	void	*ptr;  // pointer to the canvas
	char	*addr; // pointer to the pixel data of the canvas
	int		bpp; //bits per pixel, 24 for RGB, 32 for RGBA
	int		bpp_8; // bytes per pixel
	int		line_length; //number of bytes used to store one line of the image in memory
	int		endian; // byte order of the pixel color values, little- or big-endian
	int		tex_width; // width of the texture/canvas in pixels
	int		tex_height; // height of the texture/canvas in pixels
}	t_canvas;

typedef struct s_thread_data	t_thread;

typedef struct s_tex_node  //store texture data for 3D shapes
{
	char		*name; // name of the texture
	t_canvas	*tex; // canvas to store the texture
}	t_texture;

typedef struct s_program
{
	int			runtime_error; // error code stored here
	int			flt_operations; // numbers of floating point operations
	void		*mlx; // pointer to the mlx graphic library
	void		*win; // pointer to the window of rendered images
	t_list		*textures; // list of textures
	t_canvas	canvas; // canvas to draw the image
	t_world		world; //scene
	t_camera	cam; //came
	t_thread	*pool; // array of pool of threads
	bool		stop; //flag to stop for threads
	float		delta_time; // curent selected shape
	struct s_select
	{
		bool	is_cam; // camera or shapes
		t_obj	*object; // data of selected shapes
		t_vec4s	ray_dir; // direction of the ray
	}	selected;
	struct s_ambient
	{
		bool	is_set; // flag to check if ambient light is set
		int		line_set; // line number of input file for parsing
		t_color	color; // color
		float	ratio; // instensity ratio
	}	ambiance;
	struct s_movement  //store user input for movement
	{
		bool		w; //key w
		bool		a;
		bool		s;
		bool		d;
		bool		up;
		bool		down;
		bool		left;
		bool		right;
		bool		space; //speace key
		bool		lctrl; //left control key
		bool		lshift; //left shift key
	}	movement;

	struct s_mouse
	{
		bool		left_click; // left click
	}	mouse;
}	t_program;

struct s_thread_data
{
	int				id; // id of the thread
	pthread_t		thread; // pthread
	t_program		*context; // pointer to the program data
	int				y; // starting y coordinate of pixels
	int				y_f; // ending y coordinate of pixels
	int				x; //starting x coordinate of pixels
	int				x_f; // ending x coordinate of pixels
	bool			work_ready; // flag to check if assigned work to thread is ready
	pthread_mutex_t	mutex; //lock to protect the data
	pthread_cond_t	cond; // in conjuction with mutex to signal the thread when it is ready or wait
};

typedef struct itx_computation  // intersection point data for computation purpose
{
	bool		shadowed; // flag to indicate if the intersection is shadowed
	double		t; //distance from the ray's origin to the intersection point
	t_obj		*obj; // insserted object
	t_vec4s		p; // intersection point
	t_vec4s		over_point; //overpoint to avoid precision errors
	t_vec4s		under_point; //?
	t_vec4s		eyev; // eye vector in sharding calcuation looking back to eye
	t_vec4s		normalv; //norm vector at intesection point to determine the shading intensity
	t_vec4s		reflectv; // reflection vector
	int			inside; // enter or exit the shape
	double		n1; // refractive index of the medium where the ray comes from
	double		n2; // refractie index	of the medium where the ray goes to
}	t_comps;

/*--- PARSING ---*/

typedef struct s_validate_atof // for parsing float 
{
	size_t	sign_count;
	size_t	dot_count;
	size_t	digit_count;
	bool	found_alpha;
}	t_vatof;

#endif // !COMMON_H