/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:12:48 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/29 15:12:46 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_one(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	last = *s;
	while (last->next)
		last = last->next;
	*s = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack **a, t_bench *ops)
{
	rotate_one(a);
	ft_putstr_fd("ra\n", 1);
	if (ops)
	{
		ops->ra++;
		ops->total++;
	}
}

void	rb(t_stack **b, t_bench *ops)
{
	rotate_one(b);
	ft_putstr_fd("rb\n", 1);
	if (ops)
	{
		ops->rb++;
		ops->total++;
	}
}

void	rr(t_stack **a, t_stack **b, t_bench *ops)
{
	rotate_one(a);
	rotate_one(b);
	ft_putstr_fd("rr\n", 1);
	if (ops)
	{
		ops->rr++;
		ops->total++;
	}
}
