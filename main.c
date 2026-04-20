/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:05:03 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/20 18:43:39 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// Liberar un array
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

// Impresion de error
void	error_exit(t_stack **stack, char **matrix)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(stack);
	free_matrix(matrix);
	exit(1);
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

void	process_tokens(char **tokens, t_stack **a)
{
	int		j;
	long	number;

	j = 0;
	while (tokens[j])
	{
		if (!is_valid_format(tokens[j]) || !ft_atol_safe(tokens[j], &number))
			error_exit(a, tokens);
		if (check_duplicate(*a, (int)number) || !add_to_stack(a, (int)number))
			error_exit(a, tokens);
		j++;
	}
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_flags	flags;
	char	**tokens;
	int		i;

	a = NULL;
	if (argc < 2)
		return (0);
	flags.bench = 0;
	flags.strategy = ALG_ADAPTIVE;
	i = 1;
	while (i < argc)
	{
		if (parse_flags(argv[i], &flags))
		{
			i++;
			continue ;
		}
		tokens = ft_split(argv[i], ' ');
		if (!tokens || !tokens[0])
			error_exit(&a, tokens);
		process_tokens(tokens, &a);
		free_matrix(tokens);
		i++;
	}
	printf ("el indice es: %d", compute_disorder(&a));
	// TODO: Ejecutar algoritmos de ordenación
	//printf("[DEBUG] Bench: %d | Strategy: %d\n", flags.bench, flags.strategy); // BORRAR LUEGO
	free_stack(&a);
	return (0);
}
