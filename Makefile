# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 11:14:04 by yujelee           #+#    #+#              #
#    Updated: 2022/10/13 12:54:02 by yujelee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Imlx

SRCS = 	control_error.c		\
		fdf.c				\
		ft/ft_atoi.c		\
		ft/ft_calloc.c		\
		ft/ft_split.c		\
		ft/ft_strs.c		\
		ft/get_next_line.c		\
		ft/get_next_line_utils.c	\
		manage_map.c		\
		manage_coordn.c		\
		parsing.c			\
		drawing.c			\
		drawing_utils.c		\
		utils.c				\
		hooks.c

BONUS_SRC =	ft/ft_atoi.c		\
			ft/ft_calloc.c		\
			ft/ft_split.c		\
			ft/ft_strs.c		\
			ft/get_next_line.c		\
			ft/get_next_line_utils.c	\
 			bonus/control_error.c		\
			bonus/fdf_bonus.c			\
			bonus/manage_map.c		\
			bonus/manage_coordn.c		\
			bonus/parsing.c			\
			bonus/drawing.c			\
			bonus/drawing_utils.c		\
			bonus/utils.c				\
			bonus/hooks.c				\
			bonus/hook_utils.c

Q = @
ifdef DEBUG
	Q = 
endif

NAME = fdf

BONUS_NAME = fdf_bonus

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRC:.c=.o)

all : $(NAME)

bonus : $(BONUS_NAME)

$(NAME) : $(OBJS)
	$Q$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $@

$(BONUS_NAME) : $(BONUS_OBJS)
	$Q$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $@

clean :
	$Q$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	$Q$(RM) $(NAME) $(BONUS_NAME)
	
re : 
	make fclean
	make all

.PHONY: all clean fclean re bonus