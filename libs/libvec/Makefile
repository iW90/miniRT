# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 00:31:29 by maalexan          #+#    #+#              #
#    Updated: 2024/05/25 14:02:31 by inwagner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# NAMES
NAME	:=	libvector.a

# FLAGS
HDR		:=	-I ./incl/
CFLAG	:=	-Wall -Wextra -Werror

# PATHS
SRC		:=	./srcs/
OSRC	:=	./objs/

# MANDATORY
FTS		:=	normalize.c \
			vector_add.c \
			vector_create.c \
			vector_cross.c \
			vector_diff.c \
			vector_div.c \
			vector_div_self.c \
			vector_dot.c \
			vector_is_equal.c \
			vector_lenght.c \
			vector_lenght_squared.c \
			vector_mult.c \
			vector_mult_self.c \
			vector_negate_self.c \
			vector_product.c \
			vector_project.c \
			vector_reflect.c \
			vector_sub.c \
			vector_sum.c \
			vector_sum_self.c \
			vector_unit.c \

OBJ		:=	$(addprefix $(OSRC), $(FTS:.c=.o))

# cmds
all: $(NAME)

# Compile Objects
$(NAME): $(OBJ)
	@ar -rcs ../$(NAME) $(OBJ)

# Make Objects
$(OSRC)%.o: $(SRC)%.c
	@mkdir -p objs
	@cc $(CFLAG) $(HDR) -c $< -o $@

clean:
	@[ -d $(OSRC) ] && rm -rf $(OSRC) || [ -f Makefile ]

fclean:	clean
	@[ -f ../$(NAME) ] && rm ../$(NAME) && echo $(NAME) cleaned ||  [ -f Makefile ]

re: fclean all

.PHONY: all clean fclean re