# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/30 15:08:14 by cmoulini          #+#    #+#              #
#    Updated: 2019/01/09 12:19:29 by aquan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

LIBFT_PATH	=	libft/
LIB		=	$(LIBFT_PATH)/libft.a

LMLX_PATH	=	minilibx_macos/
LMLX	=	$(LMLX_PATH)/libmlx.a

SRCS	=	key_event.c close.c get_int_tab.c check_sample.c main.c ligne.c axonometrie.c isometrie.c view_event.c
OBJS	=	$(SRCS:.c=.o)

HDR		=	fdf.h

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra

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
