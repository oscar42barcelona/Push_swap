/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_complex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia4 <jgarcia4@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 00:00:00 by jgarcia4          #+#    #+#             */
/*   Updated: 2026/05/04 14:55:37 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_pass(t_stack **a, t_stack **b, int bit, t_bench *ops)
{
	int	size;
	int	rep;

	size = lst_size(a);
	rep = size;
	while (rep)
	{
		if (((*a)->index >> bit) & 1)
			ra(a, ops);
		else
			pb(a, b, ops);
		rep--;
	}
	while (pa(a, b, ops));
}

void	radix_sort(t_stack **a, t_stack **b, t_bench *ops)
{
	int	bit;
	int	size;
	int	max_bits;

	size = lst_size(a);
	if (size <= 5)
	{
		sort_small(a, b, ops);
		return;
	}
	index_sort(a, size);
	max_bits = count_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		radix_pass(a, b, bit, ops);
		bit++;
	}
}
