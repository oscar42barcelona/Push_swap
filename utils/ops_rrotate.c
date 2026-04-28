/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:42:29 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/28 00:00:00 by jgarcia4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rrotate_one(t_stack **s)
{
	t_stack	*penultimate;
	t_stack	*last;

	if (!*s || !(*s)->next)
		return ;
	penultimate = *s;
	while (penultimate->next->next)
		penultimate = penultimate->next;
	last = penultimate->next;
	last->next = *s;
	*s = last;
	penultimate->next = NULL;
}

void	rra(t_stack **a, t_bench *ops)
{
	rrotate_one(a);
	ft_putstr_fd("rra\n", 1);
	if (ops)
	{
		ops->rra++;
		ops->total++;
	}
}

void	rrb(t_stack **b, t_bench *ops)
{
	rrotate_one(b);
	ft_putstr_fd("rrb\n", 1);
	if (ops)
	{
		ops->rrb++;
		ops->total++;
	}
}

void	rrr(t_stack **a, t_stack **b, t_bench *ops)
{
	rrotate_one(a);
	rrotate_one(b);
	ft_putstr_fd("rrr\n", 1);
	if (ops)
	{
		ops->rrr++;
		ops->total++;
	}
}
