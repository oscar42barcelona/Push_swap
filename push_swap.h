/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:25:39 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/20 16:54:24 by osuarez-         ###   ########.fr       */
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
//*******gestion de errores
void	free_matrix(char **matrix);
void	error_exit(t_stack **stack, char **matrix);
//*******operaciones listas
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);

#endif
