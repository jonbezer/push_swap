/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 10:14:38 by jonbezer          #+#    #+#             */
/*   Updated: 2026/08/14 17:08:19 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack *stack)
{
	t_node	*first;

	if (!stack || !stack->head || stack->size < 2)
		return ;
	first = stack->head;
	stack->head = first->next;
	stack->head->prev = NULL;
	first->next = NULL;
	first->prev = stack->tail;
	stack->tail->next = first;
	stack->tail = first;
}

void	ft_rotate_ra(t_stack *stack_a)
{
	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return ;
	ft_rotate(stack_a);
	if (stack_a->print_ops)
		write(1, "ra\n", 3);
	if (stack_a->stats)
	{
		stack_a->stats->ra++;
		stack_a->stats->total++;
	}
}

void	ft_rotate_rb(t_stack *stack_b)
{
	if (!stack_b || !stack_b->head || !stack_b->head->next)
		return ;
	ft_rotate(stack_b);
	if (stack_b->print_ops)
		write(1, "rb\n", 3);
	if (stack_b->stats)
	{
		stack_b->stats->rb++;
		stack_b->stats->total++;
	}
}

void	ft_rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	int	verify_a;
	int	verify_b;

	verify_a = (stack_a && stack_a->head && stack_a->head->next);
	verify_b = (stack_b && stack_b->head && stack_b->head->next);
	if (!verify_a && !verify_b)
		return ;
	if (verify_a)
		ft_rotate(stack_a);
	if (verify_b)
		ft_rotate(stack_b);
	if (stack_a->print_ops)
		write(1, "rr\n", 3);
	if (stack_a && stack_a->stats)
	{
		stack_a->stats->rr++;
		stack_a->stats->total++;
	}
}
