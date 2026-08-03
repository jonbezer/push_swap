/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 20:13:26 by jonbezer          #+#    #+#             */
/*   Updated: 2026/08/03 14:37:41 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static int	ft_parse_flag(char *arg, t_config *config)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		config->strategy = STRAT_SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		config->strategy = STRAT_MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		config->strategy = STRAT_COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		config->strategy = STRAT_ADAPTIVE;
	else if (ft_strncmp(arg, "--bench", 8) == 0)
		config->bench = 1;
	else
		return (0);
	return (1);
}

static int	ft_add_num_node(t_stack *stack_a, char *str)
{
	long	num;
	t_node	*new_node;

	if (!ft_is_number(str))
		return (0);
	num = ft_atol(str);
	if (!ft_is_in_range(num))
		return (0);
	if (ft_has_duplicate(stack_a->head, (int)num))
		return (0);
	new_node = ft_create_node((int)num);
	if (!new_node)
		return (0);
	ft_add_back(stack_a, new_node);
	return (1);
}

static int	ft_parse_string(char *arg, t_stack *stack_a)
{
	int		i;
	char	**split;

	split = ft_split(arg, ' ');
	if (!split || !split[0])
	{
		ft_free_split(split);
		return (0);
	}
	i = 0;
	while (split[i])
	{
		if (!ft_add_num_node(stack_a, split[i]))
		{
			ft_free_split(split);
			return (0);
		}
		i++;
	}
	ft_free_split(split);
	return (1);
}

int	ft_parse_args(int argc, char **argv, t_stack *stack_a, t_config *config)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!ft_parse_flag(argv[i], config))
				return (0);
		}
		else
		{
			if (!ft_parse_string(argv[i], stack_a))
			{
				ft_clear_stack(stack_a);
				return (0);
			}
		}
		i++;
	}
	return (1);
}
