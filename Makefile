# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 11:14:04 by yujelee           #+#    #+#              #
#    Updated: 2022/11/02 13:24:27 by yujelee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all

RM			= 	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -MMD -MP 
CPPFLAGS	= 	-Imlx
LDFLAGS		=	-Lmlx -framework OpenGL -framework AppKit
LDLIBS 		=	-lmlx

OUTDIR		=	out/


SRCS = 	\
		ft/ft_atoi.c		\
		ft/ft_calloc.c		\
		ft/ft_split.c		\
		ft/ft_strs.c		\
		ft/get_next_line.c		\
		ft/get_next_line_utils.c	\
		control_error.c		\
		utils.c				\
		fdf.c				\
		manage_map.c		\
		manage_coordn.c		\
		parsing.c			\
		drawing.c			\
		drawing_utils.c		\
		hooks.c

Q = @
ifdef DEBUG
	Q = 
endif

NAME = fdf

OBJS		=	$(addprefix $(OUTDIR),$(SRCS:%.c=%.o))
DEPS		=	$(addprefix $(OUTDIR),$(SRCS:%.c=%.d))
-include $(DEPS)

$(OUTDIR)%.o : %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

all : $(NAME)

$(NAME) : $(OBJS)
	$Q$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean :
	$Q$(RM) $(OUTDIR)

fclean : clean
	$Q$(RM) $(NAME)
	
re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
