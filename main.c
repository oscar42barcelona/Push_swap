/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:05:03 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/28 00:00:00 by jgarcia4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	parse_flags(char *str, t_flags *flags)
{
	if (ft_strncmp(str, "--bench", 8) == 0)
		flags->bench = 1;
	else if (ft_strncmp(str, "--simple", 9) == 0)
		flags->strategy = ALG_SIMPLE;
	else if (ft_strncmp(str, "--medium", 9) == 0)
		flags->strategy = ALG_MEDIUM;
	else if (ft_strncmp(str, "--complex", 10) == 0)
		flags->strategy = ALG_COMPLEX;
	else if (ft_strncmp(str, "--adaptive", 11) == 0)
		flags->strategy = ALG_ADAPTIVE;
	else
		return (0);
	return (1);
}

static void	parse_args(int argc, char **argv, t_stack **a, t_flags *flags)
{
	char	**tokens;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (parse_flags(argv[i], flags))
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

	ft_bzero(&ops, sizeof(t_bench));
	if (is_sorted(a))
		return ;
	disorder = compute_disorder(a);
	if (flags->bench) // Temporal testeo
		print_stack_stderr(*a, "INICIAL");
	if (flags->strategy == ALG_SIMPLE)
		selection_sort(a, b, &ops);
	else if (flags->strategy == ALG_MEDIUM)
		chunk_sort(a, b, &ops);
	else if (flags->strategy == ALG_COMPLEX)
		radix_sort(a, b, &ops);
	else
		adaptive_sort(a, b, &ops, disorder);
	if (flags->bench)
	{
		print_stack_stderr(*a, "FINAL"); // Temporal testeo
		print_bench(&ops, flags->strategy, disorder);
	}
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
	run_sort(&a, &b, &flags);
	free_stack(&a);
	return (0);
}
