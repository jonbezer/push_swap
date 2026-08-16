/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 13:54:59 by jonbezer          #+#    #+#             */
/*   Updated: 2026/08/16 18:55:23 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_config	config;
	t_stats		stats;
	int			disorder;

	if (argc < 2)
		return (0);
	ft_bzero(&stats, sizeof(t_stats));
	stack_a = (t_stack){NULL, NULL, 0, 1, &stats};
	stack_b = (t_stack){NULL, NULL, 0, 1, &stats};
	config = (t_config){0, 1, STRAT_ADAPTIVE};
	if (!ft_parse_args(argc, argv, &stack_a, &config))
		return (write(2, "Error\n", 6), 1);
	if (stack_a.size > 1)
	{
		ft_assign_index(&stack_a);
		disorder = ft_compute_disorder(&stack_a);
		ft_execute_strategy(&stack_a, &stack_b, &config, disorder);
		if (config.bench)
			ft_print_bench(disorder, &config, &stats, 2);
	}
	ft_clear_stack(&stack_a);
	ft_clear_stack(&stack_b);
	return (0);
}
