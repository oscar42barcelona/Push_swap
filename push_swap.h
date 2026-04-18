/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:25:39 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/18 13:33:14 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef enum e_algo
{
	ALG_ADAPTIVE,
	ALG_SIMPLE,
	ALG_MEDIUM,
	ALG_COMPLEX
}	t_alg;

typedef struct s_flags
{
	int		bench;// 0 = apagado, 1 = encendido
	t_alg	strategy;
}	t_flags;

// Analisis Léxico y Validación
int		is_valid_format(char *str);
int		ft_atol_safe(char *str, long *result);

// Analisis contextual y estructura
int		check_duplicate(t_stack *stack, int value);
int		add_to_stack(t_stack **stack, int value);
void	free_stack(t_stack **stack);

// Utils
void	free_matrix(char **matrix);
void	error_exit(t_stack **stack, char **matrix);

#endif
