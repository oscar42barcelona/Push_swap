/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:05:03 by osuarez-          #+#    #+#             */
/*   Updated: 2026/05/01 16:18:56 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_strategy(t_flags *flags, t_alg strat)
{
	if (flags->strategy != ALG_ADAPTIVE)
		return (-1);
	flags->strategy = strat;
	return (1);
}

int	parse_flags(char *str, t_flags *flags)
{
	if (ft_strncmp(str, "--bench", 8) == 0)
	{
		if (flags->bench)
			return (-1);
		flags->bench = 1;
		return (1);
	}
	if (ft_strncmp(str, "--simple", 9) == 0)
		return (set_strategy(flags, ALG_SIMPLE));
	if (ft_strncmp(str, "--medium", 9) == 0)
		return (set_strategy(flags, ALG_MEDIUM));
	if (ft_strncmp(str, "--complex", 10) == 0)
		return (set_strategy(flags, ALG_COMPLEX));
	if (ft_strncmp(str, "--adaptive", 11) == 0)
		return (1);
	return (0);
}

static void	parse_args(int argc, char **argv, t_stack **a, t_flags *flags)
{
	char	**tokens;
	int		i;
	int		ret;

	i = 1;
	while (i < argc)
	{
		ret = parse_flags(argv[i], flags);
		if (ret == -1)
			error_exit(a, NULL);
		if (ret == 1)
		{
			i++;
			continue ;
		}
		tokens = ft_split(argv[i], ' ');
		if (!tokens || !tokens[0])
			error_exit(a, tokens);
		process_tokens(tokens, a);
		free_matrix(tokens);
		i++;
	}
}

static void	run_sort(t_stack **a, t_stack **b, t_flags *flags)
{
	t_bench	ops;
	float	disorder;
	t_alg	effective;

	ft_bzero(&ops, sizeof(t_bench));
	if (is_sorted(a))
		return ;
	disorder = compute_disorder(a);
	if (flags->strategy == ALG_SIMPLE)
		selection_sort(a, b, &ops);
	else if (flags->strategy == ALG_MEDIUM)
		chunk_sort(a, b, &ops);
	else if (flags->strategy == ALG_COMPLEX)
		radix_sort(a, b, &ops);
	else
		adaptive_sort(a, b, &ops, disorder);
	effective = flags->strategy;
	if (effective == ALG_ADAPTIVE)
		effective = adaptive_strategy(disorder);
	if (flags->bench)
		print_bench(&ops, flags->strategy, effective, disorder);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_flags	flags;

	a = NULL;
	b = NULL;
	flags.bench = 0;
	flags.strategy = ALG_ADAPTIVE;
	if (argc < 2)
		return (0);
	parse_args(argc, argv, &a, &flags);
	if (!a)
		error_exit(&a, NULL);
	run_sort(&a, &b, &flags);
	free_stack(&a);
	return (0);
}
