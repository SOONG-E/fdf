# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 11:14:04 by yujelee           #+#    #+#              #
#    Updated: 2022/08/25 16:02:52 by yujelee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRCS = 	control_error.c		\
		fdf.c				\
		ft_atoi.c			\
		ft_calloc.c			\
		ft_split.c			\
		ft_strs.c			\
		get_next_line.c		\
		get_next_line_utils.c	\
		manage_map.c		\
		manage_window.c		\
		manage_coordn.c		\
		parsing.c			\
		print.c				\
		utils.c
		#print  ㅈㅣ우기 stdio.h Makefile


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