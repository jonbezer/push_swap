/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 13:54:59 by jonbezer          #+#    #+#             */
/*   Updated: 2026/08/14 18:01:12 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_execute_strategy(t_stack *a, t_stack *b, t_config *conf, int dis)
{
	if (conf->strategy == STRAT_ADAPTIVE)
	{
		if (dis < 2000)
			conf->strategy = STRAT_SIMPLE;
		else if (dis < 5000)
			conf->strategy = STRAT_MEDIUM;
		else
			conf->strategy = STRAT_COMPLEX;
	}
	if (conf->strategy == STRAT_SIMPLE)
		ft_simple_sort(a, b);
	else if (conf->strategy == STRAT_MEDIUM)
		ft_medium_sort(a, b);
	else if (conf->strategy == STRAT_COMPLEX)
		ft_complex_sort(a, b);
}

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
	stack_a = (t_stack){NULL, NULL, 0, 0, &stats};
	stack_b = (t_stack){NULL, NULL, 0, 0, &stats};
	config = (t_config){0, STRAT_ADAPTIVE};
	if (!ft_parse_args(argc, argv, &stack_a, &config))
		return (write(2, "Error\n", 6), 1);
	if (stack_a.size > 1)
	{
		ft_assign_index(&stack_a);
		disorder = ft_compute_disorder(&stack_a);
		ft_execute_strategy(&stack_a, &stack_b, &config, disorder);
		if (config.bench)
			ft_print_bench(disorder, config.strategy, &stats, 2);
	}
	ft_clear_stack(&stack_a);
	ft_clear_stack(&stack_b);
	return (0);
}
