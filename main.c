/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:05:03 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/16 13:56:10 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	t_stack	*a;
	char	**tokens;
	long	number;
	int		i;
	int		j;

	a = NULL;
	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens || !tokens[0])
			error_exit(&a, tokens);
		j = 0;
		while (tokens[j])
		{
			if (!is_valid_format(tokens[j]) || !ft_atol_safe(tokens[j], &number))
				error_exit(&a, tokens);
			if (check_duplicate(a, (int)number) || !add_to_stack(&a, (int)number))
				error_exit(&a, tokens);
			j++;
		}
		free_matrix(tokens);
		i++;
	}
	// PENDIENTE: Ejecutar algoritmos de ordenación
	free_stack(&a);
	return (0);
}
