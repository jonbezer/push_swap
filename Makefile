# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonbezer <jonbezer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/26 13:41:22 by jonbezer          #+#    #+#              #
#    Updated: 2026/08/15 10:41:50 by jonbezer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -I includes -I libft

SRCS = srcs/main.c srcs/ft_parser.c srcs/ft_validations.c srcs/ft_stack_utils.c\
	   srcs/ft_swap.c srcs/ft_push.c srcs/ft_rotate.c srcs/ft_rev_rotate.c\
	   srcs/ft_disorder.c srcs/ft_print_bench.c srcs/ft_simple_sort.c \
	   srcs/ft_assign_index.c srcs/ft_complex_sort.c \
	   srcs/ft_medium_sort_utils.c srcs/ft_medium_sort.c srcs/ft_execute_strategy.c

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
