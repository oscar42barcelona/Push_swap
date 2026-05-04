/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:13:18 by osuarez-          #+#    #+#             */
/*   Updated: 2026/05/04 17:13:36 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	lst_size(t_stack **a)
{
	int		i;
	t_stack	*cur;

	i = 0;
	cur = *a;
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}

int	dst_lst(t_stack **a, t_stack *min_node)
{
	int		i;
	t_stack	*cur;

	i = 0;
	cur = *a;
	while (cur)
	{
		if (cur == min_node)
			return (i);
		i++;
		cur = cur->next;
	}
	return (-1);
}

static void	rotate_to_top(t_stack **a, int dst, int size, t_bench *ops)
{
	if (dst > size - dst)
	{
		dst = size - dst;
		while (dst--)
			rra(a, ops);
	}
	else
	{
		while (dst--)
			ra(a, ops);
	}
}

void	push_min_to_b(t_stack **a, t_stack **b, t_stack *min, t_bench *ops)
{
	int	dst;
	int	size;

	dst = dst_lst(a, min);
	if (dst == -1)
		return ;
	size = lst_size(a);
	rotate_to_top(a, dst, size, ops);
	pb(a, b, ops);
}

void	selection_sort(t_stack **a, t_stack **b, t_bench *ops)
{
	t_stack	*min;
	t_stack	*cur;
	int		size;

	size = lst_size(a);
	if (size <= 5)
	{
		sort_small(a, b, ops);
		return ;
	}
	while (*a && (*a)->next)
	{
		min = *a;
		cur = (*a)->next;
		while (cur)
		{
			if (cur->value < min->value)
				min = cur;
			cur = cur->next;
		}
		push_min_to_b(a, b, min, ops);
	}
	while (pa(a, b, ops))
		;
}
