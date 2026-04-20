/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:12:48 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/20 16:58:18 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return; //o gestionarlo como error...
	first = *a;
	last = *a;
	second = (*a)->next;
	while (last->next)
	{
		last = last->next;
	}
	last->next = first;
	first->next = NULL;
	*a = second;
}

void    rb(t_stack **b)
{
    t_stack *first;
    t_stack *second;
    t_stack *last;

    if (!b || !*b || !(*b)->next)
        return; //o gestionarlo como error...
    first = *b;
    last = *b;
    second = (*b)->next;
    while (last->next)
    {
        last = last->next;
    }
    last->next = first;
    first->next = NULL;
    *b = second;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

