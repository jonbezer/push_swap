/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:10:02 by jonbezer          #+#    #+#             */
/*   Updated: 2026/07/27 19:51:05 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_node **src_stack, t_node **dest_stack)
{
	t_node	*top_node;

	if (!src_stack || !*src_stack)
		return ;
	top_node = *src_stack;
	src_stack = (*src_stack)->next;
	if (*src_stack)
		*(src_stack)->prev = NULL;
	top_node->next = *dest_stack;
	top_node->prev = NULL;
	if (*dest_stack)
		*(dest->prev) = top_node;
	*dest = top_node;
}

void	ft_push_pa(t_node **stack_a, t_node **stack_b);
{
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ft_push_pb(t_node **stack a, t_node **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
