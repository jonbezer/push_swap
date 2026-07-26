/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:36:29 by jonbezer          #+#    #+#             */
/*   Updated: 2026/07/26 13:34:43 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node 	*prev;
	struct s_node	*next;
}	t_node;

/* Validation Utils (srcs/ft_validation.c) */
int		ft_is_number(char *str);
long	ft_atol(char *str);
int		ft_is_in_range(long num);
int		ft_has_duplicate(t_node *stack, int num);

/* Stack Management (srcs/ft_stack_utils.c) */
t_node	*ft_create_node(int value);
t_node	*ft_stack_last(t_node *stack);
void	ft_add_back(t_node **stack, t_node *new_node);
size_t	ft_stack_size(t_node *stack);
void	ft_clear_stack(t_node **stack);

/* Parser (srcs/ft_parser.c) */
int	ft_parse_args(int args, char **argv, t_node **stack_a);

/* Functions LIBFT (srcs/ft_split.c) */
char	**ft_split(char const *s, char c);

/* Main (srcs/main.c) */
int	main(int argc, char **argv);

#endif
