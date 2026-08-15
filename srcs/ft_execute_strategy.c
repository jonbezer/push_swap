/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_strategy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 10:40:45 by jonbezer          #+#    #+#             */
/*   Updated: 2026/08/15 10:41:00 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_execute_strategy(t_stack *a, t_stack *b, t_config *conf, int dis)
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