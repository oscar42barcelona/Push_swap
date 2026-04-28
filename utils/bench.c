/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia4 <jgarcia4@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 00:00:00 by jgarcia4          #+#    #+#             */
/*   Updated: 2026/04/28 00:00:00 by jgarcia4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*bench_strategy_name(t_alg strategy)
{
	if (strategy == ALG_SIMPLE)
		return ("Simple / O(n^2)");
	if (strategy == ALG_MEDIUM)
		return ("Medium / O(n*sqrt(n))");
	if (strategy == ALG_COMPLEX)
		return ("Complex / O(n*log(n))");
	return ("Adaptive");
}

static void	print_percent(float f, int fd)
{
	int	int_part;
	int	dec_part;

	int_part = (int)(f * 100);
	dec_part = (int)(f * 10000) % 100;
	ft_putnbr_fd(int_part, fd);
	ft_putchar_fd('.', fd);
	if (dec_part < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(dec_part, fd);
}

static void	print_bench_header(t_bench *ops, float disorder, t_alg strategy)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_percent(disorder, 2);
	ft_putstr_fd("%\n[bench] strategy: ", 2);
	ft_putstr_fd(bench_strategy_name(strategy), 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(ops->total, 2);
	ft_putchar_fd('\n', 2);
}

static void	print_bench_ops(t_bench *ops)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(ops->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(ops->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(ops->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(ops->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(ops->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(ops->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(ops->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(ops->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(ops->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(ops->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(ops->rrr, 2);
	ft_putchar_fd('\n', 2);
}

void	print_bench(t_bench *ops, t_alg strategy, float disorder)
{
	print_bench_header(ops, disorder, strategy);
	print_bench_ops(ops);
}

// Funcion temporal de testeo
void	print_stack_stderr(t_stack *stack, char *name)
{
	ft_putstr_fd("\n--- ESTADO ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(" ---\nStack: ", 2);
	while (stack)
	{
		ft_putchar_fd('[', 2);
		ft_putnbr_fd(stack->value, 2);
		ft_putstr_fd("] ", 2);
		stack = stack->next;
	}
	ft_putstr_fd("\n\n", 2);
}
