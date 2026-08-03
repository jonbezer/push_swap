/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 12:37:05 by jonbezer          #+#    #+#             */
/*   Updated: 2026/08/03 14:40:47 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_compute_disorder(t_stack *stack_a)
{
	int		inv;
	int		dis;
	int		pairs;
	t_node	*current_node;
	t_node	*inner_node;

	if (!stack_a || !stack_a->head || stack_a->size < 2)
		return (0);
	inv = 0;
	pairs = 0;
	current_node = stack_a->head;
	while (current_node && current_node->next)
	{
		inner_node = current_node->next;
		while (inner_node)
		{
			if (current_node->value > inner_node->value)
				inv++;
			pairs++;
			inner_node = inner_node->next;
		}
		current_node = current_node->next;
	}
	dis = ((long)inv * 10000) / (long)pairs;
	return ((int)dis);
}

void	ft_print_disorder(int dis, int fd)
{
	ft_putstr_fd("[bench] disorder: ", fd);
	ft_putnbr_fd(dis / 100, fd);
	ft_putchar_fd('.', fd);
	if ((dis % 100) < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(dis % 100, fd);
	ft_putchar_fd('%', fd);
	ft_putchar_fd('\n', fd);
}
