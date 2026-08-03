/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 10:14:38 by jonbezer          #+#    #+#             */
/*   Updated: 2026/08/03 11:24:13 by jonbezer         ###   ########.fr       */
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
	first->prev = stack->tail;
	stack->tail->next = first;
	stack->tail = first;
}

void	ft_rotate_ra(t_stack *stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	ft_rotate_rb(t_stack *stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	ft_rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}
