# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahouel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 08:37:55 by ahouel            #+#    #+#              #
#    Updated: 2017/04/20 16:07:22 by ahouel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME = FdF
F_PATH = ./srcs/
FL_PATH = ./libft/srcs/
HDIR = ./includes
LHDIR = ./libft/includes
FCTS = fdf fdf_imap fdf_map main fdf_strjoin fdf_drawer
LFCTS = ft_printf ft_strnew 
SRCS = $(addsuffix .c, $(FCTS))
SRC = $(addprefix $(F_PATH), $(SRCS))
OBJ = $(SRCS:.c=.o)
LSRCS = $(addsuffix .c, $(LFCTS))
LSRC = $(addprefix $(FL_PATH), $(LSRCS))
LOBJ = $(LSRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SRC) $(LSRC)
	@echo "Compilation de la lib..."
	@make -C libft/ fclean && make -C libft/
	@echo "Compilation de la mlx..."
	@make -C minilibx_macos/ clean && make -C minilibx_macos
	@echo "Compilation de FdF..."
	@clang $(CFLAGS) -I$(HDIR) -I./minilibx_macos -I$(LHDIR) -c $(SRC)
	@clang $(CFLAGS) -L./libft/ -lft -L./minilibx_macos -lmlx -framework OpenGL -framework Appkit $(OBJ) -o $(NAME)

clean :
	@rm -f $(OBJ) $(LOBJ)
	@rm -f main.o
	@make -C libft/ fclean
	@make -C minilibx_macos/ clean

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
