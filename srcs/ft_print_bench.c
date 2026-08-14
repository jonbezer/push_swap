/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bench.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 18:19:19 by jonbezer          #+#    #+#             */
/*   Updated: 2026/08/14 19:05:43 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// static void	ft_print_strategy_name(t_strategy strat, int fd)
// {
// 	if (strat == STRAT_SIMPLE)
// 		ft_putstr_fd("Simple / O(n²)", fd);
// 	else if (strat == STRAT_MEDIUM)
// 		ft_putstr_fd("Medium / O(n√n)", fd);
// 	else if (strat == STRAT_COMPLEX)
// 		ft_putstr_fd("Complex / O(n log n)", fd);
// 	else
// 		ft_putstr_fd("Adaptive / O(n√n)", fd);
// }

static void	ft_print_strategy_name(t_config *conf, int fd)
{
	if (!conf->is_adaptive)
	{
		if (conf->strategy == STRAT_SIMPLE)
			ft_putstr_fd("Simple", fd);
		else if (conf->strategy == STRAT_MEDIUM)
			ft_putstr_fd("Medium", fd);
		else if (conf->strategy == STRAT_COMPLEX)
			ft_putstr_fd("Complex)", fd);
	}
	else
		ft_putstr_fd("Adaptive", fd);
	ft_print_strategy_used(&conf, fd);	
}

static void	ft_print_strategy_used(t_config *conf, int fd)
{
	if (!conf->is_adaptive)
	{
		if (conf->strategy == STRAT_SIMPLE)
			ft_putstr_fd(" / O(n²)", fd);
		else if (conf->strategy == STRAT_MEDIUM)
			ft_putstr_fd(" / O(n√n)", fd);
		else if (conf->strategy == STRAT_COMPLEX)
			ft_putstr_fd(" / O(n log n)", fd);
	}
}

static void	ft_print_stats_1(t_stats *stats, int fd)
{
	ft_putstr_fd("[bench] sa: ", fd);
	ft_putnbr_fd(stats->sa, fd);
	ft_putstr_fd(" sb: ", fd);
	ft_putnbr_fd(stats->sb, fd);
	ft_putstr_fd(" ss: ", fd);
	ft_putnbr_fd(stats->ss, fd);
	ft_putstr_fd(" pa: ", fd);
	ft_putnbr_fd(stats->pa, fd);
	ft_putstr_fd(" pb: ", fd);
	ft_putnbr_fd(stats->pb, fd);
	ft_putchar_fd('\n', fd);
}

static void	ft_print_stats_2(t_stats *stats, int fd)
{
	ft_putstr_fd("[bench] ra: ", fd);
	ft_putnbr_fd(stats->ra, fd);
	ft_putstr_fd(" rb: ", fd);
	ft_putnbr_fd(stats->rb, fd);
	ft_putstr_fd(" rr: ", fd);
	ft_putnbr_fd(stats->rr, fd);
	ft_putstr_fd(" rra: ", fd);
	ft_putnbr_fd(stats->rra, fd);
	ft_putstr_fd(" rrb: ", fd);
	ft_putnbr_fd(stats->rrb, fd);
	ft_putstr_fd(" rrr: ", fd);
	ft_putnbr_fd(stats->rrr, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_print_bench(int dis, t_strategy strat, t_stats *stats, int fd)
{
	ft_print_disorder(dis, fd);
	ft_putstr_fd("[bench] strategy: ", fd);
	ft_print_strategy_name(strat, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("[bench] total_ops: ", fd);
	ft_putnbr_fd(stats->total, fd);
	ft_putchar_fd('\n', fd);
	ft_print_stats_1(stats, fd);
	ft_print_stats_2(stats, fd);
}
