HEADER = includes/minirt.h

NAME = miniRT
NAME_B = miniRT_bonus

M_SRCS = mandatory/main.c mandatory/get_next_line.c mandatory/allocation.c \
    mandatory/tools.c mandatory/parse_element.c mandatory/parse.c \
    mandatory/split.c mandatory/vector.c mandatory/normal_vector.c \
    mandatory/vector2.c mandatory/ray_tracing.c mandatory/parse_objects.c \
    mandatory/Garbage_Collector.c mandatory/intersection.c mandatory/mlx_func.c \
    mandatory/camera.c mandatory/color.c mandatory/surface_normale.c \
    mandatory/world.c mandatory/split_utils.c mandatory/shading.c

B_SRCS = bonus/main.c bonus/get_next_line.c bonus/allocation.c \
    bonus/tools.c bonus/parse_element.c bonus/parse.c \
    bonus/split.c bonus/vector.c bonus/normal_vector.c \
    bonus/vector2.c bonus/ray_tracing.c bonus/parse_objects.c \
    bonus/Garbage_Collector.c bonus/intersection.c bonus/mlx_func.c \
    bonus/camera.c bonus/color.c bonus/surface_normale.c \
    bonus/world.c bonus/split_utils.c bonus/cone_intersection.c \
    bonus/specular.c bonus/shading.c

CFLAGS = -Wall -Wextra -Werror

LMLX_FLAG = -L ./minilibx_opengl libmlx.a -L ./minilibx_mms_20200219 libmlx.dylib -framework OpenGL -framework AppKit


CC = gcc

OBJS_M = $(M_SRCS:.c=.o)
OBJS_B = $(B_SRCS:.c=.o)

all: $(NAME)

bonus: $(NAME_B)

$(NAME): $(OBJS_M) $(HEADER)
	@$(CC) -lmlx -lX11 -lXext $(CFLAGS) $(LMLX_FLAG) $(OBJS_M) -o $(NAME)

$(NAME_B): $(OBJS_B) $(HEADER)
	@$(CC) -lmlx -lX11 -lXext $(CFLAGS) $(OBJS_B) -o $(NAME_B)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_M) $(OBJS_B)

fclean: clean
	@rm -rf $(NAME) $(NAME_B)

re: fclean $(NAME) clean
re_b: fclean $(NAME_B) clean

.PHONY: all $(NAME) $(NAME_B) clean fclean re
