/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:26:04 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/23 15:02:51 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
 
void	sa(t_stack **a)
{
	t_stack *first;
	t_stack *second;

	if (!a || !*a || !(*a)->next)
		return; //o gestionarlo como error...
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

	if (!b || !*b || !(*b)->next)
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

int	pa(t_stack **a, t_stack **b)
{
	t_stack	*first_b;

	if (!b || !*b)
		return (0);
	first_b = *b;
	*b = (*b)->next;
	first_b->next = *a;
	*a = first_b;
	return (1);
}


int	pb(t_stack **a, t_stack **b)
{
	t_stack	*first_a;

	if (!b || !*b)
		return (0); 
	first_a = *a;
	*a = (*a)->next;
	first_a->next = *b;
	*b = first_a;
	return (1);
}
