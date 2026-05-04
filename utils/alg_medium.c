/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_medium.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia4 <jgarcia4@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 00:00:00 by jgarcia4          #+#    #+#             */
/*   Updated: 2026/05/04 17:13:01 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	index_sort(t_stack **a, int size)
{
	t_stack	*node;
	t_stack	*min;
	int		i;
	int		value;

	i = 1;
	while (i <= size)
	{
		node = *a;
		min = NULL;
		value = INT_MAX;
		while (node)
		{
			if (node->index == 0 && node->value < value)
			{
				value = node->value;
				min = node;
			}
			node = node->next;
		}
		if (min)
			min->index = i;
		i++;
	}
}

void	send_back(t_stack **a, t_stack **b, int size, t_bench *ops)
{
	int		pos;
	int		len;
	t_stack	*nodo;

	while (size)
	{
		pos = 0;
		nodo = *b;
		while (nodo && nodo->index != size && ++pos)
			nodo = nodo->next;
		if (!nodo)
			return ;
		len = lst_size(b);
		if (pos <= len / 2)
			while ((*b)->index != size)
				rb(b, ops);
		else
			while ((*b)->index != size)
				rrb(b, ops);
		pa(a, b, ops);
		size--;
	}
}

t_stack	*find_in_chunk(t_stack *a, int min, int max)
{
	while (a)
	{
		if (a->index > min && a->index <= max)
			return (a);
		a = a->next;
	}
	return (NULL);
}

static void	push_chunks_to_b(t_stack **a, t_stack **b, int size, t_bench *ops)
{
	int		i;
	int		chunk;
	int		chunk_size;
	t_stack	*node;

	chunk_size = isqrt(size);
	chunk = chunk_size;
	i = 0;
	while (i < size)
	{
		node = find_in_chunk(*a, chunk - chunk_size, chunk);
		if (!node)
			chunk += chunk_size;
		else
		{
			push_min_to_b(a, b, node, ops);
			i++;
		}
	}
}

void	chunk_sort(t_stack **a, t_stack **b, t_bench *ops)
{
	int	size;

	size = lst_size(a);
	if (size <= 5)
	{
		sort_small(a, b, ops);
		return ;
	}
	index_sort(a, size);
	push_chunks_to_b(a, b, size, ops);
	send_back(a, b, size, ops);
}
