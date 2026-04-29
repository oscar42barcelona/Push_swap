/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:51:07 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/29 18:16:02 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack **a)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*first;
	t_stack	*second;

	if (!*a || !(*a)->next)
		return (0.0f);
	mistakes = 0;
	total_pairs = 0;
	first = *a;
	while (first->next)
	{
		second = first->next;
		while (second)
		{
			total_pairs++;
			if (first->value > second->value)
				mistakes++;
			second = second->next;
		}
		first = first->next;
	}
	return ((float)mistakes / total_pairs);
}
