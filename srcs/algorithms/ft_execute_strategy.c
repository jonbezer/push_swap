/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_strategy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 10:40:45 by jonbezer          #+#    #+#             */
/*   Updated: 2026/08/16 18:56:13 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_execute_strategy(t_stack *a, t_stack *b, t_config *config, int dis)
{
	//a->print_ops = !config->bench;
	//b->print_ops = !config->bench;
	if (ft_is_sorted(a))
		return ;
	if (config->strategy == STRAT_ADAPTIVE)
	{
		if (a->size <= 5)
			config->strategy = STRAT_SIMPLE;
		else if (dis < 2000)
			config->strategy = STRAT_SIMPLE;
		else if (dis < 5000)
			config->strategy = STRAT_MEDIUM;
		else
			config->strategy = STRAT_COMPLEX;
	}
	if (config->strategy == STRAT_SIMPLE)
		ft_simple_sort(a, b);
	else if (config->strategy == STRAT_MEDIUM)
		ft_medium_sort(a, b);
	else if (config->strategy == STRAT_COMPLEX)
		ft_complex_sort(a, b);
}
