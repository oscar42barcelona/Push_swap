/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia4 <jgarcia4@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:25:39 by osuarez-          #+#    #+#             */
/*   Updated: 2026/05/01 16:19:31 by osuarez-         ###   ########.fr       */
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
	int				index;
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
	int		bench;
	t_alg	strategy;
}	t_flags;

typedef struct s_bench
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;
}	t_bench;

// Análisis léxico y validación
int		is_valid_format(char *str);
int		ft_atol_safe(char *str, long *result);
void	process_tokens(char **tokens, t_stack **a);

// Estructura del stack
int		check_duplicate(t_stack *stack, int value);
int		add_to_stack(t_stack **stack, int value);
void	free_stack(t_stack **stack);
int		is_sorted(t_stack **a);

// Gestión de errores
void	free_matrix(char **matrix);
void	error_exit(t_stack **stack, char **matrix);

// Operaciones — swap y push
void	sa(t_stack **a, t_bench *ops);
void	sb(t_stack **b, t_bench *ops);
void	ss(t_stack **a, t_stack **b, t_bench *ops);
int		pa(t_stack **a, t_stack **b, t_bench *ops);
int		pb(t_stack **a, t_stack **b, t_bench *ops);

// Operaciones — rotate
void	ra(t_stack **a, t_bench *ops);
void	rb(t_stack **b, t_bench *ops);
void	rr(t_stack **a, t_stack **b, t_bench *ops);

// Operaciones — reverse rotate
void	rra(t_stack **a, t_bench *ops);
void	rrb(t_stack **b, t_bench *ops);
void	rrr(t_stack **a, t_stack **b, t_bench *ops);

// Índice de desorden
float	compute_disorder(t_stack **a);

// Algoritmos
//------------simple--------------------------------
int			lst_size(t_stack **a);
int			dst_lst(t_stack **a, t_stack *min_node);
void		selection_sort(t_stack **a, t_stack **b, t_bench *ops);
void		pasos_a_b(t_stack **a, t_stack **b, t_stack *min, t_bench *ops);
//------------medio--------------------------------
int			rc(int size);
void		index_sort(t_stack **a, int size);
void		send_back(t_stack **a, t_stack **b, int size, t_bench *ops);
void		chunk_sort(t_stack **a, t_stack **b, t_bench *ops);
t_stack		*find_in_chunk(t_stack *a, int min, int max);
//------------alto---------------------------------
void		send_back(t_stack **a, t_stack **b, int size, t_bench *ops);
void		radix_sort(t_stack **a, t_stack **b, t_bench *ops);
void		adaptive_sort(t_stack **a, t_stack **b, t_bench *ops, float disorder);

// Benchmark
void	print_bench(t_bench *ops, t_alg strategy, float disorder);
void	print_stack_stderr(t_stack *stack, char *name); // Temporal para debug
#endif
