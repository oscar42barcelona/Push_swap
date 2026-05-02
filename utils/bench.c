/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia4 <jgarcia4@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 00:00:00 by jgarcia4          #+#    #+#             */
/*   Updated: 2026/04/30 17:26:13 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*bench_strategy_name(t_alg mode, t_alg effective)
{
	if (mode == ALG_ADAPTIVE)
	{
		if (effective == ALG_SIMPLE)
			return ("Adaptive / O(n^2)");
		if (effective == ALG_MEDIUM)
			return ("Adaptive / O(n*sqrt(n))");
		return ("Adaptive / O(n*log(n))");
	}
	if (mode == ALG_SIMPLE)
		return ("Simple / O(n^2)");
	if (mode == ALG_MEDIUM)
		return ("Medium / O(n*sqrt(n))");
	return ("Complex / O(n*log(n))");
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

static void	print_bench_header(t_bench *ops, float dis, t_alg mode, t_alg eff)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_percent(dis, 2);
	ft_putstr_fd("%\n[bench] strategy: ", 2);
	ft_putstr_fd(bench_strategy_name(mode, eff), 2);
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

void	print_bench(t_bench *ops, t_alg mode, t_alg effective, float disorder)
{
	print_bench_header(ops, disorder, mode, effective);
	print_bench_ops(ops);
}
