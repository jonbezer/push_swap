/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:36:29 by jonbezer          #+#    #+#             */
/*   Updated: 2026/08/10 19:12:51 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int				index;
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

typedef enum	e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef struct	s_config
{
	int			bench;
	t_strategy	strategy;
}	t_config;

/* Validation Utils (srcs/ft_validations.c) */
int		ft_is_number(char *str);
long	ft_atol(char *str);
int		ft_is_in_range(long num);
int		ft_has_duplicate(t_node *stack, int num);

/* Stack Management (srcs/ft_stack_utils.c) */
t_node	*ft_create_node(int value);
void	ft_add_back(t_stack *stack, t_node *new_node);
void	ft_clear_stack(t_stack *stack);

/* Parser (srcs/ft_parser.c) */
int		ft_parse_args(int argc, char **argv, 
		t_stack *stack_a, t_config *config);

/* Operations SWAP (srcs/ft_swap.c) */
void	ft_swap_sa(t_stack *stack_a);
void	ft_swap_sb(t_stack *stack_b);
void	ft_swap_ss(t_stack *stack_a, t_stack *stack_b);

/* Operations PUSH (srcs/ft_push.c) */
void	ft_push_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_push_pb(t_stack *stack_a, t_stack *stack_b);

/* Oparations ROTATE (srcs/ft_rotate.c */
void	ft_rotate_ra(t_stack *stack_a);
void	ft_rotate_rb(t_stack *stack_b);
void	ft_rotate_rr(t_stack *stack_a, t_stack *stack_b);

/* Operations REVERSE ROTATE (srcs/ft_rev_rotate.c */
void	ft_rev_rotate_rra(t_stack *stack_a);
void	ft_rev_rotate_rrb(t_stack *stack_b);
void	ft_rev_rotate_rrr(t_stack *stack_a, t_stack *stack_b);

/* Compute Disorder */
int		ft_compute_disorder(t_stack *stack_a);
void	ft_print_disorder(int dis, int fd);

/* Index Assignment (srcs/ft_assign_index.c) */
void	ft_assign_index(t_stack *stack_a);

/* Sorting Strategies */
void	ft_simple_sort(t_stack *stack_a, t_stack *stack_b);
void	ft_medium_sort(t_stack *stack_a, t_stack *stack_b);
void	ft_complex_sort(t_stack *stack_a, t_stack *stack_b);

/* Main (srcs/main.c) */
int		main(int argc, char **argv);

#endif
