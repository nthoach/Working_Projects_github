# **miniRT**
This project was graded <strong>125/100</strong>.

## 📝 **Authorship**

- [Mario Henriques](https://github.com/maricard18) ([**maricard**](https://profile.intra.42.fr/users/maricard))
- [Nuno Jesus](https://github.com/Nuno-Jesus) ([**ncarvalh**](https://profile.intra.42.fr/users/ncarvalh))

## 🧬 **Cloning**

To successfully clone this repository, use this command

```shell
git clone https://github.com/maricard18/42-miniRT.git 
```

## 📒 **About**
Rendering a 3-dimensional image can be achieved using Ray Tracing, an expensive technique, which is based on casting rays from the camera into the space. If a ray intersects a shape, it illuminates it, based on both the shape's characteristics and also the environment around it as well.

This isn't an advanced Ray Tracer, since it's implemented in C, but it definitely is functional and has a bit of our own bonus in it too!

## **Mandatory Part**

<table align=center>
	<thead>
		<tr>
			<th colspan=2>Images</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td><image src="assets/mandatory_snowman.png"></td>
			<td><image src="assets/mandatory_temple.png"></td>
		</tr>
		<tr>
			<td><image src="assets/mandatory_stickman.png"></td>
			<td><image src="assets/mandatory_losangle.png"></td>
		</tr>
	</tbody>
</table>

The mandatory part features:
	
	- Map file parser
	- Ambient and diffuse lighting
	- Display of planes, spheres and cylinders
	- Shapes intersections
	- Hard shadows
	- Ray tracing (without recursive steps)

## **Bonus Part**

<table align=center>
	<thead>
		<tr>
			<th colspan=2>Images</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td><image src="assets/bonus_colored_temple.png"></td>
			<td><image src="assets/bonus_colored_snowman.png"></td>
		</tr>
		<tr>
			<td><image src="assets/bonus_colored_multi_spot_lights.png"></td>
			<td><image src="assets/bonus_texture.png"></td>
		</tr>
	</tbody>
</table>

The bonus part features the mandatory and also the following:

	- Phong Illumination Model (ambient + diffuse + specular)
	- Checkerboarded planes
	- Multi-spot lights
	- Colored light sources
	- Multithreaded rendering (our bonus)
	- Interectable menu (our bonus)

## 🎥 **Demo**

Here's a small demo with one of our maps.

https://github.com/Nuno-Jesus/42_miniRT/assets/93390807/7ef7cc40-ab9f-4611-bdaf-18cd1a157213

## 🚨 **Disclaimer**
At 42, the C projects are built following a bunch of rules that enforce good coding style, stated in a file called **Norminette**. Some of them are:

	- No for, do while, switch, case or goto are allowed
	- No more than 25 lines per function and 5 functions per file
	- No assigns and declarations in the same line (unless static)
	- No more than 5 local functions in 1 function
	- No more than 4 parameters in 1 function
	... 


## 📦 **Compilation**
To compile the mandatory part of the ray tracer you should run `make`.

This rule will generate a `miniRT` file, which is the zipped version of all the object files. Running `make bonus` will compile the bonus part of the ray tracer. 

> **Note**
> The rules `make fast` and `make bfast` take advantage of parallel compilation to build the mandatory and bonus part, respectively. 

To launch the executable you should follow this syntax...

```sh
$ ./miniRT scene_name
```

Where `scene_name` is the name of a file that represents the world map. The scene must have a `.rt` extension. You can find example scenes in the `scenes` folder.

> **Warning**
> On the macOS mlx version, the `mlx_destroy_display` function does not exist, which will cause a compilation error, unless you comment it (`world.c` and `world_bonus.c`)

## 🕹️ **Controls**

Mandatory:
- **W** - increments the camera y coordinate
- **A** - decrements the camera x coordinate
- **S** - decrements the camera y coordinate
- **D** - increments the camera x coordinate

Bonus:
- **M** - toggles/untoggles the menu, which displays several other commands you can try

## 💫 **Testing**

This project was tested using self-made tests.

---
> Feel free to ask me any questions through Slack (**maricard**). <br>
> GitHub [@maricard18](https://github.com/maricard18) &nbsp;&middot;&nbsp;
> Linkedin [Mario Henriques](https://www.linkedin.com/in/mario18) &nbsp;&middot;&nbsp;
> [42 Porto](https://www.42porto.com/en)
