/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:10:02 by jonbezer          #+#    #+#             */
/*   Updated: 2026/07/29 10:09:17 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack *src, t_stack *dest)
{
	t_node	*top_node;

	if (!src || !dest || !src->head)
		return ;
	top_node = src->head;
	src->head = src->head->next;
	if (src->head)
		src->head->prev = NULL;
	else
		src->tail = NULL;
	src->size--;
	top_node->next = dest->head;
	top_node->prev = NULL;
	if (dest->head)
		dest->head->prev = top_node;
	else
		dest->tail = top_node;
	dest->head = top_node;
	dest->size++;
}

void	ft_push_pa(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ft_push_pb(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
