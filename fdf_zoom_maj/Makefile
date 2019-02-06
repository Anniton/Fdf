# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/30 15:08:14 by cmoulini          #+#    #+#              #
#    Updated: 2019/02/06 19:37:37 by aquan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

LIBFT_PATH	=	libft/
LIB		=	$(LIBFT_PATH)/libft.a

LMLX_PATH	=	minilibx_macos/
LMLX	=	$(LMLX_PATH)/libmlx.a

SRCS	=	check_sample.c \
		   	main.c \
			get_int_tab.c 	\
			ligne.c \
			black.c	\
			print.c	\
			close_event.c\
			bresenham.c\

OBJS	=	$(SRCS:.c=.o)

HDR		=	fdf.h

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g -fsanitize=address -fno-omit-frame-pointer

FRAMEWORKS	=	-framework OpenGL -framework AppKit

RM		=	rm -f

CLEAN	=	clean

all		:	$(NAME)

$(LIB)	:
			@make -C $(LIBFT_PATH)

$(LMLX)		:	
			@make -C $(LMLX_PATH)

$(NAME)	:	$(OBJS) $(HDR) $(LIB) $(LMLX)
			@$(CC) $(CFLAGS) $(LIB) $(LMLX) -o $(NAME) $(SRCS) -I $(HDR) $(FRAMEWORKS)

clean	:
			@$(RM) $(OBJS)
			@make clean -C $(LIBFT_PATH)
			@make clean -C $(LMLX_PATH)

fclean	:	clean
			@$(RM) $(NAME) $(LIB) $(LMLX)

re		:	fclean all

.PHONY:	all clean fclean re
