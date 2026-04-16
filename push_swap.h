/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:25:39 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/16 14:43:11 by osuarez-         ###   ########.fr       */
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
