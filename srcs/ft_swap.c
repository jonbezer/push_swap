/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 15:06:58 by jonbezer          #+#    #+#             */
/*   Updated: 2026/07/26 16:30:33 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_node **stack)
{
	t_node	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
}

void	ft_swap_sa(t_node **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void	ft_swap_sb(t_node **stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ft_swap_ss(t_node **stack_a, t_node **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}
