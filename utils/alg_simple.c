/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:13:18 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/29 15:03:51 by osuarez-         ###   ########.fr       */
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

static void	rotate_to_top(t_stack **a, int dst, int tam, t_bench *ops)
{
	if (dst > tam - dst)
	{
		dst = tam - dst;
		while (dst--)
			rra(a, ops);
	}
	else
	{
		while (dst--)
			ra(a, ops);
	}
}

void	pasos_a_b(t_stack **a, t_stack **b, t_stack *min, t_bench *ops)
{
	int	dst;
	int	tam;

	dst = dst_lst(a, min);
	if (dst == -1)
		return ;
	tam = lst_size(a);
	rotate_to_top(a, dst, tam, ops);
	pb(a, b, ops);
}

void	selection_sort(t_stack **a, t_stack **b, t_bench *ops)
{
	t_stack	*min;
	t_stack	*cur;

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
		pasos_a_b(a, b, min, ops);
	}
	while (pa(a, b, ops));
}
