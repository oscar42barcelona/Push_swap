/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_medium.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia4 <jgarcia4@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 00:00:00 by jgarcia4          #+#    #+#             */
/*   Updated: 2026/04/29 09:02:39 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* TODO CP2: implementar chunk sort O(n*sqrt(n)) */
void	chunk_sort(t_stack **a, t_stack **b, t_bench *ops)
{
	selection_sort(a, b, ops);
}

static int size(stack **a)
{
	int		size;
	t_stack	**node;

	node = *a;
	size = 0;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

static int rc(int size)
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


void  *chunks(t_stack **a, t_stack **b)
{
	int		size;
	int		rango;
	int		i;
	t_stack	*min_index;
	t_stack	*nodo;
	
	size = size(a);
	index_sort(a,size);
	rango = rc(size(a));
	i = 1;
	while (i <= size)
	{
		min_index = *a;
		nodo = *a;
		while (nodo)
		{
			if ((nodo->index > (chunk - chunk)) && (nodo->index <= chunk))
				pasos_a_b(a, b, min_index);
			nodo = nodo->next;
		}
		if ( )
		{
			
		}
		chunk = chunk + chunk;
	}
	
}
*/
