# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 11:14:04 by yujelee           #+#    #+#              #
#    Updated: 2022/08/29 20:10:41 by yujelee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror 

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
		hooks.c				\
		hook_utils.c

NAME = fdf

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	
re : 
	make fclean
	make all

.PHONY: all clean fclean re