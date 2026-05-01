/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_complex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia4 <jgarcia4@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 00:00:00 by jgarcia4          #+#    #+#             */
/*   Updated: 2026/05/01 17:39:40 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	calcular_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b, t_bench *ops)
{
	int	vueltas;
	int	i;
	int	size;
	int	rep;

	size = lst_size(a);
	index_sort(a, size);
	vueltas = calcular_bits(size);
	i = 0;
	while (i < vueltas)
	{
		rep = size;
		while (rep)
		{
			if (((*a)->index >> i) & 1)
				ra(a, ops);
			else
				pb(a, b, ops);
			rep--;
		}
		while (pa(a, b, ops));
		i++;
	}
}
