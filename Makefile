# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/27 14:56:48 by aquan             #+#    #+#              #
#    Updated: 2018/12/30 17:48:42 by aquan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

SRCS		=	key_hook.c main.c ft_line.c ft_mouse_event.c red_cross.c ft_mouse_move.c check.c

OBJS		=	$(SRCS:.c=.o)

LIBFT_PATH 	=	Libft/
LIB			=	$(LIBFT_PATH)libft.a

LIBMLX_PATH		=	minilibx_macos/
LIBMLX			=	$(LIBMLX_PATH)libmlx.a

HDR		=	fdf.h

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

MLXFLAGS = -framework OpenGL -framework AppKit

RM		=	rm -rf

CLEAN	=	clean

all		:	$(NAME)

$(LIB) : 
	@make -C $(LIBFT_PATH) #--no-print-directory

$(LIBMLX) :
	@make -C $(LIBMLX_PATH) 

$(NAME)	:	$(OBJS) $(HDR) $(LIB) $(LIBMLX) 
	@$(CC) $(LIB) $(LIBMLX) -o $(NAME) $(SRCS) -I $(HDR) $(MLXFLAGS) 

clean	:
	$(RM) $(OBJS)
	@make -C $(LIBFT_PATH) clean
	@make -C $(LIBMLX_PATH) clean

fclean	:	clean
	$(RM) $(NAME) $(LIB) $(LIBMLX)

re		:	fclean all

run		: $(NAME)
	./fdf
