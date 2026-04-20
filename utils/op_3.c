/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:42:29 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/20 16:58:30 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*penultimate;
	t_stack	*ultimate;

	if (!a || !*a || !(*a)->next)
		return;
	penultimate = *a;
	while (penultimate->next->next)
		penultimate = penultimate->next;
	ultimate = penultimate->next;
	ultimate->next = *a;
	*a = ultimate;
	penultimate->next = NULL;
}

void	rrb(t_stack **b)
{
    t_stack *penultimate;
    t_stack *ultimate;

    if (!b || !*b || !(*b)->next)
        return;
    penultimate = *b;
    while (penultimate->next->next)
        penultimate = penultimate->next;
    ultimate = penultimate->next;
    ultimate->next = *b;
    *b = ultimate;
    penultimate->next = NULL;
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
