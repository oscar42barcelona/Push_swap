/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_medium.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia4 <jgarcia4@student.42barcelona.co  +#+  +:+       +#+        */
/*                  a                              +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 00:00:00 by jgarcia4          #+#    #+#             */
/*   Updated: 2026/04/29 17:40:07 by osuarez-         ###   ########.fr       */
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


void	chunk_sort(t_stack **a, t_stack **b, t_bench *ops)
{
	int		size;
	int		rango;
	int		i;
	int		chunk;
	t_stack	*min_index;
	t_stack	*nodo_a;
	
	size = lst_size(a);
	index_sort(a,size);
	rango = rc(size);
	chunk = rango;
	i = 1;
	while (i <= size)
	{
		min_index = *a;
		nodo_a = *a;
		while (nodo_a)
		{
			if ((nodo_a->index > (chunk - rango)) && (nodo_a->index <= chunk))
			{
				min_index = nodo_a;
				pasos_a_b(a, b, min_index, ops);
				if (*b && (*b)->index < (*b)->next->index)
					sb(b, ops);
				i++;
			}
			nodo_a = nodo_a->next;
		}
		chunk = chunk + rango;
	}
}
