# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonbezer <jonbezer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/26 13:41:22 by jonbezer          #+#    #+#              #
#    Updated: 2026/08/16 18:44:56 by jonbezer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -I includes -I libft

SRCS = srcs/main.c \
       srcs/parser/ft_parser.c \
       srcs/parser/ft_validations.c \
       srcs/algorithms/ft_execute_strategy.c \
       srcs/algorithms/ft_simple_sort.c \
       srcs/algorithms/ft_medium_sort.c \
       srcs/algorithms/ft_medium_sort_utils.c \
       srcs/algorithms/ft_complex_sort.c \
       srcs/operations/ft_swap.c \
       srcs/operations/ft_push.c \
       srcs/operations/ft_rotate.c \
       srcs/operations/ft_rev_rotate.c \
       srcs/utils/ft_stack_utils.c \
       srcs/utils/ft_assign_index.c \
       srcs/utils/ft_disorder.c \
       srcs/utils/ft_print_bench.c \
       srcs/utils/ft_is_sorted.c

LIBFT = libft/libft.a

HEADER = includes/push_swap.h

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
