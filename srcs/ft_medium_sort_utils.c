/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 17:53:49 by jonbezer          #+#    #+#             */
/*   Updated: 2026/08/13 17:53:54 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_square(int n)
{
	int	x;

	x = 1;
	while (x * x < n)
		x++;
	return (x);
}

void	ft_from_bottom(t_stack *stack_b, int i)
{
	int	j;

	j = stack_b->size - i;
	while (j > 0)
	{
		ft_rev_rotate_rrb(stack_b);
		j--;
	}
}

void	ft_from_top(t_stack *stack_b, int i)
{
	int	j;

	j = i;
	while (j > 0)
	{
		ft_rotate_rb(stack_b);
		j--;
	}
}
