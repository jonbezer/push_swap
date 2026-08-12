/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 11:28:02 by jonbezer          #+#    #+#             */
/*   Updated: 2026/08/12 16:49:45 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_bitslen(int max_index)
{
	int	bits;

	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

void	ft_complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	len_bits;
	int	size;
	int	loop_bits;
	int	loop_node;

	if (!stack_a || stack_a->size < 2)
		return ;
	len_bits = ft_bitslen(stack_a->size - 1);
	loop_bits = -1;
	while (++loop_bits < len_bits)
	{
		size = stack_a->size;
		loop_node = -1;
		while (++loop_node < size)
		{
			if (((stack_a->head->index >> loop_bits) & 1) == 0)
				ft_push_pb(stack_a, stack_b);
			else
				ft_rotate_ra(stack_a);
		}
		while (stack_b->size > 0)
			ft_push_pa(stack_a, stack_b);
	}
}


