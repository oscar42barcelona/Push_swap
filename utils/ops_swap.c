/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:26:04 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/28 00:00:00 by jgarcia4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_one(t_stack **s)
{
	t_stack	*first;
	t_stack	*second;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	second = (*s)->next;
	first->next = second->next;
	second->next = first;
	*s = second;
}

void	sa(t_stack **a, t_bench *ops)
{
	swap_one(a);
	ft_putstr_fd("sa\n", 1);
	if (ops)
	{
		ops->sa++;
		ops->total++;
	}
}

void	sb(t_stack **b, t_bench *ops)
{
	swap_one(b);
	ft_putstr_fd("sb\n", 1);
	if (ops)
	{
		ops->sb++;
		ops->total++;
	}
}

void	ss(t_stack **a, t_stack **b, t_bench *ops)
{
	swap_one(a);
	swap_one(b);
	ft_putstr_fd("ss\n", 1);
	if (ops)
	{
		ops->ss++;
		ops->total++;
	}
}
