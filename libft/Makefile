# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahouel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 08:37:55 by ahouel            #+#    #+#              #
#    Updated: 2017/04/18 14:36:12 by ahouel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
NAME = libft.a
VPATH = ./srcs/
HDIR = ./includes
FCTS = ft_memset ft_bzero ft_memcpy ft_memccpy \
	   ft_memmove ft_memchr ft_memrchr ft_memcmp \
	   ft_strlen ft_strdup ft_strndup ft_strcpy \
	   ft_strncpy ft_strcat ft_strncat ft_strlcat \
	   ft_strchr ft_strrchr ft_strstr ft_strnstr \
	   ft_strcmp ft_strncmp ft_atoi ft_isalpha \
	   ft_isdigit ft_isalnum ft_isascii ft_isprint \
	   ft_toupper ft_tolower ft_memalloc ft_memdel \
	   ft_strnew ft_strdel ft_strclr ft_striter \
	   ft_striteri ft_strmap ft_strmapi ft_strequ \
	   ft_strnequ ft_strsub ft_strjoin ft_strtrim \
	   ft_strsplit ft_itoa ft_putchar ft_putstr \
	   ft_putendl ft_putnbr ft_putchar_fd ft_putstr_fd \
	   ft_putendl_fd ft_putnbr_fd ft_lstnew ft_lstdelone \
	   ft_lstdel ft_lstadd ft_lstiter ft_lstmap \
	   ft_swap ft_sqrt ft_cswap ft_strrev ft_div_mod \
	   ft_factorial ft_putlst get_next_line \
	   ft_lldtoa_base ft_ulldtoa_base ft_wctomb \
	   ft_wstrtostr ft_wstrlen ft_strnlen ft_abs \
	   ft_stradd ft_memjoin \
	   ft_printf pf_args pf_get_convert pf_get_flags \
	   pf_get_lenght pf_get_precision pf_get_width \
	   pf_convert_nbr pf_convert_char pf_convert_ptr \
	   pf_apply_flag pf_apply_precision pf_apply_width \
	   pf_apply_color pf_memjoin2 pf_dispatch_convert
SRCS = $(addsuffix .c, $(FCTS))
SRC = $(addprefix $(VPATH), $(SRCS))
OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(CFLAGS) -I $(HDIR) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
