/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rav_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 11:24:28 by jonbezer          #+#    #+#             */
/*   Updated: 2026/08/03 11:46:52 by jonbezer         ###   ########.fr       */
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
	ft_rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	ft_rev_rotate_rrb(t_stack *stack_b)
{
	ft_rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	ft_rev_rotate_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
