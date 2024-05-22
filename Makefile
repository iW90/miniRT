# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 19:37:25 by maalexan          #+#    #+#              #
#    Updated: 2024/05/22 19:19:48 by maalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME		:=	miniRT

# Directories for source, object and libraries
SRC_DIR		:=	./srcs
OBJ_DIR		:=	./objs
BSRC_DIR	:=	./bonus/srcs
HDR_DIR		:=	./incl
FTLIB_DIR	:=	./libs/libft
FTLIB		:=	./libs/libft.a
MLXLIB		:=	./libs/libmlx42.a
VECLIB_DIR	:=	./libs/libvec
VECLIB		:=  ./libs/libvector.a

# Compilation flags
CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -g -I $(HDR_DIR)
BCFLAGS		:=	-Wall -Wextra -Werror -g -I ./bonus/incl
LDFLAGS		:=	-lX11 -lglfw -lGL -lXext -lm -ldl

# Source files
FUN			:=	debug.c \
				hit_body_or_cap.c \
				hit_cylinder.c \
				hit_init_quadratic.c \
				hit_init.c \
				hit_list_hittable.c \
				hit_plane.c \
				hit_record_update.c \
				hit_select.c \
				hit_set_normal_face.c \
				hit_sphere.c \
				main.c \
				object_add.c \
				object_ambient_light.c \
				object_clear.c \
				object_default_material.c \
				render_camera_on.c \
				render_core.c \
				render_ray_at.c \
				render_ray_color.c \
				shadow_check.c \
				shadow_lightning.c \
				util_data.c \
				util_print_header.c \
				validate_ambient.c \
				validate_args.c \
				validate_camera.c \
				validate_color.c \
				validate_core.c \
				validate_cylinder.c \
				validate_free_split.c \
				validate_light.c \
				validate_orientation.c \
				validate_plane.c \
				validate_sphere.c \
				window_init_resolution.c \
				window_loop.c \

# Object files
OBJ			:=	$(FUN:%.c=$(OBJ_DIR)/%.o)
BOBJ		:=	$(BFUN:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(MLXLIB) $(FTLIB) $(VECLIB) $(OBJ)
	$(CC) $(OBJ) $(FTLIB) $(VECLIB) $(MLXLIB) $(LDFLAGS) -o $@

$(FTLIB):
	@$(MAKE) -C $(FTLIB_DIR) --silent

$(VECLIB):
	@$(MAKE) -C $(VECLIB_DIR) --silent

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	cc $(CFLAGS) -c $< -o $@

bonus: $(NAMEB)

$(NAMEB): $(BOBJ) $(FTLIB)
	$(CC) $(BOBJ) $(FTLIB) -o $@

$(OBJ_DIR)/%.o: $(BSRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(BCFLAGS) -c $< -o $@

$(MLXLIB):
	git clone https://github.com/codam-coding-college/MLX42.git
	@mkdir -p ./incl/mlx && \
	cd MLX42 && \
	sed -i 's/3.18.0/3.16.0/' CMakeLists.txt && \
	cmake -B build && \
	cmake --build build -j4 && \
	mv build/libmlx42.a ../libs && \
	cp -r include/* ../incl/mlx && \
	cd .. && \
	rm -rf MLX42

val: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes ./${NAME} || echo ""

clean:
	@$(MAKE) -C $(FTLIB_DIR) --silent clean
	@[ -d ./objs ] && rm -rf ./objs || echo Object directory doesn\'t exist

fclean: clean
	@$(MAKE) -C $(FTLIB_DIR) --silent fclean
	@[ -f $(MLXLIB) ] && rm $(MLXLIB) || [ -f Makefile ]
	@[ -d ./incl/mlx ] && rm -rf ./incl/mlx || [ -f Makefile ]
	@[ -f ./$(NAME) ] && rm $(NAME) || echo Program $(NAME) isn\'t compiled
	@[ -f ./$(NAMEB) ] && rm $(NAMEB)|| echo Bonus $(NAMEB) isn\'t compiled

re: fclean all

.PHONY: all bonus clean fclean re
