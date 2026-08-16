/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 15:06:58 by jonbezer          #+#    #+#             */
/*   Updated: 2026/08/14 17:06:49 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack *stack)
{
	int	temp_value;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	temp_value = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp_value;
}

void	ft_swap_sa(t_stack *stack_a)
{
	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return ;
	ft_swap(stack_a);
	if (stack_a->print_ops)
		write(1, "sa\n", 3);
	if (stack_a->stats)
	{
		stack_a->stats->sa++;
		stack_a->stats->total++;
	}
}

void	ft_swap_sb(t_stack *stack_b)
{
	if (!stack_b || !stack_b->head || !stack_b->head->next)
		return ;
	ft_swap(stack_b);
	if (stack_b->print_ops)
		write(1, "sb\n", 3);
	if (stack_b->stats)
	{
		stack_b->stats->sb++;
		stack_b->stats->total++;
	}
}

void	ft_swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	int	verify_a;
	int	verify_b;

	verify_a = (stack_a && stack_a->head && stack_a->head->next);
	verify_b = (stack_b && stack_b->head && stack_b->head->next);
	if (!verify_a && !verify_b)
		return ;
	if (verify_a)
		ft_swap(stack_a);
	if (verify_b)
		ft_swap(stack_b);
	if (stack_a->print_ops)
		write(1, "ss\n", 3);
	if (stack_a && stack_a->stats)
	{
		stack_a->stats->ss++;
		stack_a->stats->total++;
	}
}
