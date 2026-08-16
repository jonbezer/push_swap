/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 11:21:32 by jonbezer          #+#    #+#             */
/*   Updated: 2026/08/10 19:09:30 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assign_index(t_stack *stack_a)
{
	t_node	*current;
	t_node	*compare;
	int		count_index;

	if (!stack_a || !stack_a->head)
		return ;
	current = stack_a->head;
	while (current)
	{
		count_index = 0;
		compare = stack_a->head;
		while (compare)
		{
			if (compare->value < current->value)
				count_index++;
			compare = compare->next;
		}
		current->index = count_index;
		current = current->next;
	}
}
