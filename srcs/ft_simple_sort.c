/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 22:40:58 by jonbezer          #+#    #+#             */
/*   Updated: 2026/08/13 17:48:33 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack_a)
{
	t_node	*current_node;

	if (!stack_a || !stack_a->head)
		return (1);
	current_node = stack_a->head;
	while (current_node->next)
	{
		if (current_node->value > current_node->next->value)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}

static int	ft_idx_min_stack(t_stack *stack_a)
{
	int		min_idx;
	int		min_value;
	int		current_idx;
	t_node	*current_node;

	if (!stack_a || !stack_a->head)
		return (0);
	min_idx = 0;
	current_idx = 0;
	current_node = stack_a->head;
	min_value = stack_a->head->value;
	while (current_node)
	{
		if (current_node->value < min_value)
		{
			min_value = current_node->value;
			min_idx = current_idx;
		}
		current_idx = current_idx + 1;
		current_node = current_node->next;
	}
	return (min_idx);
}

static void	ft_sort_three(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	if (!stack_a || stack_a->size < 3 || ft_is_sorted(stack_a))
		return ;
	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->tail->value;
	if (first > second && second < third && first < third)
		ft_swap_sa(stack_a);
	else if (first > second && second > third)
	{
		ft_swap_sa(stack_a);
		ft_rev_rotate_rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ft_rotate_ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		ft_swap_sa(stack_a);
		ft_rotate_ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		ft_rev_rotate_rra(stack_a);
}

void	ft_simple_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min_idx;

	if (!stack_a || ft_is_sorted(stack_a))
		return ;
	if (stack_a->size == 2 && !ft_is_sorted(stack_a))
		ft_rotate_ra(stack_a);
	while (stack_a->size > 3)
	{
		min_idx = ft_idx_min_stack(stack_a);
		if (min_idx <= stack_a->size / 2)
		{
			while (min_idx-- > 0)
				ft_rotate_ra(stack_a);
		}
		else
		{
			while (min_idx++ < stack_a->size)
				ft_rev_rotate_rra(stack_a);
		}
		ft_push_pb(stack_a, stack_b);
	}
	ft_sort_three(stack_a);
	while (stack_b->size > 0)
		ft_push_pa(stack_a, stack_b);
}
