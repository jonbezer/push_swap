/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 11:24:28 by jonbezer          #+#    #+#             */
/*   Updated: 2026/08/14 17:12:03 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rev_rotate(t_stack *stack)
{
	t_node	*last;

	if (!stack || !stack->head || stack->size < 2)
		return ;
	last = stack->tail;
	stack->tail = last->prev;
	stack->tail->next = NULL;
	last->prev = NULL;
	last->next = stack->head;
	stack->head->prev = last;
	stack->head = last;
}

void	ft_rev_rotate_rra(t_stack *stack_a)
{
	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return ;
	ft_rev_rotate(stack_a);
	if (stack_a->print_ops)
		write(1, "rra\n", 4);
	if (stack_a->stats)
	{
		stack_a->stats->rra++;
		stack_a->stats->total++;
	}
}

void	ft_rev_rotate_rrb(t_stack *stack_b)
{
	if (!stack_b || !stack_b->head || !stack_b->head->next)
		return ;
	ft_rev_rotate(stack_b);
	if (stack_b->print_ops)
		write(1, "rrb\n", 4);
	if (stack_b->stats)
	{
		stack_b->stats->rrb++;
		stack_b->stats->total++;
	}
}

void	ft_rev_rotate_rrr(t_stack *stack_a, t_stack *stack_b)
{
	int	verify_a;
	int	verify_b;

	verify_a = (stack_a && stack_a->head && stack_a->head->next);
	verify_b = (stack_b && stack_b->head && stack_b->head->next);
	if (!verify_a && !verify_b)
		return ;
	if (verify_a)
		ft_rev_rotate(stack_a);
	if (verify_b)
		ft_rev_rotate(stack_b);
	if (stack_a->print_ops)
		write(1, "rrr\n", 4);
	if (stack_a && stack_a->stats)
	{
		stack_a->stats->rrr++;
		stack_a->stats->total++;
	}
}
