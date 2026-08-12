/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 19:02:37 by jonbezer          #+#    #+#             */
/*   Updated: 2026/08/12 19:59:59 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_square(int n)
{
	int	x;

	x = 1;
	while (x * x < n)
		x++;
	if (x * x == n)
		return(x);
	return(x - 1);
}

void	ft_bucket_sort_b(t_stack *stack_a, t_stack *stack_b, int buckets)
{
	int		i;
	int		j;
	int		x;
	int		current_range;

	i = stack_b->size - 1;
	j = 0;
	x = 0;
	current_range = i;
	while (stack_b && stack_b->head)
	{
		while (i > current_range - buckets)
		{
			while(j <= buckets)
			{
				if (stack_b->head && (stack_b->head->index == i))
				{
					ft_push_pa(stack_a, stack_b);
					i--;
					j++;
					x++;
				}
				else	
				{
					ft_rotate_rb(stack_b);
					j++;
				}
			}
			while(stack_b->tail && (stack_b->tail->index > current_range - buckets))
			{
				ft_rev_rotate_rrb(stack_b);
				j--;
			}
			j = j + x;
			if (i == current_range - buckets)
			{
				current_range = current_range - buckets;
				j = 0;
			}
		}	
	}
	return;
}

void	ft_bucket_sort(t_stack *stack_a, t_stack *stack_b, int buckets)
{
	int		i;
	int		current_range;
	
	i = 0;
	current_range = 0;
	while(stack_a && stack_a->head)
	{
		while (i < current_range + buckets)
		{
			if(stack_a->head->index < current_range + buckets)
			{
				ft_push_pb(stack_a, stack_b);
				i++;
			}
			else 
				ft_rotate_ra(stack_a);
		}
		current_range = current_range + buckets;
	}
	return;
}

void	ft_medium_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	buckets;
	int	rest;
	int	max_index;

	if (!stack_a || stack_a->size < 2)
		return;
	max_index = stack_a->size - 1;
	buckets = ft_square(stack_a->size);
	rest	= stack_a->size % buckets;
	ft_assign_index(stack_a);
	ft_bucket_sort(stack_a, stack_b, buckets);
	ft_bucket_sort_b(stack_a, stack_b, buckets);	
}
