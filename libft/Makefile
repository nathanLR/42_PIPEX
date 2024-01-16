# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 11:33:52 by nle-roux          #+#    #+#              #
#    Updated: 2024/01/13 18:32:36 by nle-roux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror -gdwarf-4
NAME	=	libft.a

# -- files -- #
SRCS	=	\
			ft_isalpha.c	ft_isdigit.c	ft_isalnum.c \
			ft_isascii.c	ft_isprint.c	ft_toupper.c \
			ft_tolower.c	ft_strchr.c		ft_strrchr.c \
			ft_strlen.c		ft_strncmp.c	ft_bzero.c	 \
			ft_memset.c		ft_memcpy.c		ft_memmove.c \
			ft_memchr.c		ft_memcmp.c		ft_strnstr.c \
			ft_strlcpy.c	ft_strlcat.c	ft_atoi.c	 \
			ft_calloc.c		ft_strdup.c		ft_isspace.c \
			ft_substr.c		ft_strjoin.c	ft_strtrim.c \
			ft_split.c		ft_itoa.c		ft_strmapi.c \
			ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c \
			ft_putendl_fd.c	ft_putnbr_fd.c	ft_putunbr_fd.c\
			ft_putnbr_base_fd.c	ft_putptr_fd.c	ft_printf.c\
			get_next_line_utilities.c		get_next_line.c\
			get_next_line_multiple.c		ft_atol.c	 \
			ft_strcmp.c		ft_tablen.c		ft_abs.c	 \
			ft_free_tab.c \

BSRCS	=	\
			ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c \
			ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c \
			ft_lstclear.c	ft_lstiter.c		ft_lstmap.c \
			ft_lstpop.c		ft_lstblast.c					\

OBJS	=	$(SRCS:.c=.o)

BOBJS	=	$(BSRCS:.c=.o)

# -- rules -- #
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@ar -rsc $(NAME) $(OBJS)

all		: $(NAME)

clean	:
	@rm -rf $(OBJS) $(BOBJS)

fclean	: clean
	@rm -f $(NAME)

re		: fclean all

bonus	: $(OBJS) $(BOBJS) libft.h
	@ar -rsc $(NAME) $(OBJS) $(BOBJS)

.PHONY	: all clean fclean re bonus
