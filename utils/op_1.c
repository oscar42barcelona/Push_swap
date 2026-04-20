/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:26:04 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/20 16:52:38 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
void	sa(t_stack **a)
{
	t_stack *first;
	t_stack *second;

	if (!a)
		return;
	if (ft_lstsize(*a) < 2)
		return;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

void    sb(t_stack **b)
{
    t_stack *first;
    t_stack *second;

    if (!b)
        return;
    if (ft_lstsize(*b) < 2)
        return; //o gestionarlo como error...
    first = *b;
    second = (*b)->next;
    first->next = second->next;
    second->next = first;
    *b = second;
}

void	ss(t_stack **a, t_stack **b)
{
	sb(b);
	sa(a);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*first_b;

	if (!b || !*b)
		return; //o gestionarlo como error...
	first_b = *b;
	*b = (*b)->next;
	first_b->next = *a;
	*a = first_b;
}


void	pb(t_stack **a, t_stack **b)
{
	t_stack	*first_a;

	if (!a || !*a)
		return; //o gestionarlo como error...
	first_a = *a;
	*a = (*a)->next;
	first_a->next = *b;
	*b = first_a;
}
