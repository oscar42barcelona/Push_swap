/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_adaptive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia4 <jgarcia4@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 00:00:00 by jgarcia4          #+#    #+#             */
/*   Updated: 2026/05/04 10:17:54 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_alg	adaptive_strategy(float disorder)
{
	if (disorder < 0.2f)
		return (ALG_SIMPLE);
	if (disorder < 0.5f)
		return (ALG_MEDIUM);
	return (ALG_COMPLEX);
}

void	adaptive_sort(t_stack **a, t_stack **b, t_bench *ops, float disorder)
{
	t_alg	algo;

	algo = adaptive_strategy(disorder);
	if (algo == ALG_SIMPLE)
		selection_sort(a, b, ops);
	else if (algo == ALG_MEDIUM)
		chunk_sort(a, b, ops);
	else
		radix_sort(a, b, ops);
}
