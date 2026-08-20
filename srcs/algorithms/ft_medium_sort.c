/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 19:02:37 by jonbezer          #+#    #+#             */
/*   Updated: 2026/08/19 20:54:46 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bucket_sort_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		current_index;
	t_node	*current_node;

	current_index = stack_b->size - 1;
	while (stack_b && stack_b->head)
	{
		current_node = stack_b->head;
		i = 0;
		while (current_node->index != current_index)
		{
			current_node = current_node->next;
			i++;
		}
		if (i > (stack_b->size / 2))
			ft_from_bottom(stack_b, i);
		else
			ft_from_top(stack_b, i);
		ft_push_pa(stack_a, stack_b);
		current_index--;
	}
}

void	ft_bucket_sort_to_b(t_stack *stack_a, t_stack *stack_b, int buckets)
{
	int		i;
	int		current_range;

	i = 0;
	current_range = 0;
	while (stack_a && stack_a->head)
	{
		while (stack_a->head && i < current_range + buckets)
		{
			if (stack_a->head->index < current_range + buckets)
			{
				ft_push_pb(stack_a, stack_b);
				i++;
			}
			else
				ft_rotate_ra(stack_a);
		}
		current_range = current_range + buckets;
	}
}

void	ft_medium_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	buckets;

	if (!stack_a || stack_a->size < 2)
		return ;
	buckets = ft_square(stack_a->size);
	ft_assign_index(stack_a);
	ft_bucket_sort_to_b(stack_a, stack_b, buckets);
	ft_bucket_sort_to_a(stack_a, stack_b);
}
