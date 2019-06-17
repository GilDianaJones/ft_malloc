# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gthomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 15:18:38 by gthomas           #+#    #+#              #
#    Updated: 2019/01/02 14:31:40 by gthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_memccpy.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_strcat.c \
	   ft_strchr.c \
	   ft_strcmp.c \
	   ft_strcpy.c \
	   ft_strdup.c \
	   ft_strlcat.c \
	   ft_strlen.c \
	   ft_strncat.c \
	   ft_strncmp.c \
	   ft_strncpy.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_strclr.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strsub.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_strsplit.c \
	   ft_itoa.c \
	   ft_putendl.c \
	   ft_putnbr.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_lstnew.c \
	   ft_lstdelone.c \
	   ft_lstdel.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_swap.c \
	   ft_swap_ptr.c \
	   ft_sqrt.c \
	   ft_power.c \
	   ft_lstaddend.c \
	   ft_strconcat.c \
	   ft_strichr.c \
	   ft_strcopy.c \
	   ft_intlen.c \
	   ft_stristr.c \
	   ft_ptrlen.c \
	   ft_realloc_int.c \
	   get_str_before.c \
	   get_nb_char.c \
	   ft_strichr_last.c \
	   ft_strichr_nb.c \
	   ft_strichr_cnt.c \
	   ft_stristr_eq.c \
	   ft_lstcnt.c \
	   ft_lstend.c \
	   ft_stritabstr.c \
	   ft_lststrstr.c \
	   ft_putnbr_hex.c \
	   ft_lprintf.c \
	   ft_wnbchar.c \
	   ft_wnbcharnl.c \
	   ft_realloc.c \
	   get_next_line.c \
	   ft_freeandnil.c \
	   ft_align.c


OBJS = $(SRCS:.c=.o)

HEADER = ./includes

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	gcc -c $< -o $@ -Wall -Werror -Wextra -I$(HEADER)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
