# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 14:52:51 by nle-roux          #+#    #+#              #
#    Updated: 2024/01/20 21:48:29 by nle-roux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= clang
CFLAGS		= -Wall -Werror -Wextra -g -gdwarf-4
NAME		= pipex
BONUS_CALL	= 0

MANDATORY	= main utils ft_pipex ft_execve
BONUS		= $(addsuffix _bonus, $(MANDATORY))

SRCS_M		= $(addsuffix .c, $(addprefix mandatory/, $(MANDATORY)))
SRCS_B		= $(addsuffix .c, $(addprefix bonus/, $(BONUS)))

OBJS_M		= $(SRCS_M:.c=.o)
OBJS_B		= $(SRCS_B:.c=.o)

# -- rules -- #
%.o: %.c
	$(CC) $(CFLAGS) -Ilibft -Imandatory -Ibonus -c $< -o $@

$(NAME): $(OBJS_M)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS_M) -L./libft -lft -o $(NAME)

all: $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJS_M) $(OBJS_B)

fclean:
	make -C libft fclean
	rm -f $(OBJS_M) $(OBJS_B) $(NAME)

re: fclean all

bonus: $(OBJS_B)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS_B) -L./libft -lft -o $(NAME)

.PHONY: all clean fclean re bonus
