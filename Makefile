# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 19:37:25 by maalexan          #+#    #+#              #
#    Updated: 2024/03/25 21:48:40 by maalexan         ###   ########.fr        #
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

# Compilation flags
CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -g -I $(HDR_DIR)
BCFLAGS		:=	-Wall -Wextra -Werror -g -I ./bonus/incl
LDFLAGS		:=	-lX11 -lglfw -lGL -lXext -lm -ldl

# Source files
FUN			:=	main.c \
				etcs/exit_hook.c \
				etcs/exit_program.c \
				etcs/object_list.c \
				render/color.c \
				render/intersecs.c \
				render/ray_cast.c \
				render/render.c \
				math/util_math.c \
				math/vec3f.c \
				parser/validations.c \
				parser/validations_getters.c \
				parser/validations_object.c \
				parser/validations_scene.c \
				parser/validations_utils.c \

# Object files
OBJ			:=	$(FUN:%.c=$(OBJ_DIR)/%.o)
BOBJ		:=	$(BFUN:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(MLXLIB) $(FTLIB) $(OBJ)
	$(CC) $(OBJ) $(FTLIB) $(MLXLIB) $(LDFLAGS) -o $@

$(FTLIB):
	@$(MAKE) -C $(FTLIB_DIR) --silent

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
#	@[ -f $(MLXLIB) ] && rm $(MLXLIB) || [ -f Makefile ]
	@[ -d ./incl/mlx ] && rm -rf ./incl/mlx || [ -f Makefile ]
	@[ -f ./$(NAME) ] && rm $(NAME) || echo Program $(NAME) isn\'t compiled
	@[ -f ./$(NAMEB) ] && rm $(NAMEB)|| echo Bonus $(NAMEB) isn\'t compiled

re: fclean all

.PHONY: all bonus clean fclean re
