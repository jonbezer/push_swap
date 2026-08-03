/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 13:20:21 by jonbezer          #+#    #+#             */
/*   Updated: 2026/07/31 19:55:00 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;

	if (argc < 2)
		return (0);
	stack_a.head = NULL;
	stack_a.tail = NULL;
	stack_a.size = 0;
	if (!ft_parse_args(argc, argv, &stack_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ft_clear_stack(&stack_a);
	return (0);
}
