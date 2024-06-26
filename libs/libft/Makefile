# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 17:06:10 by inwagner          #+#    #+#              #
#    Updated: 2024/05/18 11:37:13 by maalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAMES
NAME	:=	libft.a

# FLAGS
HDR		:=	-I ./incl/
CFLAG	:=	-Wall -Wextra -Werror

# PATHS
SRC		:=	./srcs/
OSRC	:=	./objs/

# MANDATORY
FTS		:=	ft_abs.c \
			ft_atoi.c \
			ft_atof.c \
			ft_atol.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isblank.c \
			ft_isdigit.c \
			ft_isgraph.c \
			ft_islower.c \
			ft_isprint.c \
			ft_ispunct.c \
			ft_isspace.c \
			ft_isupper.c \
			ft_isxdigit.c \
			ft_is_numeric_string.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_strcspn.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strspn.c \
			ft_strtok.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			get_next_line.c

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