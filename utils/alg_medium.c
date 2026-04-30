/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_medium.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia4 <jgarcia4@student.42barcelona.co  +#+  +:+       +#+        */
/*                  a                              +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 00:00:00 by jgarcia4          #+#    #+#             */
/*   Updated: 2026/04/30 19:23:50 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int rc(int size)
{
	int	i;
	
	i = 0;
	while (i * i < size)
		i++;
	return (i);
}

void    index_sort(t_stack **a, int size)
{
	t_stack	*nodo;
	t_stack	*min;
	int		i;
	int		value;

	i = 1;
	while (i <= size)
	{
		nodo = *a;
		min = NULL;
		while (nodo)
		{
			if (nodo->index == 0 && (min == NULL || nodo->value < value))
			{
				value = nodo->value;
				min = nodo;
			}
			nodo = nodo->next;
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

void	chunk_sort(t_stack **a, t_stack **b, t_bench *ops)
{
	int		size;
	int		rango;
	int		i;
	int		chunk;
	t_stack	*nodo_a;

	size = lst_size(a);
	index_sort(a, size);
	rango = rc(size);
	chunk = rango;
	i = 1;
	while (i <= size)
	{
		nodo_a = find_in_chunk(*a, chunk - rango, chunk);
		if (!nodo_a)
			chunk += rango;
		else
		{
			pasos_a_b(a, b, nodo_a, ops);
			i++;
		}
	}
	send_back(a, b, size, ops);
}
